/**
 * @file TriggerActivityMakerTriton.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/Triton/TriggerActivityMakerTriton.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TriggerActivityMakerTriton"
//#include "grpc_client.h"
//#include "triggeralgs/Triton/json_utils.h"
//#include "rapidjson/document.h"

namespace tc = triton::client;

namespace triggeralgs {

using Logging::TLVL_GENERAL;
using Logging::TLVL_DEBUG_INFO;
using Logging::TLVL_DEBUG_HIGH;
using Logging::TLVL_DEBUG_ALL;

static std::unique_ptr<triton::client::InferenceServerGrpcClient> client;

void
TriggerActivityMakerTriton::process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_tas)
{
  // Expect that TPs are inherently time ordered.
  m_current_ta.inputs.push_back(input_tp);

  // Add useful info about recived TPs here for FW and SW TPG guys.
  if (m_print_tp_info) {
    TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:Triton] TP Start Time: " << input_tp.time_start << ", TP ADC Sum: " <<  input_tp.adc_integral
	    << ", TP TOT: " << input_tp.time_over_threshold << ", TP ADC Peak: " << input_tp.adc_peak
     	<< ", TP Offline Channel ID: " << input_tp.channel;
  }

  if (m_current_ta.inputs.size() < m_number_tps_per_request) {
    m_current_ta.inputs.push_back(input_tp);
    return;
  }

  check_model_inputs(m_model_name, m_model_version);
  /*
  std::vector<std::vector<std::vector<int>>> adc_values = get_adcs_from_trigger_primitives(
    m_number_tps_per_request, 
    m_number_time_ticks, 
    m_number_wires
  );
  */

  // Reset the current.
  m_current_ta = TriggerActivity();
  return;
}

void TriggerActivityMakerTriton::check_triton_server_liveness(const std::string& inference_url) const {
  bool live;
  if (!client->IsServerLive(&live).IsOk()) {
    throw triggeralgs::ServerNotLive(ERS_HERE);
  }

  // Server metadata
  inference::ServerMetadataResponse server_metadata;
  if (!client->ServerMetadata(&server_metadata).IsOk()) {
    throw triggeralgs::CantGetServerMetadata(ERS_HERE);
  }
  if (server_metadata.name().compare("triton") != 0) {
    throw triggeralgs::UnexpectedServerMetadata(ERS_HERE, server_metadata.name());
  }

  TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TAM:Triton] Server metadata debug string: " << server_metadata.DebugString();

  return;
}

void TriggerActivityMakerTriton::check_model_readiness(const std::string model_name, const std::string model_version) const {
  bool model_ready;
  fail_if_error(client->IsModelReady(&model_ready, model_name, model_version), "Unable to get model readiness");
  /*
  if (!client->IsModelReady(&model_ready, model_name, model_version).IsOk()) {
    //throw triggeralgs::ModelIsNotReady(ERS_HERE, model_name);
    //throw triggeralgs::ModelNotReady(ERS_HERE, model_name);
  }
  */
  TLOG(TLVL_DEBUG_INFO) << "Model " << model_name << " is ready.";

  return;
}

void TriggerActivityMakerTriton::check_model_inputs(const std::string model_name, const std::string model_version) const {

  /*
  if (model_name != "simple") {
    TLOG_DEBUG(TLVL_IMPORTANT) << "WARNING: Model name is not 'simple'; skipping inference reuqest";
    return;
  }
  */
  
  // Placeholder using the "simple" model
  std::vector<int32_t> input0_data(16);
  std::vector<int32_t> input1_data(16);
  for (size_t i = 0; i < 16; ++i) {
    input0_data[i] = i;
    input1_data[i] = 1;
  }

  std::vector<int64_t> shape{1, 16};

  // Initialize the inputs with the data.
  tc::InferInput* input0;
  tc::InferInput* input1;

  fail_if_error(tc::InferInput::Create(&input0, "INPUT0", shape, "INT32"), "Unable to get INPUT0");
  std::shared_ptr<tc::InferInput> input0_ptr;
  input0_ptr.reset(input0);

  fail_if_error(tc::InferInput::Create(&input1, "INPUT1", shape, "INT32"), "Unable to get INPUT1");
  std::shared_ptr<tc::InferInput> input1_ptr;
  input1_ptr.reset(input1);

  fail_if_error(
    input0_ptr->AppendRaw(
          reinterpret_cast<uint8_t*>(&input0_data[0]),
          input0_data.size() * sizeof(int32_t)),
    "Unable to set data for INPUT0");
  fail_if_error(
    input1_ptr->AppendRaw(
          reinterpret_cast<uint8_t*>(&input1_data[0]),
          input1_data.size() * sizeof(int32_t)),
    "Unable to set data for INPUT1");

  // Generate the outputs to be requested.
  tc::InferRequestedOutput* output0;
  tc::InferRequestedOutput* output1;

  fail_if_error(
    tc::InferRequestedOutput::Create(&output0, "OUTPUT0"), 
    "Unable to get OUTPUT0");
  std::shared_ptr<tc::InferRequestedOutput> output0_ptr;
  output0_ptr.reset(output0);

  fail_if_error(
    tc::InferRequestedOutput::Create(&output1, "OUTPUT1"), 
    "Unable to get OUTPUT1");
  std::shared_ptr<tc::InferRequestedOutput> output1_ptr;
  output1_ptr.reset(output1);

  // The inference settings. Will be using default for now.
  tc::InferOptions options(model_name);
  options.model_version_ = model_version;
  options.client_timeout_ = 0;
  
  std::vector<tc::InferInput*> inputs = {input0_ptr.get(), input1_ptr.get()};
  std::vector<const tc::InferRequestedOutput*> outputs = {
      output0_ptr.get(), output1_ptr.get()
  };

  tc::InferResult* results;
  /*
  fail_if_error(
    client->Infer(&results, options, inputs, outputs), 
    "Unable to run model");
  */
  std::shared_ptr<tc::InferResult> results_ptr;
  results_ptr.reset(results);

  std::mutex mtx;
  std::condition_variable cv;
  bool callback_invoked = false;
  std::shared_ptr<tc::InferResult> result_placeholder;
  fail_if_error(
    client->AsyncInfer(
      [&](tc::InferResult* result) {
        {
          std::shared_ptr<tc::InferResult> result_ptr;
          result_ptr.reset(result);
          // Defer the response retrieval to main thread
          std::lock_guard<std::mutex> lk(mtx);
          callback_invoked = true;
          result_placeholder = std::move(result_ptr);
        }
        cv.notify_all();
      },
      options, inputs, outputs),
    "unable to run model"
  );

  // Ensure callback is completed
  {
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk, [&]() { return callback_invoked; });
  }

  // Get deferred response
  std::cout << "Getting results from deferred response" << std::endl;
  if (result_placeholder->RequestStatus().IsOk()) {
    ValidateSimpleResult(result_placeholder, input0_data, input1_data);
  } else {
    std::cerr << "error: Inference failed: "
              << result_placeholder->RequestStatus() << std::endl;
    exit(1);
  }
  // Get pointers to the result returned...
  /*
  int32_t* output0_data;
  size_t output0_byte_size;
  fail_if_error(
    results_ptr->RawData("OUTPUT0", (const uint8_t**)&output0_data, &output0_byte_size),
    "Unable to get result data for OUTPUT0");
  if (output0_byte_size != 64) {
    std::cerr << "error: received incorrect byte size for 'OUTPUT0': "
              << output0_byte_size << std::endl;
    exit(1);
  }

  int32_t* output1_data;
  size_t output1_byte_size;
  fail_if_error(
    results_ptr->RawData("OUTPUT1", (const uint8_t**)&output1_data, &output1_byte_size),
    "Unable to get result data for output1");
  if (output1_byte_size != 64) {
    std::cerr << "error: received incorrect byte size for 'OUTPUT1': "
              << output1_byte_size << std::endl;
    exit(1);
  }

  for (size_t i = 0; i < 16; ++i) {
    std::cout << input0_data[i] << " + " << input1_data[i] << " = "
              << *(output0_data + i) << std::endl;
    std::cout << input0_data[i] << " - " << input1_data[i] << " = "
              << *(output1_data + i) << std::endl;

    if ((input0_data[i] + input1_data[i]) != *(output0_data + i)) {
      std::cerr << "Error: incorrect sum" << std::endl;
      exit(1);
    }
    if ((input0_data[i] - input1_data[i]) != *(output1_data + i)) {
      std::cerr << "Error: incorrect difference" << std::endl;
      exit(1);
    }
  }
  */

  // Get full response
  //TLOG() << results_ptr->DebugString();

  tc::InferStat infer_stat;
  client->ClientInferStat(&infer_stat);
  TLOG() << "======Client Statistics======";
  TLOG() << "completed_request_count "
            << infer_stat.completed_request_count;
  TLOG() << "cumulative_total_request_time_ns "
            << infer_stat.cumulative_total_request_time_ns;
  TLOG() << "cumulative_send_time_ns "
            << infer_stat.cumulative_send_time_ns;
  TLOG() << "cumulative_receive_time_ns "
            << infer_stat.cumulative_receive_time_ns;

  inference::ModelStatisticsResponse model_stat;
  client->ModelInferenceStatistics(&model_stat, model_name);
  TLOG() << "======Model Statistics======";
  TLOG() << model_stat.DebugString();


  TLOG() << "PASS : Infer";

  return;
}

std::vector<std::vector<std::vector<int>>>
TriggerActivityMakerTriton::get_adcs_from_trigger_primitives(
  const uint64_t number_tps,
  const uint64_t number_time_ticks,
  const uint64_t number_wires) {

  std::vector<std::vector<std::vector<int>>> adc_values(
    number_tps,
    std::vector<std::vector<int>>(
      number_time_ticks, 
      std::vector<int>(number_wires, 0)
    )
  );
  return adc_values;
}

void 
TriggerActivityMakerTriton::configure(const nlohmann::json& config)
{
  if (config.is_object() && config.contains("number_tps_per_request")) {
    m_number_tps_per_request = config["number_tps_per_request"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Configured TPs per request: " << m_number_tps_per_request;
  }
  if (config.is_object() && config.contains("batch_size")) {
    m_batch_size = config["batch_size"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Configured batch size: " << m_batch_size;
  }
  if (config.is_object() && config.contains("number_time_ticks")) {
    m_number_time_ticks = config["number_time_ticks"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Configured time ticks per TP: " << m_number_time_ticks;
  }
  if (config.is_object() && config.contains("number_wires")) {
    m_number_wires = config["number_wires"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Configured number of wires per TP: " << m_number_wires;
  }
  if (config.is_object() && config.contains("inference_url")) {
    m_inference_url = config["inference_url"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Inference URL is " << m_inference_url;
  }
  if (config.is_object() && config.contains("model_name")) {
    m_model_name = config["model_name"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Model name is " << m_model_name;
  }
  if (config.is_object() && config.contains("model_version")) {
    m_model_version = config["model_version"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Model version is " << m_model_version;
  }
  if (config.is_object() && config.contains("client_timeout_microseconds")) {
    m_client_timeout_microseconds = config["client_timeout_microseconds"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] client_timeout_microseconds is " << m_client_timeout_microseconds;
  }
  if (config.is_object() && config.contains("server_timeout_microseconds")) {
    m_server_timeout_microseconds = config["server_timeout_microseconds"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] server_timeout_microseconds is " << m_server_timeout_microseconds;
  }
  if (config.is_object() && config.contains("print_tp_info")) {
    m_print_tp_info = config["print_tp_info"];
    TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Printing of TP info enabled";
  }

  TLOG_DEBUG(TLVL_DEBUG_INFO) << "[TA:Triton] Using configuration:\n" << config.dump(4);

  fail_if_error(tc::InferenceServerGrpcClient::Create(&client, m_inference_url), "Could not create Triton client");

  check_triton_server_liveness(m_inference_url);
  check_model_readiness(m_model_name, m_model_version);
}

void TriggerActivityMakerTriton::fail_if_error(const tc::Error& err, const std::string& msg) const 
{
  if (!err.IsOk()) {
    TLOG() << "[TA:Triton] ERROR: " << msg << ": " << err << std::endl;
  exit(1);
  }
}

void
TriggerActivityMakerTriton::ValidateSimpleShapeAndDatatype(
    const std::string& name, std::shared_ptr<tc::InferResult> result) const
{
  std::vector<int64_t> shape;
  fail_if_error(
      result->Shape(name, &shape), "unable to get shape for '" + name + "'");
  // Validate shape
  if ((shape.size() != 2) || (shape[0] != 1) || (shape[1] != 16)) {
    std::cerr << "error: received incorrect shapes for '" << name << "'"
              << std::endl;
    exit(1);
  }
  std::string datatype;
  fail_if_error(
      result->Datatype(name, &datatype),
      "unable to get datatype for '" + name + "'");
  // Validate datatype
  if (datatype.compare("INT32") != 0) {
    std::cerr << "error: received incorrect datatype for '" << name
              << "': " << datatype << std::endl;
    exit(1);
  }
}

void TriggerActivityMakerTriton::ValidateSimpleResult(
    const std::shared_ptr<tc::InferResult> result,
    std::vector<int32_t>& input0_data, std::vector<int32_t>& input1_data) const
{
  // Validate the results...
  ValidateSimpleShapeAndDatatype("OUTPUT0", result);
  ValidateSimpleShapeAndDatatype("OUTPUT1", result);

  // Get pointers to the result returned...
  int32_t* output0_data;
  size_t output0_byte_size;
  fail_if_error(
      result->RawData(
          "OUTPUT0", (const uint8_t**)&output0_data, &output0_byte_size),
      "unable to get result data for 'OUTPUT0'");
  if (output0_byte_size != 64) {
    std::cerr << "error: received incorrect byte size for 'OUTPUT0': "
              << output0_byte_size << std::endl;
    exit(1);
  }

  int32_t* output1_data;
  size_t output1_byte_size;
  fail_if_error(
      result->RawData(
          "OUTPUT1", (const uint8_t**)&output1_data, &output1_byte_size),
      "unable to get result data for 'OUTPUT1'");
  if (output0_byte_size != 64) {
    std::cerr << "error: received incorrect byte size for 'OUTPUT1': "
              << output0_byte_size << std::endl;
    exit(1);
  }

  for (size_t i = 0; i < 16; ++i) {
    std::cout << input0_data[i] << " + " << input1_data[i] << " = "
              << *(output0_data + i) << std::endl;
    std::cout << input0_data[i] << " - " << input1_data[i] << " = "
              << *(output1_data + i) << std::endl;

    if ((input0_data[i] + input1_data[i]) != *(output0_data + i)) {
      std::cerr << "error: incorrect sum" << std::endl;
      exit(1);
    }
    if ((input0_data[i] - input1_data[i]) != *(output1_data + i)) {
      std::cerr << "error: incorrect difference" << std::endl;
      exit(1);
    }
  }

  // Get full response
  std::cout << result->DebugString() << std::endl;
}

REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TriggerActivityMakerTriton)
} // namespace triggeralgs

