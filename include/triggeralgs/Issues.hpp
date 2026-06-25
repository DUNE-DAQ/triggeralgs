/**
* @file Issues.hpp
*
* This is part of the DUNE DAQ Application Framework, copyright 2020.
* Licensing/copyright details are in the COPYING file that you should have
* received with this code.
*/

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_ISSUES_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_ISSUES_HPP_

#include "ers/Issue.hpp"
#include "logging/Logging.hpp" // NOTE: if ISSUES ARE DECLARED BEFORE include logging/Logging.hpp, TLOG_DEBUG<<issue wont work.

#include <string>

ERS_DECLARE_ISSUE(triggeralgs,
                  FactoryOverwrite, 
                  "Attempted to overwrite a creator in factory with " << alg_name,
                  ((std::string)alg_name))

ERS_DECLARE_ISSUE(triggeralgs,
                  FactoryInvalidState,
                  "Makers map contains invalid/null pointers " << alg_name,
                  ((std::string)alg_name))

ERS_DECLARE_ISSUE(triggeralgs,
                  FactoryNotFound,
                  "Factory couldn't find: " << alg_name,
                  ((std::string)alg_name))

ERS_DECLARE_ISSUE(triggeralgs,
                  BadConfiguration,
                  "Bad configuration in " << alg_name,
                  ((std::string)alg_name))

ERS_DECLARE_ISSUE(triggeralgs,
                  InvalidConfiguration,
                  "Invalid configuration error: " << conferror,
                  ((std::string)conferror))


#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_ISSUES_HPP_
