//
// Created by YuzukiTsuru on 2021/3/13.
//
#include <iostream>
#include <sstream>

#if MSVC
#include <algorithm>
#endif

#include "UTAUParameterPaser.h"
#include "ScaleConvert.h"

UTAUParameterPaser::UTAUParameterPaser(int argc, char *argv[]) {
    utauPara.localName = argv[0];
    utauPara.inputFileName = argv[1];
    utauPara.outputFileName = argv[2];
    utauPara.scaleName = argv[3];
    ScaleConvert scaleConvert(utauPara.scaleName);
    utauPara.scaleNum = scaleConvert.GetScaleNum();

    // velocity
    if (argc > 3) {
        std::istringstream sstream(argv[4]);
        sstream >> utauPara.timePercent;
        utauPara.velocity = pow(2, utauPara.timePercent / 100.0 - 1.0);
        sstream.clear();
    }

    // offset
    if (argc > 5) {
        std::istringstream sstream(argv[6]);
        sstream >> utauPara.offset;
        sstream.clear();
    }

    // require length
    if (argc > 6) {
        std::istringstream sstream(argv[7]);
        sstream >> utauPara.requiredLength;
        sstream.clear();
    }

    // fixed length
    if (argc > 7) {
        std::istringstream sstream(argv[8]);
        sstream >> utauPara.firstHalfFixedPart;
        sstream.clear();
    }

    // blank length
    if (argc > 8) {
        std::istringstream sstream(argv[9]);
        sstream >> utauPara.lastUnusedPart;
        sstream.clear();
    }

    // volume
    if (argc > 9) {
        std::istringstream sstream(argv[10]);
        sstream >> utauPara.volumes;
        utauPara.volumes *= 0.01;
        sstream.clear();
    }

    // modulation
    if (argc > 10) {
        std::istringstream sstream(argv[11]);
        sstream >> utauPara.modulation;
        sstream.clear();
    }

    // tempo
    if (argc > 11) {
        std::istringstream sstream(argv[12]);
        sstream >> utauPara.tempo;
        utauPara.tempoNum = std::stoi(utauPara.tempo.substr(1, utauPara.tempo.length()));
        sstream.clear();
    }

    // pitchbend
    if (argc > 12) {
        std::istringstream sstream(argv[13]);
        sstream >> utauPara.pitch;
        // TODO: Geez
    }
}
