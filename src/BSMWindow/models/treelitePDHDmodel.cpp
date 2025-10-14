#include "triggeralgs/BSMWindow/treelitemodel.hpp"

namespace triggeralgs {

int32_t TreelitePDHDModel::get_num_feature(void) const {
  return 26;
}

void TreelitePDHDModel::predict(union Entry* data, int pred_margin, float* result) const {
  unsigned int tmp;
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)4175910)) {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)154028)) {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)468)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)126248)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)221528)) {
            result[0] += -0.5993537;
          } else {
            result[0] += -0.20935605;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)71364)) {
            result[0] += -0.5348931;
          } else {
            result[0] += 0.21355711;
          }
        }
      } else {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)162214)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)54522)) {
            result[0] += -0.14669305;
          } else {
            result[0] += -0.51039916;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)195871)) {
            result[0] += 0.06356325;
          } else {
            result[0] += 0.54948467;
          }
        }
      }
    } else {
      if ( (data[22].missing != -1) && (data[22].fvalue < (float)507262)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)196075)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)72988)) {
            result[0] += 0.12209804;
          } else {
            result[0] += -0.3918763;
          }
        } else {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)73448)) {
            result[0] += 0.5759773;
          } else {
            result[0] += 0.210211;
          }
        }
      } else {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)295314)) {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)152404)) {
            result[0] += 0.7131594;
          } else {
            result[0] += -0.41381574;
          }
        } else {
          result[0] += -0.6857143;
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)5130512)) {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)124968)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)281510)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)244259)) {
            result[0] += 0.603885;
          } else {
            result[0] += -0.44761887;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)508265)) {
            result[0] += -0.7549296;
          } else {
            result[0] += 0.2919877;
          }
        }
      } else {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)8439)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)143902)) {
            result[0] += 0.37150517;
          } else {
            result[0] += -0.34660813;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)194664)) {
            result[0] += -0.05559308;
          } else {
            result[0] += -0.7764706;
          }
        }
      }
    } else {
      if ( (data[17].missing != -1) && (data[17].fvalue < (float)669)) {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)2506)) {
          result[0] += -0.7058824;
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)194477)) {
            result[0] += 0.58066726;
          } else {
            result[0] += -0.5714286;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)6778337)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)151135)) {
            result[0] += 0.714555;
          } else {
            result[0] += 0.2581573;
          }
        } else {
          result[0] += 0.79269546;
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)3673340)) {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)167184)) {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)160368)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)155481)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)150753)) {
            result[0] += -0.38232568;
          } else {
            result[0] += 0.09735132;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)30733)) {
            result[0] += 0.1872454;
          } else {
            result[0] += -0.28472143;
          }
        }
      } else {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)184566)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)62774)) {
            result[0] += 0.19270997;
          } else {
            result[0] += -0.27003533;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)105505)) {
            result[0] += 0.4618292;
          } else {
            result[0] += -0.1930355;
          }
        }
      }
    } else {
      if ( (data[4].missing != -1) && (data[4].fvalue < (float)56921)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)61)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)75803)) {
            result[0] += -0.43464968;
          } else {
            result[0] += 0.10398781;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)311061)) {
            result[0] += 0.20513761;
          } else {
            result[0] += 0.47644812;
          }
        }
      } else {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)78504)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)61822)) {
            result[0] += 0.14873597;
          } else {
            result[0] += -0.54502773;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)644623)) {
            result[0] += -0.7222331;
          } else {
            result[0] += 0.22736652;
          }
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)5391137)) {
      if ( (data[1].missing != -1) && (data[1].fvalue < (float)105455)) {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)130168)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)412528)) {
            result[0] += 0.48666626;
          } else {
            result[0] += -0.41114154;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)292296)) {
            result[0] += -0.39376038;
          } else {
            result[0] += 0.17101002;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)636717)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)49994)) {
            result[0] += -0.019022718;
          } else {
            result[0] += -0.52349;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)3642)) {
            result[0] += -0.6417107;
          } else {
            result[0] += 0.48742437;
          }
        }
      }
    } else {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)6182253)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)183558)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)104332)) {
            result[0] += 0.5442776;
          } else {
            result[0] += 0.12909874;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)676328)) {
            result[0] += -0.36722195;
          } else {
            result[0] += 0.54989386;
          }
        }
      } else {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)61)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)390893)) {
            result[0] += 0.4759159;
          } else {
            result[0] += -0.64693683;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)61)) {
            result[0] += 0.4069798;
          } else {
            result[0] += 0.57381374;
          }
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)3986725)) {
    if ( (data[20].missing != -1) && (data[20].fvalue < (float)263)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)688553)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)523953)) {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)174564)) {
            result[0] += -0.5534199;
          } else {
            result[0] += 0.17819749;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)181775)) {
            result[0] += -0.3998633;
          } else {
            result[0] += 0.09846395;
          }
        }
      } else {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)44183)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)1084)) {
            result[0] += -0.20518084;
          } else {
            result[0] += 0.0597512;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)477200)) {
            result[0] += -0.41567943;
          } else {
            result[0] += 0.35401297;
          }
        }
      }
    } else {
      if ( (data[9].missing != -1) && (data[9].fvalue < (float)55198)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)523953)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)427636)) {
            result[0] += -0.6462996;
          } else {
            result[0] += -0.32283092;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)65054)) {
            result[0] += 0.20706749;
          } else {
            result[0] += -0.107324556;
          }
        }
      } else {
        if ( (data[8].missing != -1) && (data[8].fvalue < (float)322670)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)364647)) {
            result[0] += -0.35029295;
          } else {
            result[0] += 0.3747227;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)380)) {
            result[0] += -0.48570004;
          } else {
            result[0] += 0.37192985;
          }
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)6182253)) {
      if ( (data[4].missing != -1) && (data[4].fvalue < (float)29956)) {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)523)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)64194)) {
            result[0] += 0.2710328;
          } else {
            result[0] += -0.52224964;
          }
        } else {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)293890)) {
            result[0] += 0.44127297;
          } else {
            result[0] += -0.1927317;
          }
        }
      } else {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)98901)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)157154)) {
            result[0] += 0.24404266;
          } else {
            result[0] += -0.15488802;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)584718)) {
            result[0] += -0.46416375;
          } else {
            result[0] += 0.22427933;
          }
        }
      }
    } else {
      if ( (data[21].missing != -1) && (data[21].fvalue < (float)61)) {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)115846)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)856123)) {
            result[0] += -0.88196844;
          } else {
            result[0] += 0.3344439;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)297491)) {
            result[0] += 0.46882913;
          } else {
            result[0] += -0.11764933;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)703)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)133802)) {
            result[0] += -0.19851956;
          } else {
            result[0] += 0.36234266;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)377104)) {
            result[0] += 0.4920623;
          } else {
            result[0] += 0.3728777;
          }
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)4728342)) {
    if ( (data[15].missing != -1) && (data[15].fvalue < (float)325)) {
      if ( (data[16].missing != -1) && (data[16].fvalue < (float)428)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)77992)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)983)) {
            result[0] += -0.31732345;
          } else {
            result[0] += 0.0021952626;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)178303)) {
            result[0] += -0.53731;
          } else {
            result[0] += -0.10524895;
          }
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)125892)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)60409)) {
            result[0] += 0.12194117;
          } else {
            result[0] += -0.18164001;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)312785)) {
            result[0] += -0.50980026;
          } else {
            result[0] += 0.066911265;
          }
        }
      }
    } else {
      if ( (data[15].missing != -1) && (data[15].fvalue < (float)22813)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)405)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)234)) {
            result[0] += -0.109244026;
          } else {
            result[0] += 0.25889078;
          }
        } else {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)130252)) {
            result[0] += 0.43999335;
          } else {
            result[0] += 0.07439154;
          }
        }
      } else {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)50289)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)29169)) {
            result[0] += 0.09638991;
          } else {
            result[0] += -0.14849134;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)413671)) {
            result[0] += -0.3515645;
          } else {
            result[0] += 0.1889767;
          }
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)6778337)) {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)215143)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)105477)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)314894)) {
            result[0] += 0.40630594;
          } else {
            result[0] += -0.004026077;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)393947)) {
            result[0] += 0.17996319;
          } else {
            result[0] += -0.7028288;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)44375)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)228)) {
            result[0] += -0.47483507;
          } else {
            result[0] += 0.36218616;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)53960)) {
            result[0] += -0.19485028;
          } else {
            result[0] += -0.928727;
          }
        }
      }
    } else {
      if ( (data[21].missing != -1) && (data[21].fvalue < (float)2494)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)390893)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)435266)) {
            result[0] += 0.42149034;
          } else {
            result[0] += -0.12716044;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)5218)) {
            result[0] += 0.13510214;
          } else {
            result[0] += -0.8554451;
          }
        }
      } else {
        result[0] += 0.45391127;
      }
    }
  }
  if ( (data[23].missing != -1) && (data[23].fvalue < (float)409356)) {
    if ( (data[12].missing != -1) && (data[12].fvalue < (float)202680)) {
      if ( (data[22].missing != -1) && (data[22].fvalue < (float)410925)) {
        if ( (data[8].missing != -1) && (data[8].fvalue < (float)391429)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)70083)) {
            result[0] += -0.09654555;
          } else {
            result[0] += -0.3010988;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)493)) {
            result[0] += -0.2932832;
          } else {
            result[0] += 0.4005494;
          }
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)91128)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)109314)) {
            result[0] += 0.38592812;
          } else {
            result[0] += -0.21606533;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)10252)) {
            result[0] += -0.011002466;
          } else {
            result[0] += -0.8756246;
          }
        }
      }
    } else {
      if ( (data[17].missing != -1) && (data[17].fvalue < (float)1188)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)127162)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)198846)) {
            result[0] += -0.38290992;
          } else {
            result[0] += 0.2687133;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)380)) {
            result[0] += -0.53816545;
          } else {
            result[0] += 0.13756882;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)130)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)79859)) {
            result[0] += 0.18505453;
          } else {
            result[0] += -0.2961317;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1833487)) {
            result[0] += 0.595915;
          } else {
            result[0] += 0.3046176;
          }
        }
      }
    }
  } else {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)6963)) {
      if ( (data[9].missing != -1) && (data[9].fvalue < (float)54396)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)205)) {
          result[0] += -0.67837405;
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)130972)) {
            result[0] += 0.36911964;
          } else {
            result[0] += -0.43019676;
          }
        }
      } else {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)158834)) {
          result[0] += -0.69956934;
        } else {
          result[0] += -0.080936514;
        }
      }
    } else {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)679284)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1401707)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)84614)) {
            result[0] += 0.62913334;
          } else {
            result[0] += 0.121250115;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)193048)) {
            result[0] += 0.07155492;
          } else {
            result[0] += 0.38258797;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)3673340)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)127485)) {
            result[0] += 0.5807669;
          } else {
            result[0] += -0.2310303;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)211)) {
            result[0] += -0.13203329;
          } else {
            result[0] += 0.43466076;
          }
        }
      }
    }
  }
  if ( (data[17].missing != -1) && (data[17].fvalue < (float)403555)) {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)512937)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)427636)) {
        result[0] += -0.4885521;
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)179103)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)8080)) {
            result[0] += -0.47197723;
          } else {
            result[0] += -0.08962237;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)272901)) {
            result[0] += 0.6763165;
          } else {
            result[0] += -0.52212423;
          }
        }
      }
    } else {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)50689)) {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)41613)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)106654)) {
            result[0] += 0.19633712;
          } else {
            result[0] += -0.18310837;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)271)) {
            result[0] += -0.25335088;
          } else {
            result[0] += 0.0543586;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)202383)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)460217)) {
            result[0] += -0.27436367;
          } else {
            result[0] += 0.2527815;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)339)) {
            result[0] += -0.16450283;
          } else {
            result[0] += 0.31871995;
          }
        }
      }
    }
  } else {
    if ( (data[15].missing != -1) && (data[15].fvalue < (float)864)) {
      if ( (data[11].missing != -1) && (data[11].fvalue < (float)125696)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)165484)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)891)) {
            result[0] += -0.52396065;
          } else {
            result[0] += 0.21539043;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)446)) {
            result[0] += -1.1118201;
          } else {
            result[0] += 0.098576404;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)5130512)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)870116)) {
            result[0] += -0.83856004;
          } else {
            result[0] += -0.17949572;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)18742)) {
            result[0] += 0.47887358;
          } else {
            result[0] += -0.50208694;
          }
        }
      }
    } else {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)511)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)130226)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)775)) {
            result[0] += 0.2560965;
          } else {
            result[0] += -0.44174653;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)5130512)) {
            result[0] += -0.60722035;
          } else {
            result[0] += 0.22420385;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)2377471)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)232374)) {
            result[0] += 0.62261575;
          } else {
            result[0] += -0.10826286;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)127)) {
            result[0] += -0.20554915;
          } else {
            result[0] += 0.37898827;
          }
        }
      }
    }
  }
  if ( (data[23].missing != -1) && (data[23].fvalue < (float)470051)) {
    if ( (data[10].missing != -1) && (data[10].fvalue < (float)140)) {
      if ( (data[21].missing != -1) && (data[21].fvalue < (float)497849)) {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)615)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)507262)) {
            result[0] += -0.2242887;
          } else {
            result[0] += 0.29013953;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)105505)) {
            result[0] += 0.053203285;
          } else {
            result[0] += -0.37579712;
          }
        }
      } else {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)75945)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)377)) {
            result[0] += -0.64700085;
          } else {
            result[0] += 0.42320773;
          }
        } else {
          result[0] += -0.7218382;
        }
      }
    } else {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)36380)) {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)701)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)523953)) {
            result[0] += -0.37748304;
          } else {
            result[0] += 0.08173012;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)273681)) {
            result[0] += 0.39205572;
          } else {
            result[0] += -0.20179705;
          }
        }
      } else {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)364647)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)481384)) {
            result[0] += -0.14514221;
          } else {
            result[0] += 0.2720725;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)1134)) {
            result[0] += -0.28122756;
          } else {
            result[0] += 0.31980804;
          }
        }
      }
    }
  } else {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)9187)) {
      if ( (data[7].missing != -1) && (data[7].fvalue < (float)133)) {
        result[0] += -0.79866636;
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)922)) {
          result[0] += -0.5617018;
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)3898)) {
            result[0] += 0.36412653;
          } else {
            result[0] += -0.3544384;
          }
        }
      }
    } else {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)905270)) {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)114126)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)187022)) {
            result[0] += 0.3366751;
          } else {
            result[0] += -0.10397401;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)329329)) {
            result[0] += -0.6774043;
          } else {
            result[0] += 0.30098787;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)3828286)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)61)) {
            result[0] += 0.29463464;
          } else {
            result[0] += 0.54463655;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)61)) {
            result[0] += -0.18680935;
          } else {
            result[0] += 0.41074142;
          }
        }
      }
    }
  }
  if ( (data[22].missing != -1) && (data[22].fvalue < (float)644623)) {
    if ( (data[12].missing != -1) && (data[12].fvalue < (float)286)) {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)24120)) {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)61)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)316)) {
            result[0] += -0.32442737;
          } else {
            result[0] += -0.050096788;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)546834)) {
            result[0] += -0.3064881;
          } else {
            result[0] += 0.15905795;
          }
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)15598)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)33921)) {
            result[0] += -0.0937336;
          } else {
            result[0] += -0.42799243;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)93379)) {
            result[0] += -0.28613168;
          } else {
            result[0] += -0.58730054;
          }
        }
      }
    } else {
      if ( (data[14].missing != -1) && (data[14].fvalue < (float)40209)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)96739)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)678897)) {
            result[0] += -0.15993129;
          } else {
            result[0] += 0.21122625;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)366810)) {
            result[0] += -0.19401294;
          } else {
            result[0] += 0.6521558;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)526730)) {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)197996)) {
            result[0] += -0.18053226;
          } else {
            result[0] += 0.1458751;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)557)) {
            result[0] += -0.39872366;
          } else {
            result[0] += 0.3792455;
          }
        }
      }
    }
  } else {
    if ( (data[23].missing != -1) && (data[23].fvalue < (float)4776)) {
      if ( (data[24].missing != -1) && (data[24].fvalue < (float)122)) {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)1442393)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)65068)) {
            result[0] += -1.336475;
          } else {
            result[0] += -0.36213338;
          }
        } else {
          result[0] += -0.038339775;
        }
      } else {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)142)) {
          result[0] += 0.36821768;
        } else {
          result[0] += -0.3622484;
        }
      }
    } else {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)1150)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)76555)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)231334)) {
            result[0] += 0.2967857;
          } else {
            result[0] += -0.53365463;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)3673)) {
            result[0] += 0.01245467;
          } else {
            result[0] += -0.87496156;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)890699)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)126156)) {
            result[0] += 0.33311802;
          } else {
            result[0] += -0.2572041;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)167516)) {
            result[0] += 0.41781536;
          } else {
            result[0] += 0.22896364;
          }
        }
      }
    }
  }
  if ( (data[1].missing != -1) && (data[1].fvalue < (float)124628)) {
    if ( (data[5].missing != -1) && (data[5].fvalue < (float)109611)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)599607)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)477762)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)179103)) {
            result[0] += -0.42860433;
          } else {
            result[0] += -0.072328694;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)360)) {
            result[0] += -0.27158818;
          } else {
            result[0] += 0.0833344;
          }
        }
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)61)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)512)) {
            result[0] += -0.16801661;
          } else {
            result[0] += 0.0657948;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)35254)) {
            result[0] += 0.2597347;
          } else {
            result[0] += 0.060495354;
          }
        }
      }
    } else {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)564354)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)49631)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)28088)) {
            result[0] += 0.013388747;
          } else {
            result[0] += -0.2994547;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)7434863)) {
            result[0] += -0.38709813;
          } else {
            result[0] += 0.30994034;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)11868)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)144097)) {
            result[0] += -0.6662913;
          } else {
            result[0] += 0.06678842;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)61)) {
            result[0] += -0.5618858;
          } else {
            result[0] += 0.4463205;
          }
        }
      }
    }
  } else {
    if ( (data[2].missing != -1) && (data[2].fvalue < (float)451000)) {
      if ( (data[4].missing != -1) && (data[4].fvalue < (float)61821)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)34864)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)324)) {
            result[0] += -0.41891313;
          } else {
            result[0] += 0.0071526007;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)251069)) {
            result[0] += -0.38847548;
          } else {
            result[0] += 0.21540165;
          }
        }
      } else {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)477200)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)20718)) {
            result[0] += -0.19663662;
          } else {
            result[0] += -0.4718872;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)13968)) {
            result[0] += -0.63127935;
          } else {
            result[0] += 0.41600657;
          }
        }
      }
    } else {
      if ( (data[6].missing != -1) && (data[6].fvalue < (float)115163)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)201858)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)5160)) {
            result[0] += -0.04670545;
          } else {
            result[0] += -0.6753228;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)8400)) {
            result[0] += 0.44543558;
          } else {
            result[0] += -0.26721168;
          }
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)140395)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)213684)) {
            result[0] += 0.9932994;
          } else {
            result[0] += 0.021969393;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)422)) {
            result[0] += -0.51566803;
          } else {
            result[0] += 0.41761103;
          }
        }
      }
    }
  }
  if ( (data[4].missing != -1) && (data[4].fvalue < (float)90065)) {
    if ( (data[9].missing != -1) && (data[9].fvalue < (float)20105)) {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)734)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)122)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)89047)) {
            result[0] += -0.09095434;
          } else {
            result[0] += -0.37741977;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)444)) {
            result[0] += -0.11565615;
          } else {
            result[0] += 0.11618292;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)584)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)100013)) {
            result[0] += 0.17432418;
          } else {
            result[0] += -0.25572354;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)56332)) {
            result[0] += 0.42066428;
          } else {
            result[0] += 0.24598669;
          }
        }
      }
    } else {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)356962)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)26766)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)1320)) {
            result[0] += -0.14232495;
          } else {
            result[0] += 0.25485808;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)381541)) {
            result[0] += -0.25536156;
          } else {
            result[0] += 0.1388517;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)139)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)412841)) {
            result[0] += -0.49481684;
          } else {
            result[0] += 0.14946036;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)241324)) {
            result[0] += 0.33715552;
          } else {
            result[0] += -0.38294306;
          }
        }
      }
    }
  } else {
    if ( (data[3].missing != -1) && (data[3].fvalue < (float)392169)) {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)43824)) {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)321)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)625)) {
            result[0] += -0.1193172;
          } else {
            result[0] += -0.39790824;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)338769)) {
            result[0] += 0.09890475;
          } else {
            result[0] += -0.63058037;
          }
        }
      } else {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)760169)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)401994)) {
            result[0] += -0.43862796;
          } else {
            result[0] += 0.0683345;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)135394)) {
            result[0] += -0.03380903;
          } else {
            result[0] += 0.533047;
          }
        }
      }
    } else {
      if ( (data[9].missing != -1) && (data[9].fvalue < (float)1821)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1093874)) {
          result[0] += 0.53697735;
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)94873)) {
            result[0] += 0.20259719;
          } else {
            result[0] += -0.43259174;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)3604837)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)177804)) {
            result[0] += 0.6609219;
          } else {
            result[0] += -0.44630557;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)2141)) {
            result[0] += -0.8335266;
          } else {
            result[0] += 0.19313177;
          }
        }
      }
    }
  }
  if ( (data[23].missing != -1) && (data[23].fvalue < (float)638062)) {
    if ( (data[24].missing != -1) && (data[24].fvalue < (float)57287)) {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)78722)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)557)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)135300)) {
            result[0] += 0.03561399;
          } else {
            result[0] += -0.25636116;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)628)) {
            result[0] += 0.06878476;
          } else {
            result[0] += 0.28834975;
          }
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)574)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)18055)) {
            result[0] += 0.08848183;
          } else {
            result[0] += -0.3157425;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)89595)) {
            result[0] += -0.09805902;
          } else {
            result[0] += 0.15457432;
          }
        }
      }
    } else {
      if ( (data[18].missing != -1) && (data[18].fvalue < (float)195871)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)27354)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)201)) {
            result[0] += -0.20801964;
          } else {
            result[0] += 0.26592255;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)48018)) {
            result[0] += -0.16051592;
          } else {
            result[0] += -0.4021039;
          }
        }
      } else {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)199990)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)12374)) {
            result[0] += 0.22754768;
          } else {
            result[0] += -0.011075449;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)372817)) {
            result[0] += -0.66620886;
          } else {
            result[0] += 0.13693534;
          }
        }
      }
    }
  } else {
    if ( (data[21].missing != -1) && (data[21].fvalue < (float)212)) {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)445)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)1187)) {
          result[0] += -0.47990724;
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)9169)) {
            result[0] += 0.37982625;
          } else {
            result[0] += -0.05372584;
          }
        }
      } else {
        result[0] += -0.78615874;
      }
    } else {
      if ( (data[24].missing != -1) && (data[24].fvalue < (float)61)) {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)578)) {
          result[0] += -0.10997545;
        } else {
          result[0] += -0.70544046;
        }
      } else {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)379375)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)282)) {
            result[0] += 0.9950654;
          } else {
            result[0] += 0.3617731;
          }
        } else {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)1051)) {
            result[0] += -0.52452195;
          } else {
            result[0] += 0.21267687;
          }
        }
      }
    }
  }
  if ( (data[0].missing != -1) && (data[0].fvalue < (float)209743)) {
    if ( (data[0].missing != -1) && (data[0].fvalue < (float)128)) {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)246376)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)197)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)112175)) {
            result[0] += -0.19618061;
          } else {
            result[0] += 0.16433224;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)22262)) {
            result[0] += 0.16469115;
          } else {
            result[0] += -0.03792843;
          }
        }
      } else {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)1478)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)5728656)) {
            result[0] += -0.69190913;
          } else {
            result[0] += 0.21926022;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)199186)) {
            result[0] += -0.44457027;
          } else {
            result[0] += -0.0032686621;
          }
        }
      }
    } else {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)42152)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)133)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)473)) {
            result[0] += -0.1323087;
          } else {
            result[0] += 0.09649769;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)584)) {
            result[0] += 0.13098633;
          } else {
            result[0] += 0.2909456;
          }
        }
      } else {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)20880)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)44375)) {
            result[0] += 0.12614964;
          } else {
            result[0] += -0.094099864;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)553116)) {
            result[0] += -0.17353334;
          } else {
            result[0] += 0.31090504;
          }
        }
      }
    }
  } else {
    if ( (data[24].missing != -1) && (data[24].fvalue < (float)40471)) {
      if ( (data[14].missing != -1) && (data[14].fvalue < (float)62666)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)29169)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)304)) {
            result[0] += -0.09827944;
          } else {
            result[0] += 0.26504532;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)313708)) {
            result[0] += -0.4106567;
          } else {
            result[0] += 0.27615294;
          }
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)3469)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)223623)) {
            result[0] += -0.53483087;
          } else {
            result[0] += -0.115062535;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)468884)) {
            result[0] += -0.25288153;
          } else {
            result[0] += 0.42191073;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)477200)) {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)725773)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)820005)) {
            result[0] += -0.500299;
          } else {
            result[0] += 0.3010666;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)91105)) {
            result[0] += -0.2579382;
          } else {
            result[0] += 0.4168209;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)16316)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)62)) {
            result[0] += 0.0061665704;
          } else {
            result[0] += 0.7225964;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)183737)) {
            result[0] += -0.6699979;
          } else {
            result[0] += 0.27228966;
          }
        }
      }
    }
  }
  if ( (data[15].missing != -1) && (data[15].fvalue < (float)495)) {
    if ( (data[11].missing != -1) && (data[11].fvalue < (float)125696)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)477762)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)159605)) {
          result[0] += -0.4294889;
        } else {
          result[0] += 0.4018147;
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)340)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)105694)) {
            result[0] += -0.056500282;
          } else {
            result[0] += -0.34331572;
          }
        } else {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)18307)) {
            result[0] += 0.18232378;
          } else {
            result[0] += -0.077551;
          }
        }
      }
    } else {
      if ( (data[16].missing != -1) && (data[16].fvalue < (float)199347)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)1708)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)970)) {
            result[0] += -0.38901073;
          } else {
            result[0] += -0.6386904;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)215221)) {
            result[0] += -0.13454781;
          } else {
            result[0] += -0.5742903;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)268921)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)4272)) {
            result[0] += -0.4994588;
          } else {
            result[0] += 0.4680687;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)246156)) {
            result[0] += -0.0051006214;
          } else {
            result[0] += -0.6970884;
          }
        }
      }
    }
  } else {
    if ( (data[15].missing != -1) && (data[15].fvalue < (float)51545)) {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)18307)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)477762)) {
          result[0] += -0.4318222;
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)111545)) {
            result[0] += 0.30011937;
          } else {
            result[0] += 0.04328873;
          }
        }
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)44982)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)387)) {
            result[0] += -0.111924626;
          } else {
            result[0] += 0.21372409;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)17644)) {
            result[0] += 0.008275459;
          } else {
            result[0] += -0.32947156;
          }
        }
      }
    } else {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)151469)) {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)444532)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)15598)) {
            result[0] += -0.046030235;
          } else {
            result[0] += -0.22065356;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)2038)) {
            result[0] += -0.29677716;
          } else {
            result[0] += 0.27651617;
          }
        }
      } else {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)53234)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)210669)) {
            result[0] += 0.49660847;
          } else {
            result[0] += 0.05076132;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)6778337)) {
            result[0] += -0.0352656;
          } else {
            result[0] += 0.37425965;
          }
        }
      }
    }
  }
  if ( (data[5].missing != -1) && (data[5].fvalue < (float)46984)) {
    if ( (data[5].missing != -1) && (data[5].fvalue < (float)991)) {
      if ( (data[1].missing != -1) && (data[1].fvalue < (float)129047)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)224534)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)512937)) {
            result[0] += -0.33156192;
          } else {
            result[0] += 0.03750589;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)855413)) {
            result[0] += -0.44274774;
          } else {
            result[0] += 0.58934885;
          }
        }
      } else {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)4025)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1009506)) {
            result[0] += 0.118006684;
          } else {
            result[0] += -0.25873065;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)6182253)) {
            result[0] += -0.48884773;
          } else {
            result[0] += 0.16425233;
          }
        }
      }
    } else {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)281690)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)394)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)65898)) {
            result[0] += 0.16343264;
          } else {
            result[0] += -0.22082531;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)25520)) {
            result[0] += 0.3345133;
          } else {
            result[0] += 0.056698598;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)330249)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)390)) {
            result[0] += -0.64250547;
          } else {
            result[0] += -0.31613025;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)2074)) {
            result[0] += -0.43874994;
          } else {
            result[0] += 0.26576144;
          }
        }
      }
    }
  } else {
    if ( (data[21].missing != -1) && (data[21].fvalue < (float)45743)) {
      if ( (data[1].missing != -1) && (data[1].fvalue < (float)496)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)1580)) {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)204470)) {
            result[0] += -0.18860827;
          } else {
            result[0] += -0.5092388;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)15129)) {
            result[0] += 0.11785884;
          } else {
            result[0] += -0.18071054;
          }
        }
      } else {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)60814)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)70237)) {
            result[0] += 0.2873426;
          } else {
            result[0] += 0.029225899;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)254085)) {
            result[0] += -0.107688844;
          } else {
            result[0] += 0.1799693;
          }
        }
      }
    } else {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)8292884)) {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)21569)) {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)5868)) {
            result[0] += -0.1850342;
          } else {
            result[0] += 0.12020288;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)49200)) {
            result[0] += -0.23249571;
          } else {
            result[0] += -0.41051674;
          }
        }
      } else {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)13785)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)478435)) {
            result[0] += -0.19130532;
          } else {
            result[0] += 0.2512732;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)7329)) {
            result[0] += 0.12126155;
          } else {
            result[0] += 0.39386442;
          }
        }
      }
    }
  }
  if ( (data[4].missing != -1) && (data[4].fvalue < (float)47240)) {
    if ( (data[9].missing != -1) && (data[9].fvalue < (float)107616)) {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)97243)) {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)131)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)47657)) {
            result[0] += 0.040193483;
          } else {
            result[0] += -0.16553362;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)103354)) {
            result[0] += 0.1636245;
          } else {
            result[0] += -0.05109908;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)166525)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)593326)) {
            result[0] += -0.21212156;
          } else {
            result[0] += 0.1933916;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)130696)) {
            result[0] += 0.24479966;
          } else {
            result[0] += -0.12478062;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)1084)) {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)204)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)557)) {
            result[0] += -0.4352865;
          } else {
            result[0] += -0.11118486;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)81523)) {
            result[0] += 0.006704343;
          } else {
            result[0] += -0.3822265;
          }
        }
      } else {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)204692)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)21540)) {
            result[0] += 0.0472272;
          } else {
            result[0] += -0.3141607;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)588)) {
            result[0] += -0.12771522;
          } else {
            result[0] += 0.39282352;
          }
        }
      }
    }
  } else {
    if ( (data[3].missing != -1) && (data[3].fvalue < (float)233737)) {
      if ( (data[9].missing != -1) && (data[9].fvalue < (float)57560)) {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)71142)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)144779)) {
            result[0] += 0.06562788;
          } else {
            result[0] += -0.16242345;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)19967)) {
            result[0] += 0.29794955;
          } else {
            result[0] += -0.32221645;
          }
        }
      } else {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)228601)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)556371)) {
            result[0] += 0.4518434;
          } else {
            result[0] += -0.41080546;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)97953)) {
            result[0] += 0.17882007;
          } else {
            result[0] += -0.32587236;
          }
        }
      }
    } else {
      if ( (data[9].missing != -1) && (data[9].fvalue < (float)1441)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)5049)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)89047)) {
            result[0] += -0.52031374;
          } else {
            result[0] += -0.21544369;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)135208)) {
            result[0] += 0.11431958;
          } else {
            result[0] += -0.36780593;
          }
        }
      } else {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)446)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)1257451)) {
            result[0] += -0.31604978;
          } else {
            result[0] += 1.0685104;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)2301273)) {
            result[0] += 0.6140347;
          } else {
            result[0] += 0.16047654;
          }
        }
      }
    }
  }
  if ( (data[22].missing != -1) && (data[22].fvalue < (float)984980)) {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)427636)) {
      result[0] += -0.41660586;
    } else {
      if ( (data[4].missing != -1) && (data[4].fvalue < (float)29956)) {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)224472)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)193)) {
            result[0] += -0.016514337;
          } else {
            result[0] += 0.085349075;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)507)) {
            result[0] += -0.5879922;
          } else {
            result[0] += -0.09472415;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)388212)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)19127)) {
            result[0] += -0.02821807;
          } else {
            result[0] += -0.16903087;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)124)) {
            result[0] += -0.3842974;
          } else {
            result[0] += 0.25440896;
          }
        }
      }
    }
  } else {
    if ( (data[23].missing != -1) && (data[23].fvalue < (float)3992)) {
      if ( (data[13].missing != -1) && (data[13].fvalue < (float)9327)) {
        result[0] += 0.21309364;
      } else {
        result[0] += -0.52628744;
      }
    } else {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)124)) {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)385)) {
          result[0] += 0.3408897;
        } else {
          result[0] += -0.5480539;
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)108202)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)780693)) {
            result[0] += 0.4016409;
          } else {
            result[0] += 0.049905386;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)1442393)) {
            result[0] += -0.16189002;
          } else {
            result[0] += 0.2886462;
          }
        }
      }
    }
  }
  if ( (data[17].missing != -1) && (data[17].fvalue < (float)44375)) {
    if ( (data[17].missing != -1) && (data[17].fvalue < (float)125)) {
      if ( (data[16].missing != -1) && (data[16].fvalue < (float)309330)) {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)289647)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)729)) {
            result[0] += -0.07291817;
          } else {
            result[0] += 0.095591456;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)213283)) {
            result[0] += -0.51266545;
          } else {
            result[0] += -0.12887166;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)533070)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)46983)) {
            result[0] += -0.8405313;
          } else {
            result[0] += -0.43054643;
          }
        } else {
          result[0] += 0.13512363;
        }
      }
    } else {
      if ( (data[22].missing != -1) && (data[22].fvalue < (float)85091)) {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)2517)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)353)) {
            result[0] += -0.10906072;
          } else {
            result[0] += 0.15291989;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)71880)) {
            result[0] += 0.33334866;
          } else {
            result[0] += 0.08030056;
          }
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)68546)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)87290)) {
            result[0] += 0.16246025;
          } else {
            result[0] += -0.24908614;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)494956)) {
            result[0] += -0.29226202;
          } else {
            result[0] += 0.29297706;
          }
        }
      }
    }
  } else {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)61)) {
      if ( (data[17].missing != -1) && (data[17].fvalue < (float)81080)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)41816)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)94666)) {
            result[0] += 0.3234612;
          } else {
            result[0] += -0.21125285;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)468884)) {
            result[0] += -0.31081182;
          } else {
            result[0] += 0.41893792;
          }
        }
      } else {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)182261)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)297491)) {
            result[0] += -0.3528497;
          } else {
            result[0] += -0.10174467;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1740545)) {
            result[0] += 0.30655977;
          } else {
            result[0] += -0.19498965;
          }
        }
      }
    } else {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)187452)) {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)71730)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)93140)) {
            result[0] += 0.087631956;
          } else {
            result[0] += -0.12511216;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)27354)) {
            result[0] += -0.08073916;
          } else {
            result[0] += -0.37107262;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)190527)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)156193)) {
            result[0] += 0.030718103;
          } else {
            result[0] += -0.50775313;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)2114867)) {
            result[0] += 0.42822418;
          } else {
            result[0] += 0.10522186;
          }
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)660723)) {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)134370)) {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)146650)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)176996)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)45402)) {
            result[0] += -0.37070078;
          } else {
            result[0] += -0.04995742;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)18227)) {
            result[0] += 0.34602004;
          } else {
            result[0] += -0.42567593;
          }
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)102045)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)45566)) {
            result[0] += 0.16818564;
          } else {
            result[0] += 0.77533513;
          }
        } else {
          result[0] += -0.4688871;
        }
      }
    } else {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)72521)) {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)63)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)922)) {
            result[0] += -0.44707045;
          } else {
            result[0] += 0.2852815;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)7479)) {
            result[0] += 0.52890134;
          } else {
            result[0] += 1.1096365;
          }
        }
      } else {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)1020)) {
          result[0] += -0.730498;
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)1580)) {
            result[0] += -0.024120172;
          } else {
            result[0] += 0.42645454;
          }
        }
      }
    }
  } else {
    if ( (data[14].missing != -1) && (data[14].fvalue < (float)41613)) {
      if ( (data[14].missing != -1) && (data[14].fvalue < (float)273)) {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)111892)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)130226)) {
            result[0] += 0.050250527;
          } else {
            result[0] += -0.19025074;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)258904)) {
            result[0] += -0.17795324;
          } else {
            result[0] += -0.5645918;
          }
        }
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)35254)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)218230)) {
            result[0] += 0.2559785;
          } else {
            result[0] += -0.119746424;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)2364)) {
            result[0] += -0.123556904;
          } else {
            result[0] += 0.11001965;
          }
        }
      }
    } else {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)142802)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)277483)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)361882)) {
            result[0] += -0.17534754;
          } else {
            result[0] += 0.20788847;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)161269)) {
            result[0] += 0.27867916;
          } else {
            result[0] += -0.17264244;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1451640)) {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)273393)) {
            result[0] += 0.26650527;
          } else {
            result[0] += 1.1801134;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)154969)) {
            result[0] += -0.08581604;
          } else {
            result[0] += 0.14240383;
          }
        }
      }
    }
  }
  if ( (data[10].missing != -1) && (data[10].fvalue < (float)340)) {
    if ( (data[7].missing != -1) && (data[7].fvalue < (float)44605)) {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)132403)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)193)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)396792)) {
            result[0] += -0.09601151;
          } else {
            result[0] += 0.25349885;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)299910)) {
            result[0] += 0.09294654;
          } else {
            result[0] += -0.2798607;
          }
        }
      } else {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)153428)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)69229)) {
            result[0] += -0.5526137;
          } else {
            result[0] += -0.12098918;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)19616)) {
            result[0] += 0.2276759;
          } else {
            result[0] += -0.4547049;
          }
        }
      }
    } else {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)418)) {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)87541)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)352988)) {
            result[0] += -0.49400863;
          } else {
            result[0] += 0.2202832;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)209)) {
            result[0] += -0.4761214;
          } else {
            result[0] += 0.07249514;
          }
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)41147)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)364284)) {
            result[0] += 0.24521561;
          } else {
            result[0] += -0.92664635;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)25898)) {
            result[0] += -0.06405932;
          } else {
            result[0] += -0.30560753;
          }
        }
      }
    }
  } else {
    if ( (data[10].missing != -1) && (data[10].fvalue < (float)18307)) {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)135)) {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)46984)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)61)) {
            result[0] += -0.004136194;
          } else {
            result[0] += 0.2226506;
          }
        } else {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)370365)) {
            result[0] += -0.21356364;
          } else {
            result[0] += 0.5254114;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)339691)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)236931)) {
            result[0] += 0.24123529;
          } else {
            result[0] += -0.13656215;
          }
        } else {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)2214)) {
            result[0] += -0.7424706;
          } else {
            result[0] += 0.010712666;
          }
        }
      }
    } else {
      if ( (data[6].missing != -1) && (data[6].fvalue < (float)716)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)55770)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)90651)) {
            result[0] += -0.027327314;
          } else {
            result[0] += -0.35980138;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)61)) {
            result[0] += -0.16475257;
          } else {
            result[0] += -0.4050277;
          }
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)18182)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)193)) {
            result[0] += -0.0012416741;
          } else {
            result[0] += 0.257951;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)45849)) {
            result[0] += 0.0644426;
          } else {
            result[0] += -0.08350541;
          }
        }
      }
    }
  }
  if ( (data[1].missing != -1) && (data[1].fvalue < (float)129047)) {
    if ( (data[23].missing != -1) && (data[23].fvalue < (float)905270)) {
      if ( (data[21].missing != -1) && (data[21].fvalue < (float)853046)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)675152)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)109314)) {
            result[0] += 0.021094086;
          } else {
            result[0] += -0.07370954;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)3548713)) {
            result[0] += 0.53653574;
          } else {
            result[0] += 0.080767214;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)873)) {
          result[0] += -0.5809417;
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)2261)) {
            result[0] += 0.4200378;
          } else {
            result[0] += 0.11707492;
          }
        }
      }
    } else {
      if ( (data[24].missing != -1) && (data[24].fvalue < (float)19813)) {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)840)) {
          result[0] += -0.717449;
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)156193)) {
            result[0] += -0.1479684;
          } else {
            result[0] += 0.24113312;
          }
        }
      } else {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)128529)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)780693)) {
            result[0] += 0.41386634;
          } else {
            result[0] += 0.19820791;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)238607)) {
            result[0] += -0.42126822;
          } else {
            result[0] += 0.3423704;
          }
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)2377471)) {
      if ( (data[2].missing != -1) && (data[2].fvalue < (float)475950)) {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)75282)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)55776)) {
            result[0] += -0.0035567102;
          } else {
            result[0] += 0.3696306;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)150563)) {
            result[0] += -0.21631399;
          } else {
            result[0] += 0.18930678;
          }
        }
      } else {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)276)) {
          result[0] += -0.44323707;
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)131)) {
            result[0] += 0.99911195;
          } else {
            result[0] += 0.30363008;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)543569)) {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)187585)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)32052)) {
            result[0] += -0.074715704;
          } else {
            result[0] += -0.46356255;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)67087)) {
            result[0] += -0.4227533;
          } else {
            result[0] += 0.043787833;
          }
        }
      } else {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)123905)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)10990)) {
            result[0] += 0.20402041;
          } else {
            result[0] += -0.53223085;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)60699)) {
            result[0] += -0.19516364;
          } else {
            result[0] += 0.67859644;
          }
        }
      }
    }
  }
  if ( (data[24].missing != -1) && (data[24].fvalue < (float)17793)) {
    if ( (data[23].missing != -1) && (data[23].fvalue < (float)133)) {
      if ( (data[18].missing != -1) && (data[18].fvalue < (float)116189)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)151469)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)218)) {
            result[0] += -0.1524419;
          } else {
            result[0] += 0.020275936;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)168238)) {
            result[0] += 0.3834153;
          } else {
            result[0] += 0.07191902;
          }
        }
      } else {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)621)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)660723)) {
            result[0] += 0.054774653;
          } else {
            result[0] += -0.5479943;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)133518)) {
            result[0] += -0.04897922;
          } else {
            result[0] += -0.37816676;
          }
        }
      }
    } else {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)61985)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)122)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)274351)) {
            result[0] += 0.0784575;
          } else {
            result[0] += -0.6344474;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)247090)) {
            result[0] += 0.22305314;
          } else {
            result[0] += -0.271255;
          }
        }
      } else {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)25231)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)451)) {
            result[0] += -0.06320843;
          } else {
            result[0] += 0.24917875;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)426)) {
            result[0] += -0.35212216;
          } else {
            result[0] += -0.031658858;
          }
        }
      }
    }
  } else {
    if ( (data[18].missing != -1) && (data[18].fvalue < (float)190390)) {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)30722)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)74997)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)336)) {
            result[0] += 0.052741524;
          } else {
            result[0] += -0.23165193;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)300311)) {
            result[0] += 0.32270575;
          } else {
            result[0] += -0.3117722;
          }
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)19396)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)410925)) {
            result[0] += -0.107119195;
          } else {
            result[0] += 0.21728852;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)690482)) {
            result[0] += -0.28608936;
          } else {
            result[0] += 0.41504166;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)266802)) {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)202383)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)161269)) {
            result[0] += 0.0895682;
          } else {
            result[0] += -0.52161497;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)397)) {
            result[0] += -0.14226814;
          } else {
            result[0] += 0.30063957;
          }
        }
      } else {
        if ( (data[8].missing != -1) && (data[8].fvalue < (float)454875)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)296835)) {
            result[0] += -0.51656234;
          } else {
            result[0] += -1.012382;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)590)) {
            result[0] += -0.6471984;
          } else {
            result[0] += 0.28892678;
          }
        }
      }
    }
  }
  if ( (data[20].missing != -1) && (data[20].fvalue < (float)50071)) {
    if ( (data[20].missing != -1) && (data[20].fvalue < (float)751)) {
      if ( (data[22].missing != -1) && (data[22].fvalue < (float)277656)) {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)123)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)28088)) {
            result[0] += -0.045670908;
          } else {
            result[0] += -0.23611271;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)34175)) {
            result[0] += 0.13687526;
          } else {
            result[0] += -0.024902755;
          }
        }
      } else {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)12167)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)49875)) {
            result[0] += -0.8672599;
          } else {
            result[0] += -0.32071862;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1583758)) {
            result[0] += 0.11439973;
          } else {
            result[0] += -0.38706747;
          }
        }
      }
    } else {
      if ( (data[15].missing != -1) && (data[15].fvalue < (float)181839)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)282)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)63)) {
            result[0] += -0.17269108;
          } else {
            result[0] += 0.12192404;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)183558)) {
            result[0] += 0.25608423;
          } else {
            result[0] += -0.10166984;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)8771)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)48780)) {
            result[0] += -0.52563375;
          } else {
            result[0] += 0.39001346;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)139)) {
            result[0] += -0.35032842;
          } else {
            result[0] += 0.087370485;
          }
        }
      }
    }
  } else {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)54295)) {
      if ( (data[9].missing != -1) && (data[9].fvalue < (float)89536)) {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)171401)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)25520)) {
            result[0] += 0.08402712;
          } else {
            result[0] += -0.10810995;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)110991)) {
            result[0] += -0.09480398;
          } else {
            result[0] += 0.3332078;
          }
        }
      } else {
        if ( (data[8].missing != -1) && (data[8].fvalue < (float)268225)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)221000)) {
            result[0] += -0.38005996;
          } else {
            result[0] += 0.081507176;
          }
        } else {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)36380)) {
            result[0] += 0.28182894;
          } else {
            result[0] += -0.21247311;
          }
        }
      }
    } else {
      if ( (data[21].missing != -1) && (data[21].fvalue < (float)691562)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)35945)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)1481)) {
            result[0] += -0.09324564;
          } else {
            result[0] += 0.2695274;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)470051)) {
            result[0] += -0.17364435;
          } else {
            result[0] += 0.15726441;
          }
        }
      } else {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)21271)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)381541)) {
            result[0] += 0.45023218;
          } else {
            result[0] += 0.19278108;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)1746)) {
            result[0] += -0.42798048;
          } else {
            result[0] += 0.17759655;
          }
        }
      }
    }
  }
  if ( (data[24].missing != -1) && (data[24].fvalue < (float)131)) {
    if ( (data[19].missing != -1) && (data[19].fvalue < (float)199267)) {
      if ( (data[22].missing != -1) && (data[22].fvalue < (float)214)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)8710)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)134368)) {
            result[0] += -0.13043286;
          } else {
            result[0] += 0.09823024;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)250748)) {
            result[0] += 0.3756167;
          } else {
            result[0] += -0.35878563;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)208947)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)19066)) {
            result[0] += 0.110855184;
          } else {
            result[0] += -0.0727549;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1441476)) {
            result[0] += 0.06801797;
          } else {
            result[0] += -0.31406197;
          }
        }
      }
    } else {
      if ( (data[18].missing != -1) && (data[18].fvalue < (float)1824)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)4300)) {
          result[0] += -0.48100486;
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)9931)) {
            result[0] += 0.6411191;
          } else {
            result[0] += -0.31391603;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)636717)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)632797)) {
            result[0] += -0.5340792;
          } else {
            result[0] += -0.0390841;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)169621)) {
            result[0] += 0.039654087;
          } else {
            result[0] += 0.25988233;
          }
        }
      }
    }
  } else {
    if ( (data[24].missing != -1) && (data[24].fvalue < (float)15598)) {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)136790)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)184743)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)111409)) {
            result[0] += 0.054057445;
          } else {
            result[0] += 0.25004166;
          }
        } else {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)112813)) {
            result[0] += 0.3662482;
          } else {
            result[0] += -0.17035268;
          }
        }
      } else {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)12626)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)264)) {
            result[0] += -0.17683768;
          } else {
            result[0] += 0.14333384;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)590981)) {
            result[0] += -0.46254262;
          } else {
            result[0] += 0.21210973;
          }
        }
      }
    } else {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)35254)) {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)27478)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)185812)) {
            result[0] += 0.18786459;
          } else {
            result[0] += -0.07419788;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)190390)) {
            result[0] += -0.1376739;
          } else {
            result[0] += 0.14211926;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)688645)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)54295)) {
            result[0] += 0.004927648;
          } else {
            result[0] += -0.1511331;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)168698)) {
            result[0] += 0.32107934;
          } else {
            result[0] += 0.025089083;
          }
        }
      }
    }
  }
  if ( (data[15].missing != -1) && (data[15].fvalue < (float)61)) {
    if ( (data[18].missing != -1) && (data[18].fvalue < (float)274351)) {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)313914)) {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)361420)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)108747)) {
            result[0] += -0.03057613;
          } else {
            result[0] += -0.21392806;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)209)) {
            result[0] += -0.59685653;
          } else {
            result[0] += 0.29334974;
          }
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)402418)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)599008)) {
            result[0] += -0.58050007;
          } else {
            result[0] += -0.07975725;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)432309)) {
            result[0] += -0.3218541;
          } else {
            result[0] += 0.26394758;
          }
        }
      }
    } else {
      if ( (data[24].missing != -1) && (data[24].fvalue < (float)102045)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)1104277)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)533070)) {
            result[0] += -0.56930566;
          } else {
            result[0] += 0.23554003;
          }
        } else {
          result[0] += 0.38115412;
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)33319)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)600)) {
            result[0] += -0.2587038;
          } else {
            result[0] += 0.27490148;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)37054)) {
            result[0] += 0.04723169;
          } else {
            result[0] += -0.73533064;
          }
        }
      }
    }
  } else {
    if ( (data[15].missing != -1) && (data[15].fvalue < (float)30044)) {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)227078)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)593)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)529)) {
            result[0] += -0.094027326;
          } else {
            result[0] += 0.09639636;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)81483)) {
            result[0] += 0.19603637;
          } else {
            result[0] += 0.05231337;
          }
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)316279)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)205768)) {
            result[0] += -0.39051268;
          } else {
            result[0] += -0.013642922;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)290)) {
            result[0] += -0.53871316;
          } else {
            result[0] += 0.34517828;
          }
        }
      }
    } else {
      if ( (data[7].missing != -1) && (data[7].fvalue < (float)125)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)78978)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)282968)) {
            result[0] += -0.03638371;
          } else {
            result[0] += -0.7766148;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)506714)) {
            result[0] += -0.45432994;
          } else {
            result[0] += 0.38251397;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)1043)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)100010)) {
            result[0] += -0.024562934;
          } else {
            result[0] += -0.37337172;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)319595)) {
            result[0] += 0.07458582;
          } else {
            result[0] += -0.4032452;
          }
        }
      }
    }
  }
  if ( (data[10].missing != -1) && (data[10].fvalue < (float)97292)) {
    if ( (data[5].missing != -1) && (data[5].fvalue < (float)273681)) {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)1364)) {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)44081)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)151052)) {
            result[0] += 0.046501298;
          } else {
            result[0] += -0.17488234;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)81768)) {
            result[0] += -0.20730081;
          } else {
            result[0] += -0.010841031;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)166525)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)40682)) {
            result[0] += 0.12817864;
          } else {
            result[0] += -0.05368146;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)269866)) {
            result[0] += 0.2377734;
          } else {
            result[0] += -0.20172302;
          }
        }
      }
    } else {
      if ( (data[1].missing != -1) && (data[1].fvalue < (float)477340)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)69363)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)141760)) {
            result[0] += -0.257884;
          } else {
            result[0] += 0.29062685;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)636717)) {
            result[0] += -0.5728589;
          } else {
            result[0] += 0.27285942;
          }
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)16022)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)285761)) {
            result[0] += -0.42132598;
          } else {
            result[0] += 0.23982823;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)259289)) {
            result[0] += 0.04042488;
          } else {
            result[0] += 0.8908926;
          }
        }
      }
    }
  } else {
    if ( (data[15].missing != -1) && (data[15].fvalue < (float)197510)) {
      if ( (data[7].missing != -1) && (data[7].fvalue < (float)2554)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)20747)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)95386)) {
            result[0] += -0.2077924;
          } else {
            result[0] += 0.16154066;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)392829)) {
            result[0] += -0.42892334;
          } else {
            result[0] += 0.07389194;
          }
        }
      } else {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)7046)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)402)) {
            result[0] += 0.5049357;
          } else {
            result[0] += 0.034746844;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)182230)) {
            result[0] += -0.15456237;
          } else {
            result[0] += 0.026655803;
          }
        }
      }
    } else {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)39530)) {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)110357)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)394)) {
            result[0] += -0.50911224;
          } else {
            result[0] += 0.17634492;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)477023)) {
            result[0] += -0.4808533;
          } else {
            result[0] += 0.3129883;
          }
        }
      } else {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)245548)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)118000)) {
            result[0] += 0.56304824;
          } else {
            result[0] += -0.170516;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)290)) {
            result[0] += -0.31524354;
          } else {
            result[0] += 0.14018272;
          }
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)427636)) {
    result[0] += -0.40882564;
  } else {
    if ( (data[23].missing != -1) && (data[23].fvalue < (float)905270)) {
      if ( (data[4].missing != -1) && (data[4].fvalue < (float)31268)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)64)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)271990)) {
            result[0] += -0.0018056436;
          } else {
            result[0] += -0.5026311;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)11890)) {
            result[0] += 0.1347208;
          } else {
            result[0] += -0.0010031319;
          }
        }
      } else {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)355453)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)338769)) {
            result[0] += -0.07591677;
          } else {
            result[0] += -0.42868128;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)997)) {
            result[0] += -0.34709725;
          } else {
            result[0] += 0.22588873;
          }
        }
      }
    } else {
      if ( (data[24].missing != -1) && (data[24].fvalue < (float)11573)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)3668)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)313708)) {
            result[0] += -0.009547381;
          } else {
            result[0] += 0.32378206;
          }
        } else {
          result[0] += -0.41923133;
        }
      } else {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)215143)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)129539)) {
            result[0] += 0.39718243;
          } else {
            result[0] += 0.015302429;
          }
        } else {
          result[0] += -0.06153179;
        }
      }
    }
  }
  if ( (data[5].missing != -1) && (data[5].fvalue < (float)25520)) {
    if ( (data[5].missing != -1) && (data[5].fvalue < (float)65)) {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)104895)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)124)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)126611)) {
            result[0] += -0.17182665;
          } else {
            result[0] += 0.17197666;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)19527)) {
            result[0] += 0.13311026;
          } else {
            result[0] += -0.014207847;
          }
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)63)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)161269)) {
            result[0] += -0.44954324;
          } else {
            result[0] += -0.03036934;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)41760)) {
            result[0] += 0.20599262;
          } else {
            result[0] += -0.20029704;
          }
        }
      }
    } else {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)225273)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)33788)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)153428)) {
            result[0] += 0.18663435;
          } else {
            result[0] += -0.010889368;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)50839)) {
            result[0] += 0.09800182;
          } else {
            result[0] += -0.12252515;
          }
        }
      } else {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)103932)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)448600)) {
            result[0] += -0.39371058;
          } else {
            result[0] += 0.6856243;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)1551)) {
            result[0] += -0.35371932;
          } else {
            result[0] += 0.3953095;
          }
        }
      }
    }
  } else {
    if ( (data[11].missing != -1) && (data[11].fvalue < (float)42098)) {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)865)) {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)249221)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)194116)) {
            result[0] += -0.080386095;
          } else {
            result[0] += 0.36107862;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)468508)) {
            result[0] += -0.56923336;
          } else {
            result[0] += 0.04282876;
          }
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)403)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)202343)) {
            result[0] += 0.03756654;
          } else {
            result[0] += -0.59164757;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)95199)) {
            result[0] += 0.37136897;
          } else {
            result[0] += 0.03372007;
          }
        }
      }
    } else {
      if ( (data[7].missing != -1) && (data[7].fvalue < (float)148513)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)10720)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)322570)) {
            result[0] += -0.16549636;
          } else {
            result[0] += 0.29116875;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)12374)) {
            result[0] += -0.124528304;
          } else {
            result[0] += -0.39804107;
          }
        }
      } else {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)1178)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)2662)) {
            result[0] += -0.44524786;
          } else {
            result[0] += -0.0052015632;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)46658)) {
            result[0] += 0.34288952;
          } else {
            result[0] += 0.03834084;
          }
        }
      }
    }
  }
  if ( (data[11].missing != -1) && (data[11].fvalue < (float)445)) {
    if ( (data[12].missing != -1) && (data[12].fvalue < (float)243615)) {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)271414)) {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)281690)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)339375)) {
            result[0] += -0.030150054;
          } else {
            result[0] += 0.16602086;
          }
        } else {
          result[0] += -0.5295579;
        }
      } else {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)732931)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)1104277)) {
            result[0] += -0.48195758;
          } else {
            result[0] += 0.26674876;
          }
        } else {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)40983)) {
            result[0] += 0.36646074;
          } else {
            result[0] += -0.42542252;
          }
        }
      }
    } else {
      if ( (data[14].missing != -1) && (data[14].fvalue < (float)53072)) {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)292540)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)46914)) {
            result[0] += -0.4703035;
          } else {
            result[0] += -1.010568;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)23642)) {
            result[0] += -0.149794;
          } else {
            result[0] += 0.34223375;
          }
        }
      } else {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)125)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)61)) {
            result[0] += -0.07228641;
          } else {
            result[0] += -0.547182;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)9169)) {
            result[0] += 0.36773932;
          } else {
            result[0] += -0.1460471;
          }
        }
      }
    }
  } else {
    if ( (data[11].missing != -1) && (data[11].fvalue < (float)29629)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)763298)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)152488)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)110614)) {
            result[0] += -0.19968668;
          } else {
            result[0] += 0.35792077;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)587998)) {
            result[0] += 0.74380195;
          } else {
            result[0] += 0.053284407;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)118273)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)6008)) {
            result[0] += 0.27742034;
          } else {
            result[0] += 0.06650574;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)46262)) {
            result[0] += -0.21352902;
          } else {
            result[0] += 0.11737547;
          }
        }
      }
    } else {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)24120)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)125)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)58415)) {
            result[0] += -0.13187368;
          } else {
            result[0] += 0.33963883;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)63)) {
            result[0] += 0.0045342906;
          } else {
            result[0] += 0.14938977;
          }
        }
      } else {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)37054)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)103773)) {
            result[0] += 0.17902972;
          } else {
            result[0] += -0.3531519;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)546451)) {
            result[0] += -0.13293515;
          } else {
            result[0] += 0.17206214;
          }
        }
      }
    }
  }
  if ( (data[1].missing != -1) && (data[1].fvalue < (float)194804)) {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)688553)) {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)228313)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)187933)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)51624)) {
            result[0] += -0.08588523;
          } else {
            result[0] += -0.37401688;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)8188)) {
            result[0] += -0.1327144;
          } else {
            result[0] += 1.8706461;
          }
        }
      } else {
        result[0] += 0.7932452;
      }
    } else {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)281690)) {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)87965)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)1339)) {
            result[0] += -0.0005817079;
          } else {
            result[0] += 0.11757747;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)460217)) {
            result[0] += -0.037679736;
          } else {
            result[0] += 0.25464454;
          }
        }
      } else {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)975)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)89595)) {
            result[0] += -0.52686596;
          } else {
            result[0] += 0.32515046;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)851)) {
            result[0] += 0.15441434;
          } else {
            result[0] += -0.18714371;
          }
        }
      }
    }
  } else {
    if ( (data[6].missing != -1) && (data[6].fvalue < (float)997)) {
      if ( (data[4].missing != -1) && (data[4].fvalue < (float)393917)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)852)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)529)) {
            result[0] += -0.023383548;
          } else {
            result[0] += -0.59790677;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1192823)) {
            result[0] += 0.14818792;
          } else {
            result[0] += -0.35414216;
          }
        }
      } else {
        result[0] += 1.0485052;
      }
    } else {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)2666791)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)145023)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)312)) {
            result[0] += -0.13098148;
          } else {
            result[0] += 0.22075526;
          }
        } else {
          result[0] += -0.44701812;
        }
      } else {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)299623)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)79804)) {
            result[0] += -0.57323164;
          } else {
            result[0] += -0.20290998;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)3986725)) {
            result[0] += -0.31382146;
          } else {
            result[0] += 0.25948367;
          }
        }
      }
    }
  }
  if ( (data[24].missing != -1) && (data[24].fvalue < (float)200383)) {
    if ( (data[19].missing != -1) && (data[19].fvalue < (float)43084)) {
      if ( (data[13].missing != -1) && (data[13].fvalue < (float)102309)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)621)) {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)234625)) {
            result[0] += 0.025943;
          } else {
            result[0] += -0.36544678;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)293300)) {
            result[0] += 0.120304935;
          } else {
            result[0] += -0.14955465;
          }
        }
      } else {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)190390)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)266247)) {
            result[0] += -0.20425193;
          } else {
            result[0] += 0.06775161;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)254388)) {
            result[0] += 0.45060444;
          } else {
            result[0] += -0.09748276;
          }
        }
      }
    } else {
      if ( (data[6].missing != -1) && (data[6].fvalue < (float)13380)) {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)716)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)527528)) {
            result[0] += -0.057816744;
          } else {
            result[0] += 0.30196172;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)88670)) {
            result[0] += 0.041320834;
          } else {
            result[0] += 0.31178355;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)6757)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)392)) {
            result[0] += -0.1298215;
          } else {
            result[0] += 0.3505846;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)248536)) {
            result[0] += -0.2670828;
          } else {
            result[0] += -0.01783972;
          }
        }
      }
    }
  } else {
    if ( (data[18].missing != -1) && (data[18].fvalue < (float)107988)) {
      if ( (data[14].missing != -1) && (data[14].fvalue < (float)186447)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)66)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)214)) {
            result[0] += -0.4109307;
          } else {
            result[0] += -0.04555093;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)432309)) {
            result[0] += -0.5097387;
          } else {
            result[0] += 0.15865403;
          }
        }
      } else {
        if ( (data[8].missing != -1) && (data[8].fvalue < (float)54028)) {
          result[0] += -0.45697823;
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)213430)) {
            result[0] += 0.57293254;
          } else {
            result[0] += 0.014619867;
          }
        }
      }
    } else {
      if ( (data[22].missing != -1) && (data[22].fvalue < (float)61)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)188176)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)188589)) {
            result[0] += -0.65842557;
          } else {
            result[0] += -0.07837673;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1786394)) {
            result[0] += 0.54399294;
          } else {
            result[0] += -0.31804997;
          }
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)13877)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)151215)) {
            result[0] += 0.24486108;
          } else {
            result[0] += -0.23161633;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)732931)) {
            result[0] += -0.1777991;
          } else {
            result[0] += 0.33865473;
          }
        }
      }
    }
  }
  if ( (data[7].missing != -1) && (data[7].fvalue < (float)468884)) {
    if ( (data[9].missing != -1) && (data[9].fvalue < (float)20105)) {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)277203)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)1624)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)158758)) {
            result[0] += 0.023276322;
          } else {
            result[0] += -0.19272016;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)296)) {
            result[0] += 0.0127908755;
          } else {
            result[0] += 0.22467859;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)361420)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)61)) {
            result[0] += -0.18143621;
          } else {
            result[0] += -0.54390657;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)3475)) {
            result[0] += -0.41554528;
          } else {
            result[0] += 0.33864686;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)163698)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)20718)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)718)) {
            result[0] += -0.081533544;
          } else {
            result[0] += 0.13433525;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)260297)) {
            result[0] += -0.15792546;
          } else {
            result[0] += -0.46540633;
          }
        }
      } else {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)460)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)403)) {
            result[0] += -0.41579056;
          } else {
            result[0] += -0.019001883;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1963631)) {
            result[0] += 0.4533827;
          } else {
            result[0] += 0.09328371;
          }
        }
      }
    }
  } else {
    if ( (data[8].missing != -1) && (data[8].fvalue < (float)21315)) {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)197184)) {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)57164)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)8493)) {
            result[0] += -0.6234222;
          } else {
            result[0] += 0.06999844;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)128564)) {
            result[0] += -0.3722534;
          } else {
            result[0] += -1.1272779;
          }
        }
      } else {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)228313)) {
          result[0] += -0.25780895;
        } else {
          result[0] += 0.49240142;
        }
      }
    } else {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)3748636)) {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)128)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)97704)) {
            result[0] += -0.2578805;
          } else {
            result[0] += 0.50436246;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)127)) {
            result[0] += 0.11334874;
          } else {
            result[0] += 0.44479743;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)1505)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)17210)) {
            result[0] += -0.8681156;
          } else {
            result[0] += -0.09981461;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)1197)) {
            result[0] += -0.45945665;
          } else {
            result[0] += 0.19284682;
          }
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)427636)) {
    result[0] += -0.3962137;
  } else {
    if ( (data[21].missing != -1) && (data[21].fvalue < (float)992949)) {
      if ( (data[22].missing != -1) && (data[22].fvalue < (float)1442393)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)29112)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)593)) {
            result[0] += -0.015458825;
          } else {
            result[0] += 0.121527925;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)37035)) {
            result[0] += 0.07718074;
          } else {
            result[0] += -0.07132956;
          }
        }
      } else {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)80599)) {
          result[0] += 0.3994132;
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)89047)) {
            result[0] += -0.15473792;
          } else {
            result[0] += 0.22969793;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)7615)) {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)83672)) {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)161458)) {
            result[0] += 0.43610165;
          } else {
            result[0] += 0.13819115;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)45462)) {
            result[0] += 0.31166577;
          } else {
            result[0] += -0.17391786;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)70042)) {
          result[0] += 0.2840803;
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)369060)) {
            result[0] += -0.54616725;
          } else {
            result[0] += 0.112362325;
          }
        }
      }
    }
  }
  if ( (data[15].missing != -1) && (data[15].fvalue < (float)296894)) {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)763298)) {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)153634)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)152488)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)219318)) {
            result[0] += -0.14492975;
          } else {
            result[0] += 0.8042623;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)109686)) {
            result[0] += 0.3327257;
          } else {
            result[0] += -0.68830556;
          }
        }
      } else {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)77739)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)1514)) {
            result[0] += 0.44160435;
          } else {
            result[0] += 0.12023687;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)63)) {
            result[0] += 0.026649911;
          } else {
            result[0] += -0.6851602;
          }
        }
      }
    } else {
      if ( (data[2].missing != -1) && (data[2].fvalue < (float)88440)) {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)606)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)104832)) {
            result[0] += 0.035192408;
          } else {
            result[0] += -0.13985525;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)3954)) {
            result[0] += 0.15694197;
          } else {
            result[0] += 0.019462116;
          }
        }
      } else {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)669)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)64)) {
            result[0] += -0.5541622;
          } else {
            result[0] += -0.080071464;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)829)) {
            result[0] += -0.12059265;
          } else {
            result[0] += 0.058744878;
          }
        }
      }
    }
  } else {
    if ( (data[16].missing != -1) && (data[16].fvalue < (float)2158)) {
      if ( (data[1].missing != -1) && (data[1].fvalue < (float)16353)) {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)122308)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)121921)) {
            result[0] += -0.75959414;
          } else {
            result[0] += -0.37394726;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)97953)) {
            result[0] += -0.3128733;
          } else {
            result[0] += 0.21680093;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)65)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)139)) {
            result[0] += 0.37722892;
          } else {
            result[0] += 0.040744282;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)37048)) {
            result[0] += -0.5308985;
          } else {
            result[0] += 0.049885478;
          }
        }
      }
    } else {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)348721)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)136026)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)234572)) {
            result[0] += -0.0007933027;
          } else {
            result[0] += -0.60012037;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)315927)) {
            result[0] += -0.57901716;
          } else {
            result[0] += 0.048191678;
          }
        }
      } else {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)40347)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)6120)) {
            result[0] += 0.45239025;
          } else {
            result[0] += -0.5749251;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)80139)) {
            result[0] += 0.4076975;
          } else {
            result[0] += -0.087741084;
          }
        }
      }
    }
  }
  if ( (data[14].missing != -1) && (data[14].fvalue < (float)25434)) {
    if ( (data[19].missing != -1) && (data[19].fvalue < (float)271414)) {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)137666)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)179754)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)318979)) {
            result[0] += 0.03291874;
          } else {
            result[0] += -0.5632097;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)104895)) {
            result[0] += 0.103407435;
          } else {
            result[0] += 0.586742;
          }
        }
      } else {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)293)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)209)) {
            result[0] += -0.5745155;
          } else {
            result[0] += -0.16615297;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)64348)) {
            result[0] += 0.08724513;
          } else {
            result[0] += -0.31057903;
          }
        }
      }
    } else {
      if ( (data[18].missing != -1) && (data[18].fvalue < (float)559451)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)718108)) {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)466136)) {
            result[0] += -0.43005696;
          } else {
            result[0] += 0.10520691;
          }
        } else {
          result[0] += 0.37996125;
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)178618)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)655)) {
            result[0] += 0.29650837;
          } else {
            result[0] += -0.27187082;
          }
        } else {
          result[0] += -0.5637154;
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)619661)) {
      result[0] += -0.5031013;
    } else {
      if ( (data[1].missing != -1) && (data[1].fvalue < (float)244259)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)444289)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)55356)) {
            result[0] += 0.025512928;
          } else {
            result[0] += -0.11649763;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)2642178)) {
            result[0] += 0.44743943;
          } else {
            result[0] += 0.05911232;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)201516)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)229720)) {
            result[0] += -0.48216096;
          } else {
            result[0] += 0.1365381;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)131251)) {
            result[0] += -0.27544734;
          } else {
            result[0] += 0.33612233;
          }
        }
      }
    }
  }
  if ( (data[1].missing != -1) && (data[1].fvalue < (float)83455)) {
    if ( (data[0].missing != -1) && (data[0].fvalue < (float)280914)) {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)812)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)179757)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)138264)) {
            result[0] += -0.058078386;
          } else {
            result[0] += 0.06898781;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)180374)) {
            result[0] += 0.11419771;
          } else {
            result[0] += -0.4708405;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)44355)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)136026)) {
            result[0] += 0.12315088;
          } else {
            result[0] += -0.07761656;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)131251)) {
            result[0] += -0.047312483;
          } else {
            result[0] += 0.11267897;
          }
        }
      }
    } else {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)204)) {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)245906)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)154042)) {
            result[0] += -0.58230084;
          } else {
            result[0] += 0.11607613;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)629)) {
            result[0] += 0.2730359;
          } else {
            result[0] += -0.23977545;
          }
        }
      } else {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)30389)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)172390)) {
            result[0] += -0.55801314;
          } else {
            result[0] += 0.10200781;
          }
        } else {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)343906)) {
            result[0] += -0.3772193;
          } else {
            result[0] += 0.117241524;
          }
        }
      }
    }
  } else {
    if ( (data[4].missing != -1) && (data[4].fvalue < (float)44183)) {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)38576)) {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)82398)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)37838)) {
            result[0] += 0.14278544;
          } else {
            result[0] += -0.10158459;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)97440)) {
            result[0] += -0.44171435;
          } else {
            result[0] += 0.0340969;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1950077)) {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)313410)) {
            result[0] += -0.3249964;
          } else {
            result[0] += 0.5048062;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)83241)) {
            result[0] += -0.08641406;
          } else {
            result[0] += 0.22456913;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)19967)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)870403)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)126)) {
            result[0] += -0.31548962;
          } else {
            result[0] += 1.0397666;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)86862)) {
            result[0] += -0.3313658;
          } else {
            result[0] += 0.32667875;
          }
        }
      } else {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)189268)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)393917)) {
            result[0] += -0.34039414;
          } else {
            result[0] += 0.4584805;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)757)) {
            result[0] += -0.21576989;
          } else {
            result[0] += 0.0890883;
          }
        }
      }
    }
  }
  if ( (data[14].missing != -1) && (data[14].fvalue < (float)99025)) {
    if ( (data[19].missing != -1) && (data[19].fvalue < (float)94308)) {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)53044)) {
        if ( (data[8].missing != -1) && (data[8].fvalue < (float)1307)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)268417)) {
            result[0] += 0.025621204;
          } else {
            result[0] += -0.5194297;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)690647)) {
            result[0] += 0.12740543;
          } else {
            result[0] += 1.4645767;
          }
        }
      } else {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)273)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)104469)) {
            result[0] += -0.069102176;
          } else {
            result[0] += -0.3025746;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)16053)) {
            result[0] += 0.13086998;
          } else {
            result[0] += -0.07692479;
          }
        }
      }
    } else {
      if ( (data[18].missing != -1) && (data[18].fvalue < (float)292666)) {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)92500)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)369060)) {
            result[0] += -0.2584878;
          } else {
            result[0] += 0.16309302;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)336)) {
            result[0] += -0.48864633;
          } else {
            result[0] += 0.1121244;
          }
        }
      } else {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)2281)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)103032)) {
            result[0] += -0.09883852;
          } else {
            result[0] += -0.5630015;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)70083)) {
            result[0] += 0.23900981;
          } else {
            result[0] += -0.13575733;
          }
        }
      }
    }
  } else {
    if ( (data[8].missing != -1) && (data[8].fvalue < (float)13948)) {
      if ( (data[14].missing != -1) && (data[14].fvalue < (float)154969)) {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)14800)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)77140)) {
            result[0] += -0.06486405;
          } else {
            result[0] += 0.36792856;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)199267)) {
            result[0] += -0.42468005;
          } else {
            result[0] += 0.04213854;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)632797)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)406)) {
            result[0] += -0.45555574;
          } else {
            result[0] += -0.24292468;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)32326)) {
            result[0] += -0.61265707;
          } else {
            result[0] += 0.25727236;
          }
        }
      }
    } else {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)509)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)73092)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)105979)) {
            result[0] += 0.18848073;
          } else {
            result[0] += -0.5240335;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)19708)) {
            result[0] += 0.3945431;
          } else {
            result[0] += -0.3315779;
          }
        }
      } else {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)390)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)46507)) {
            result[0] += 0.04461029;
          } else {
            result[0] += -0.56648046;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)2377471)) {
            result[0] += 0.36670914;
          } else {
            result[0] += 0.0822147;
          }
        }
      }
    }
  }
  if ( (data[16].missing != -1) && (data[16].fvalue < (float)534)) {
    if ( (data[17].missing != -1) && (data[17].fvalue < (float)275768)) {
      if ( (data[21].missing != -1) && (data[21].fvalue < (float)123538)) {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)144203)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)467)) {
            result[0] += -0.10664197;
          } else {
            result[0] += 0.040503737;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)150441)) {
            result[0] += 0.2849109;
          } else {
            result[0] += -0.058818143;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)24077)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)5277)) {
            result[0] += 0.33983943;
          } else {
            result[0] += -0.2371627;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)77888)) {
            result[0] += -0.00012165508;
          } else {
            result[0] += -0.36349005;
          }
        }
      }
    } else {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)201)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)61)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)856123)) {
            result[0] += -0.5086579;
          } else {
            result[0] += 0.32844326;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)61)) {
            result[0] += -0.17815685;
          } else {
            result[0] += 0.4709521;
          }
        }
      } else {
        if ( (data[14].missing != -1) && (data[14].fvalue < (float)3170)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)49591)) {
            result[0] += -1.2151192;
          } else {
            result[0] += -0.5292148;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)210669)) {
            result[0] += -0.53693694;
          } else {
            result[0] += 0.072011285;
          }
        }
      }
    }
  } else {
    if ( (data[16].missing != -1) && (data[16].fvalue < (float)14351)) {
      if ( (data[17].missing != -1) && (data[17].fvalue < (float)1704)) {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)273)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)2683)) {
            result[0] += -0.32234833;
          } else {
            result[0] += 0.07448201;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)9940)) {
            result[0] += 0.30094978;
          } else {
            result[0] += 0.034744248;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)309378)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)12280)) {
            result[0] += 0.19365178;
          } else {
            result[0] += 0.48821363;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)4804)) {
            result[0] += -0.67868584;
          } else {
            result[0] += 0.052744843;
          }
        }
      }
    } else {
      if ( (data[10].missing != -1) && (data[10].fvalue < (float)34842)) {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)44081)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)406)) {
            result[0] += 0.027547255;
          } else {
            result[0] += 0.18868527;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)157978)) {
            result[0] += -0.19390787;
          } else {
            result[0] += 0.0624444;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)144037)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)161529)) {
            result[0] += -0.06589386;
          } else {
            result[0] += -0.29002777;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)37397)) {
            result[0] += 0.18836637;
          } else {
            result[0] += -0.057198126;
          }
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)427636)) {
    result[0] += -0.3869052;
  } else {
    if ( (data[4].missing != -1) && (data[4].fvalue < (float)84015)) {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)271990)) {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)16740)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)90579)) {
            result[0] += 0.07463326;
          } else {
            result[0] += -0.02293175;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)247317)) {
            result[0] += -0.02909188;
          } else {
            result[0] += 0.09909821;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)79180)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)63)) {
            result[0] += -0.22234054;
          } else {
            result[0] += -0.7365546;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)2655)) {
            result[0] += -0.33519432;
          } else {
            result[0] += 0.102941275;
          }
        }
      }
    } else {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)103033)) {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)187022)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)99065)) {
            result[0] += -0.012767183;
          } else {
            result[0] += 0.2310891;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)404783)) {
            result[0] += -0.38188595;
          } else {
            result[0] += 0.12930633;
          }
        }
      } else {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)277203)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)579422)) {
            result[0] += -0.4012621;
          } else {
            result[0] += 0.22502032;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)470)) {
            result[0] += -0.41071185;
          } else {
            result[0] += 0.059529226;
          }
        }
      }
    }
  }
  if ( (data[7].missing != -1) && (data[7].fvalue < (float)412841)) {
    if ( (data[5].missing != -1) && (data[5].fvalue < (float)1006791)) {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)49591)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)311)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)162666)) {
            result[0] += 0.0021737488;
          } else {
            result[0] += -0.2599567;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)210365)) {
            result[0] += 0.050769955;
          } else {
            result[0] += 0.24248381;
          }
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)72190)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)61)) {
            result[0] += 0.10267847;
          } else {
            result[0] += -0.06893627;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)289)) {
            result[0] += -0.35130745;
          } else {
            result[0] += -0.054188948;
          }
        }
      }
    } else {
      if ( (data[9].missing != -1) && (data[9].fvalue < (float)7868)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)1481)) {
          result[0] += 0.11270523;
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)4300312)) {
            result[0] += 0.6942651;
          } else {
            result[0] += 0.3770896;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)91105)) {
          result[0] += -0.21745399;
        } else {
          result[0] += 0.20680666;
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)3986725)) {
      if ( (data[13].missing != -1) && (data[13].fvalue < (float)1874)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)287)) {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)313410)) {
            result[0] += -0.53260034;
          } else {
            result[0] += 0.07584637;
          }
        } else {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)13611)) {
            result[0] += 0.2705852;
          } else {
            result[0] += -0.4034358;
          }
        }
      } else {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)207879)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)212)) {
            result[0] += 0.05948148;
          } else {
            result[0] += 0.36495623;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)4610)) {
            result[0] += -0.57252705;
          } else {
            result[0] += 0.26322734;
          }
        }
      }
    } else {
      if ( (data[13].missing != -1) && (data[13].fvalue < (float)99342)) {
        if ( (data[7].missing != -1) && (data[7].fvalue < (float)1185063)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)84155)) {
            result[0] += -0.59094787;
          } else {
            result[0] += -0.032668464;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)174298)) {
            result[0] += 0.35200936;
          } else {
            result[0] += -0.30678394;
          }
        }
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)282)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)100601)) {
            result[0] += -0.042658936;
          } else {
            result[0] += -0.6846313;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)68653)) {
            result[0] += -0.2104019;
          } else {
            result[0] += 0.27513337;
          }
        }
      }
    }
  }
  if ( (data[4].missing != -1) && (data[4].fvalue < (float)9931)) {
    if ( (data[4].missing != -1) && (data[4].fvalue < (float)7861)) {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)1352)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)196075)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)169201)) {
            result[0] += -0.055296626;
          } else {
            result[0] += 0.114053;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)199)) {
            result[0] += -0.23928352;
          } else {
            result[0] += 0.1267405;
          }
        }
      } else {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)61601)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)21569)) {
            result[0] += 0.22626708;
          } else {
            result[0] += 0.011830209;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)1033)) {
            result[0] += -0.11018401;
          } else {
            result[0] += 0.15205957;
          }
        }
      }
    } else {
      if ( (data[16].missing != -1) && (data[16].fvalue < (float)194259)) {
        if ( (data[3].missing != -1) && (data[3].fvalue < (float)201)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)62)) {
            result[0] += 0.708006;
          } else {
            result[0] += 0.22219227;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)13948)) {
            result[0] += -0.42686296;
          } else {
            result[0] += 0.24846898;
          }
        }
      } else {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)119769)) {
          result[0] += -0.58335316;
        } else {
          result[0] += 0.011714313;
        }
      }
    }
  } else {
    if ( (data[7].missing != -1) && (data[7].fvalue < (float)193301)) {
      if ( (data[7].missing != -1) && (data[7].fvalue < (float)44605)) {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)284)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)113343)) {
            result[0] += 0.12685317;
          } else {
            result[0] += -0.40142608;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)60105)) {
            result[0] += -0.28020743;
          } else {
            result[0] += -0.035498746;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1540838)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)274744)) {
            result[0] += -0.3309847;
          } else {
            result[0] += 0.42010623;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)33670)) {
            result[0] += 0.05374291;
          } else {
            result[0] += -0.26914078;
          }
        }
      }
    } else {
      if ( (data[6].missing != -1) && (data[6].fvalue < (float)68085)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)321761)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)245548)) {
            result[0] += 0.31251064;
          } else {
            result[0] += -0.29614922;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)58335)) {
            result[0] += 0.2878469;
          } else {
            result[0] += -0.48637486;
          }
        }
      } else {
        if ( (data[13].missing != -1) && (data[13].fvalue < (float)387)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)109686)) {
            result[0] += -0.4693968;
          } else {
            result[0] += 0.1466807;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)10961)) {
            result[0] += 0.3058382;
          } else {
            result[0] += -0.01860459;
          }
        }
      }
    }
  }
  if ( (data[8].missing != -1) && (data[8].fvalue < (float)711590)) {
    if ( (data[9].missing != -1) && (data[9].fvalue < (float)103132)) {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)80908)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)17441)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)298574)) {
            result[0] += -0.00333189;
          } else {
            result[0] += 0.13413946;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)29172)) {
            result[0] += -0.36351338;
          } else {
            result[0] += -0.08838872;
          }
        }
      } else {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)416)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)270)) {
            result[0] += -0.27369207;
          } else {
            result[0] += 0.083389156;
          }
        } else {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)213472)) {
            result[0] += 0.14545423;
          } else {
            result[0] += -0.1748883;
          }
        }
      }
    } else {
      if ( (data[3].missing != -1) && (data[3].fvalue < (float)167157)) {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)204)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)2591)) {
            result[0] += -0.080106534;
          } else {
            result[0] += -0.37849718;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)81523)) {
            result[0] += 0.030751187;
          } else {
            result[0] += -0.32062685;
          }
        }
      } else {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)63)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)228081)) {
            result[0] += -0.4108385;
          } else {
            result[0] += 0.14547342;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)55513)) {
            result[0] += 0.27372774;
          } else {
            result[0] += -0.005358948;
          }
        }
      }
    }
  } else {
    if ( (data[6].missing != -1) && (data[6].fvalue < (float)663)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)4427190)) {
        result[0] += -0.6671201;
      } else {
        result[0] += -0.13646547;
      }
    } else {
      if ( (data[13].missing != -1) && (data[13].fvalue < (float)6650)) {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)6447)) {
          result[0] += -0.5867508;
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)15518)) {
            result[0] += 0.2783408;
          } else {
            result[0] += -0.2893121;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)3828286)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)277203)) {
            result[0] += 0.5604101;
          } else {
            result[0] += -0.15880655;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)56320)) {
            result[0] += -0.31811246;
          } else {
            result[0] += 0.28134152;
          }
        }
      }
    }
  }
  if ( (data[21].missing != -1) && (data[21].fvalue < (float)25231)) {
    if ( (data[16].missing != -1) && (data[16].fvalue < (float)211469)) {
      if ( (data[20].missing != -1) && (data[20].fvalue < (float)1028)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)358)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)296814)) {
            result[0] += 0.034942307;
          } else {
            result[0] += -0.40273434;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)125260)) {
            result[0] += -0.26806554;
          } else {
            result[0] += 0.05924288;
          }
        }
      } else {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)81523)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)168238)) {
            result[0] += 0.0029478027;
          } else {
            result[0] += 0.23788185;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)213820)) {
            result[0] += 0.26199055;
          } else {
            result[0] += -0.03293506;
          }
        }
      }
    } else {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)229)) {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)2013)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)795368)) {
            result[0] += -0.7173833;
          } else {
            result[0] += -0.15947157;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)147934)) {
            result[0] += -0.26862735;
          } else {
            result[0] += 0.14339605;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1158883)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)322)) {
            result[0] += 0.6585603;
          } else {
            result[0] += -0.25013047;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)1740)) {
            result[0] += -0.38787255;
          } else {
            result[0] += 0.05727889;
          }
        }
      }
    }
  } else {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)619661)) {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)287)) {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)586)) {
          result[0] += -0.5950633;
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)9940)) {
            result[0] += 0.33299962;
          } else {
            result[0] += -0.20836993;
          }
        }
      } else {
        result[0] += -0.54462856;
      }
    } else {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)134848)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)653)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)205948)) {
            result[0] += -0.018799575;
          } else {
            result[0] += -0.44757673;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)98505)) {
            result[0] += 0.046494905;
          } else {
            result[0] += -0.08069734;
          }
        }
      } else {
        if ( (data[18].missing != -1) && (data[18].fvalue < (float)86474)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)149757)) {
            result[0] += -0.019933296;
          } else {
            result[0] += 0.45436946;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)298574)) {
            result[0] += -0.37972972;
          } else {
            result[0] += -0.051708486;
          }
        }
      }
    }
  }
  if ( (data[10].missing != -1) && (data[10].fvalue < (float)281690)) {
    if ( (data[10].missing != -1) && (data[10].fvalue < (float)223623)) {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)369162)) {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)536089)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)182261)) {
            result[0] += -0.008055327;
          } else {
            result[0] += 0.067767374;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)255306)) {
            result[0] += -0.58310574;
          } else {
            result[0] += -0.05510796;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)323435)) {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)614457)) {
            result[0] += -0.40733424;
          } else {
            result[0] += 0.42078042;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)118722)) {
            result[0] += -0.3892494;
          } else {
            result[0] += 0.5198149;
          }
        }
      }
    } else {
      if ( (data[15].missing != -1) && (data[15].fvalue < (float)94101)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1027433)) {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)129018)) {
            result[0] += 0.14694956;
          } else {
            result[0] += 0.92324793;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1751435)) {
            result[0] += -0.35226902;
          } else {
            result[0] += 0.034242578;
          }
        }
      } else {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)104923)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)62)) {
            result[0] += 1.7401876;
          } else {
            result[0] += 0.24789205;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)183737)) {
            result[0] += 0.30370626;
          } else {
            result[0] += -0.23680137;
          }
        }
      }
    }
  } else {
    if ( (data[21].missing != -1) && (data[21].fvalue < (float)3229)) {
      if ( (data[7].missing != -1) && (data[7].fvalue < (float)292296)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1682578)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)215655)) {
            result[0] += -0.40392253;
          } else {
            result[0] += 0.32478318;
          }
        } else {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)1006791)) {
            result[0] += -0.5458426;
          } else {
            result[0] += 0.06700338;
          }
        }
      } else {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)108513)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)206)) {
            result[0] += -0.5293302;
          } else {
            result[0] += 0.048907425;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)62937)) {
            result[0] += 0.39771944;
          } else {
            result[0] += -0.32880104;
          }
        }
      }
    } else {
      if ( (data[11].missing != -1) && (data[11].fvalue < (float)57492)) {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)28322)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)97420)) {
            result[0] += -0.37361988;
          } else {
            result[0] += 0.15233324;
          }
        } else {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)207879)) {
            result[0] += -0.5887862;
          } else {
            result[0] += 0.00861778;
          }
        }
      } else {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)10720)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1166885)) {
            result[0] += 1.0644802;
          } else {
            result[0] += 0.17653315;
          }
        } else {
          if ( (data[7].missing != -1) && (data[7].fvalue < (float)87822)) {
            result[0] += -0.3653652;
          } else {
            result[0] += 0.07120114;
          }
        }
      }
    }
  }
  if ( (data[13].missing != -1) && (data[13].fvalue < (float)28997)) {
    if ( (data[13].missing != -1) && (data[13].fvalue < (float)757)) {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)243615)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)251242)) {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)18133)) {
            result[0] += 0.0321037;
          } else {
            result[0] += -0.05914206;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)187452)) {
            result[0] += -0.40931955;
          } else {
            result[0] += 0.37584168;
          }
        }
      } else {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)8560)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)56077)) {
            result[0] += -0.76105154;
          } else {
            result[0] += -0.30337676;
          }
        } else {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)120176)) {
            result[0] += 0.14739873;
          } else {
            result[0] += -0.5630347;
          }
        }
      }
    } else {
      if ( (data[14].missing != -1) && (data[14].fvalue < (float)77408)) {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)630607)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)57932)) {
            result[0] += -0.55191433;
          } else {
            result[0] += 0.050354708;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)161096)) {
            result[0] += 0.09683265;
          } else {
            result[0] += -0.11963695;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)94644)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)107561)) {
            result[0] += 0.50740755;
          } else {
            result[0] += -0.30933937;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)198820)) {
            result[0] += -0.38581666;
          } else {
            result[0] += 0.20380251;
          }
        }
      }
    }
  } else {
    if ( (data[18].missing != -1) && (data[18].fvalue < (float)104273)) {
      if ( (data[8].missing != -1) && (data[8].fvalue < (float)2666)) {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)15956)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)46507)) {
            result[0] += -0.03368951;
          } else {
            result[0] += -0.28237757;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)370)) {
            result[0] += -0.42248917;
          } else {
            result[0] += -0.1819348;
          }
        }
      } else {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)128846)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)296908)) {
            result[0] += -0.027555916;
          } else {
            result[0] += -0.29725745;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)2704)) {
            result[0] += -0.12507409;
          } else {
            result[0] += 0.2546969;
          }
        }
      }
    } else {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)865)) {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)1571)) {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)257229)) {
            result[0] += -0.30722487;
          } else {
            result[0] += -0.7962987;
          }
        } else {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)4789)) {
            result[0] += 0.17628099;
          } else {
            result[0] += -0.3635256;
          }
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)197919)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)108425)) {
            result[0] += 0.16406557;
          } else {
            result[0] += -0.04335719;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)66510)) {
            result[0] += -0.5535063;
          } else {
            result[0] += 0.028901849;
          }
        }
      }
    }
  }
  if ( (data[18].missing != -1) && (data[18].fvalue < (float)430)) {
    if ( (data[23].missing != -1) && (data[23].fvalue < (float)115552)) {
      if ( (data[16].missing != -1) && (data[16].fvalue < (float)340974)) {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)59456)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)89443)) {
            result[0] += -0.057997357;
          } else {
            result[0] += 0.23144105;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)94361)) {
            result[0] += 0.13576756;
          } else {
            result[0] += -0.09359517;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)10602)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)126)) {
            result[0] += -0.8427083;
          } else {
            result[0] += -0.40497947;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)35945)) {
            result[0] += -0.4729174;
          } else {
            result[0] += 0.07869943;
          }
        }
      }
    } else {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)205515)) {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)271305)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)37035)) {
            result[0] += -0.031542137;
          } else {
            result[0] += -0.4307897;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)136862)) {
            result[0] += 0.51391876;
          } else {
            result[0] += -0.29621866;
          }
        }
      } else {
        if ( (data[25].missing != -1) && (data[25].fvalue < (float)1571133)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)124)) {
            result[0] += -0.51942563;
          } else {
            result[0] += 0.25148168;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)688645)) {
            result[0] += -0.44139242;
          } else {
            result[0] += 0.16145341;
          }
        }
      }
    }
  } else {
    if ( (data[18].missing != -1) && (data[18].fvalue < (float)19447)) {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)9951)) {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)142424)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)101029)) {
            result[0] += 0.15091437;
          } else {
            result[0] += 0.39883322;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)140)) {
            result[0] += -0.53071713;
          } else {
            result[0] += 0.0744217;
          }
        }
      } else {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)91622)) {
          if ( (data[0].missing != -1) && (data[0].fvalue < (float)173590)) {
            result[0] += -0.17728908;
          } else {
            result[0] += 0.112678364;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)162214)) {
            result[0] += 0.24656187;
          } else {
            result[0] += -0.35356224;
          }
        }
      }
    } else {
      if ( (data[17].missing != -1) && (data[17].fvalue < (float)297491)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)44375)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)164834)) {
            result[0] += 0.09706848;
          } else {
            result[0] += -0.17606115;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)168779)) {
            result[0] += -0.10033035;
          } else {
            result[0] += 0.09983944;
          }
        }
      } else {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)130)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)28374)) {
            result[0] += -0.58735174;
          } else {
            result[0] += -0.124061696;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1238429)) {
            result[0] += 0.689053;
          } else {
            result[0] += 0.11860508;
          }
        }
      }
    }
  }
  if ( (data[22].missing != -1) && (data[22].fvalue < (float)138264)) {
    if ( (data[22].missing != -1) && (data[22].fvalue < (float)103985)) {
      if ( (data[21].missing != -1) && (data[21].fvalue < (float)113580)) {
        if ( (data[17].missing != -1) && (data[17].fvalue < (float)112333)) {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)54701)) {
            result[0] += 0.025044708;
          } else {
            result[0] += -0.06748606;
          }
        } else {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)9232)) {
            result[0] += -0.03723022;
          } else {
            result[0] += -0.2219433;
          }
        }
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)77888)) {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)135548)) {
            result[0] += 0.25746602;
          } else {
            result[0] += -0.2160003;
          }
        } else {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)97865)) {
            result[0] += -0.07846288;
          } else {
            result[0] += 0.21401754;
          }
        }
      }
    } else {
      if ( (data[24].missing != -1) && (data[24].fvalue < (float)232374)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)3010)) {
          if ( (data[8].missing != -1) && (data[8].fvalue < (float)15076)) {
            result[0] += 0.089014046;
          } else {
            result[0] += -0.31279135;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)94527)) {
            result[0] += -0.3841566;
          } else {
            result[0] += -0.083172865;
          }
        }
      } else {
        if ( (data[12].missing != -1) && (data[12].fvalue < (float)41004)) {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)205)) {
            result[0] += 0.37330198;
          } else {
            result[0] += -0.30131945;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)594)) {
            result[0] += -0.3382524;
          } else {
            result[0] += 0.08361286;
          }
        }
      }
    }
  } else {
    if ( (data[21].missing != -1) && (data[21].fvalue < (float)99513)) {
      if ( (data[19].missing != -1) && (data[19].fvalue < (float)509)) {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)143813)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)62)) {
            result[0] += -0.11347618;
          } else {
            result[0] += 0.19206493;
          }
        } else {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)112333)) {
            result[0] += -0.6658048;
          } else {
            result[0] += -0.034423303;
          }
        }
      } else {
        if ( (data[22].missing != -1) && (data[22].fvalue < (float)206375)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)88326)) {
            result[0] += 0.43544984;
          } else {
            result[0] += 0.17645434;
          }
        } else {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)43605)) {
            result[0] += 0.17304705;
          } else {
            result[0] += -0.0969663;
          }
        }
      }
    } else {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)782069)) {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)1680)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)270622)) {
            result[0] += -0.6980632;
          } else {
            result[0] += 0.03432314;
          }
        } else {
          result[0] += 0.0713413;
        }
      } else {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)198)) {
          if ( (data[23].missing != -1) && (data[23].fvalue < (float)71021)) {
            result[0] += 0.16063568;
          } else {
            result[0] += -0.02025134;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)206375)) {
            result[0] += -0.29131076;
          } else {
            result[0] += -0.0513802;
          }
        }
      }
    }
  }
  if ( (data[1].missing != -1) && (data[1].fvalue < (float)175669)) {
    if ( (data[25].missing != -1) && (data[25].fvalue < (float)8292884)) {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)442545)) {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)94101)) {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)230255)) {
            result[0] += 0.03310734;
          } else {
            result[0] += -0.087674595;
          }
        } else {
          if ( (data[20].missing != -1) && (data[20].fvalue < (float)129241)) {
            result[0] += -0.077851236;
          } else {
            result[0] += 0.049851283;
          }
        }
      } else {
        if ( (data[0].missing != -1) && (data[0].fvalue < (float)881147)) {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)6778337)) {
            result[0] += -0.51199484;
          } else {
            result[0] += 0.03033848;
          }
        } else {
          if ( (data[15].missing != -1) && (data[15].fvalue < (float)101359)) {
            result[0] += -0.33873874;
          } else {
            result[0] += 0.43067536;
          }
        }
      }
    } else {
      if ( (data[7].missing != -1) && (data[7].fvalue < (float)61)) {
        result[0] += -0.06924743;
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)751)) {
          result[0] += 0.064229965;
        } else {
          if ( (data[1].missing != -1) && (data[1].fvalue < (float)130465)) {
            result[0] += 0.38961223;
          } else {
            result[0] += 0.08058776;
          }
        }
      }
    }
  } else {
    if ( (data[6].missing != -1) && (data[6].fvalue < (float)145578)) {
      if ( (data[5].missing != -1) && (data[5].fvalue < (float)169621)) {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)63)) {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)579422)) {
            result[0] += -0.49000525;
          } else {
            result[0] += 0.076752305;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)21113)) {
            result[0] += -0.033742268;
          } else {
            result[0] += -0.48661017;
          }
        }
      } else {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)33633)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)754)) {
            result[0] += 0.027949518;
          } else {
            result[0] += -0.6077366;
          }
        } else {
          if ( (data[2].missing != -1) && (data[2].fvalue < (float)92038)) {
            result[0] += -0.29763308;
          } else {
            result[0] += 0.49503762;
          }
        }
      }
    } else {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)1322157)) {
        if ( (data[1].missing != -1) && (data[1].fvalue < (float)279750)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)276)) {
            result[0] += 1.015745;
          } else {
            result[0] += 0.21074656;
          }
        } else {
          result[0] += -0.32987568;
        }
      } else {
        if ( (data[2].missing != -1) && (data[2].fvalue < (float)10199)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)345641)) {
            result[0] += -0.3892437;
          } else {
            result[0] += 0.41171518;
          }
        } else {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)199281)) {
            result[0] += -0.33508167;
          } else {
            result[0] += 0.20256448;
          }
        }
      }
    }
  }
  if ( (data[22].missing != -1) && (data[22].fvalue < (float)984980)) {
    if ( (data[23].missing != -1) && (data[23].fvalue < (float)905270)) {
      if ( (data[1].missing != -1) && (data[1].fvalue < (float)698727)) {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)250568)) {
          if ( (data[19].missing != -1) && (data[19].fvalue < (float)63)) {
            result[0] += -0.024815328;
          } else {
            result[0] += 0.026592929;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1183572)) {
            result[0] += 0.15898137;
          } else {
            result[0] += -0.12972842;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)194259)) {
          result[0] += -0.509454;
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)179754)) {
            result[0] += -0.30696324;
          } else {
            result[0] += 0.2310235;
          }
        }
      }
    } else {
      if ( (data[24].missing != -1) && (data[24].fvalue < (float)11573)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)1522470)) {
          result[0] += -0.48159567;
        } else {
          result[0] += 0.21268247;
        }
      } else {
        if ( (data[19].missing != -1) && (data[19].fvalue < (float)238250)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)1413)) {
            result[0] += 0.056774992;
          } else {
            result[0] += 0.41094002;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)197078)) {
            result[0] += -0.4607453;
          } else {
            result[0] += 0.25510672;
          }
        }
      }
    }
  } else {
    if ( (data[20].missing != -1) && (data[20].fvalue < (float)1419)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)2780105)) {
        result[0] += 0.25074658;
      } else {
        result[0] += -0.6115419;
      }
    } else {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)11277)) {
        result[0] += -0.2789302;
      } else {
        if ( (data[15].missing != -1) && (data[15].fvalue < (float)279468)) {
          if ( (data[6].missing != -1) && (data[6].fvalue < (float)125042)) {
            result[0] += 0.3780664;
          } else {
            result[0] += -0.091488875;
          }
        } else {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)254388)) {
            result[0] += -0.44161436;
          } else {
            result[0] += 0.20825326;
          }
        }
      }
    }
  }
  if ( (data[25].missing != -1) && (data[25].fvalue < (float)964937)) {
    if ( (data[2].missing != -1) && (data[2].fvalue < (float)194715)) {
      if ( (data[12].missing != -1) && (data[12].fvalue < (float)184743)) {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)157232)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)212264)) {
            result[0] += -0.109893076;
          } else {
            result[0] += 0.18650892;
          }
        } else {
          if ( (data[24].missing != -1) && (data[24].fvalue < (float)23595)) {
            result[0] += -0.0010160034;
          } else {
            result[0] += 0.2571725;
          }
        }
      } else {
        if ( (data[20].missing != -1) && (data[20].fvalue < (float)287)) {
          if ( (data[14].missing != -1) && (data[14].fvalue < (float)5611)) {
            result[0] += 0.12902;
          } else {
            result[0] += 0.908587;
          }
        } else {
          result[0] += -0.58723366;
        }
      }
    } else {
      if ( (data[0].missing != -1) && (data[0].fvalue < (float)1020)) {
        if ( (data[9].missing != -1) && (data[9].fvalue < (float)94571)) {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)158455)) {
            result[0] += -0.44760004;
          } else {
            result[0] += 0.35944122;
          }
        } else {
          result[0] += 0.85938466;
        }
      } else {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)43168)) {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)61)) {
            result[0] += 0.5011693;
          } else {
            result[0] += -0.20589946;
          }
        } else {
          if ( (data[3].missing != -1) && (data[3].fvalue < (float)4596)) {
            result[0] += 0.039313678;
          } else {
            result[0] += 1.3094858;
          }
        }
      }
    }
  } else {
    if ( (data[16].missing != -1) && (data[16].fvalue < (float)452)) {
      if ( (data[25].missing != -1) && (data[25].fvalue < (float)2377471)) {
        if ( (data[5].missing != -1) && (data[5].fvalue < (float)179159)) {
          if ( (data[4].missing != -1) && (data[4].fvalue < (float)177246)) {
            result[0] += -0.051993605;
          } else {
            result[0] += 0.21945071;
          }
        } else {
          if ( (data[25].missing != -1) && (data[25].fvalue < (float)1009506)) {
            result[0] += 1.072248;
          } else {
            result[0] += 0.11266928;
          }
        }
      } else {
        if ( (data[16].missing != -1) && (data[16].fvalue < (float)61)) {
          if ( (data[11].missing != -1) && (data[11].fvalue < (float)42098)) {
            result[0] += -0.03296469;
          } else {
            result[0] += -0.28151596;
          }
        } else {
          if ( (data[13].missing != -1) && (data[13].fvalue < (float)117453)) {
            result[0] += -0.6083318;
          } else {
            result[0] += -0.28849646;
          }
        }
      }
    } else {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)32234)) {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)2031)) {
          if ( (data[9].missing != -1) && (data[9].fvalue < (float)330)) {
            result[0] += 0.098972194;
          } else {
            result[0] += -0.10222006;
          }
        } else {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)46865)) {
            result[0] += 0.21248491;
          } else {
            result[0] += 0.0721127;
          }
        }
      } else {
        if ( (data[10].missing != -1) && (data[10].fvalue < (float)125892)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)114906)) {
            result[0] += 0.047422644;
          } else {
            result[0] += -0.1901487;
          }
        } else {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)51653)) {
            result[0] += 0.05160409;
          } else {
            result[0] += -0.25581357;
          }
        }
      }
    }
  }
  if ( (data[20].missing != -1) && (data[20].fvalue < (float)885135)) {
    if ( (data[7].missing != -1) && (data[7].fvalue < (float)182230)) {
      if ( (data[23].missing != -1) && (data[23].fvalue < (float)144521)) {
        if ( (data[23].missing != -1) && (data[23].fvalue < (float)17780)) {
          if ( (data[17].missing != -1) && (data[17].fvalue < (float)870116)) {
            result[0] += -0.0046543414;
          } else {
            result[0] += -0.5954357;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)257802)) {
            result[0] += -0.12291308;
          } else {
            result[0] += 0.117121175;
          }
        }
      } else {
        if ( (data[11].missing != -1) && (data[11].fvalue < (float)113018)) {
          if ( (data[18].missing != -1) && (data[18].fvalue < (float)109345)) {
            result[0] += -0.011752357;
          } else {
            result[0] += 0.15748154;
          }
        } else {
          if ( (data[12].missing != -1) && (data[12].fvalue < (float)428649)) {
            result[0] += -0.30084932;
          } else {
            result[0] += 0.23845692;
          }
        }
      }
    } else {
      if ( (data[6].missing != -1) && (data[6].fvalue < (float)435)) {
        if ( (data[4].missing != -1) && (data[4].fvalue < (float)310)) {
          if ( (data[10].missing != -1) && (data[10].fvalue < (float)78693)) {
            result[0] += -0.6398646;
          } else {
            result[0] += -0.02718755;
          }
        } else {
          if ( (data[21].missing != -1) && (data[21].fvalue < (float)134368)) {
            result[0] += -0.1253123;
          } else {
            result[0] += 0.30306885;
          }
        }
      } else {
        if ( (data[6].missing != -1) && (data[6].fvalue < (float)110401)) {
          if ( (data[5].missing != -1) && (data[5].fvalue < (float)66314)) {
            result[0] += 0.06380925;
          } else {
            result[0] += 0.3411365;
          }
        } else {
          if ( (data[22].missing != -1) && (data[22].fvalue < (float)61)) {
            result[0] += -0.13678002;
          } else {
            result[0] += 0.10379747;
          }
        }
      }
    }
  } else {
    if ( (data[21].missing != -1) && (data[21].fvalue < (float)37332)) {
      result[0] += -0.5676996;
    } else {
      if ( (data[17].missing != -1) && (data[17].fvalue < (float)62)) {
        if ( (data[24].missing != -1) && (data[24].fvalue < (float)86892)) {
          result[0] += -0.36158597;
        } else {
          result[0] += 0.27792963;
        }
      } else {
        if ( (data[21].missing != -1) && (data[21].fvalue < (float)1143851)) {
          if ( (data[16].missing != -1) && (data[16].fvalue < (float)349898)) {
            result[0] += 0.516395;
          } else {
            result[0] += 0.1575861;
          }
        } else {
          result[0] += -0.12157494;
        }
      }
    }
  }
  
  // Apply base_scores
  result[0] += -0;
  
  // Apply postprocessor
  if (!pred_margin) { postprocess(result); }
}

} // end triggeralgs namespace
