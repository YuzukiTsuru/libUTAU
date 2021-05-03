//
// Created by YuzukiTsuru on 2021/3/7.
//

#include <iostream>

#include "UTAUException.h"

#include "libUTAU.h"

libUTAU::libUTAU(int argc, char **argv) {
    if (argc < 3) {
        throw parameter_error("too sort");
    }
}

void libUTAU::printUTAUPara() {
    std::cout << utauPara.localName << std::endl;
    std::cout << utauPara.inputFileName << std::endl;
    std::cout << utauPara.outputFileName << std::endl;
    std::cout << utauPara.scaleName << std::endl;
    std::cout << utauPara.scaleNum << std::endl;
    std::cout << utauPara.timePercent << std::endl;
    std::cout << utauPara.velocity << std::endl;
    std::cout << utauPara.flags << std::endl;
    std::cout << utauPara.offset << std::endl;
    std::cout << utauPara.requiredLength << std::endl;
    std::cout << utauPara.firstHalfFixedPart << std::endl;
    std::cout << utauPara.lastUnusedPart << std::endl;
    std::cout << utauPara.volumes << std::endl;
    std::cout << utauPara.tempo << std::endl;
    std::cout << utauPara.tempoNum << std::endl;
    std::cout << utauPara.pitch << std::endl;
    std::cout << utauPara.pitchBend.data() << std::endl;
}
