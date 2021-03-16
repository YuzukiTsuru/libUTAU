//
// Created by YuzukiTsuru on 2021/3/13.
//

#include "UTAUParameterPaser.h"
#include "ScaleConvert.h"

UTAUParameterPaser::UTAUParameterPaser(int argc, char *argv) {
    utauPara.localName = argv[0];
    utauPara.inputFileName = argv[1];
    utauPara.outputFileName = argv[2];
    utauPara.scaleName = argv[3];
    utauPara.scaleNum = ScaleConvert::ScaleConvertToDouble(utauPara.scaleName);

}
