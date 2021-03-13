//
// Created by YuzukiTsuru on 2021/3/13.
//

#include "UTAUParameterPaser.h"

UTAUParameterPaser::UTAUParameterPaser(int argc, char *argv) {
    utauPara.localName = argv[0];
    utauPara.inputFileName = argv[1];
    utauPara.outputFileName = argv[2];
    utauPara.scale = argv[3];
}
