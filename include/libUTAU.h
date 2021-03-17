//
// Created by YuzukiTsuru on 2021/3/7.
//

#ifndef LIBUTAU_LIBUTAU_H
#define LIBUTAU_LIBUTAU_H

#include <iostream>

class UTAUPara {
public:
    std::string localName = {};
    std::string inputFileName = {};
    std::string outputFileName = {};
    std::string scaleName = {};
    double scaleNum = 0.0;
    int timePercent = 0;
    double velocity = 0.0;
    std::string flags = {};
    double offset = 0.0;
    double requiredLength = 0.0;
    double firstHalfFixedPart = 0.0;
    double lastUnusedPart = 0.0;
    double volumes = 0;
    int modulation = 0;
    std::string tempo = {};
    int tempoNum = 0;
    std::string pitch = {};
};

class libUTAU {
public:
    libUTAU(int argc, char *argv[]);

private:
    UTAUPara utauPara;
};

#endif //LIBUTAU_LIBUTAU_H
