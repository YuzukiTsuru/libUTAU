//
// Created by YuzukiTsuru on 2021/3/7.
//

#ifndef LIBUTAU_LIBUTAU_H
#define LIBUTAU_LIBUTAU_H

#include <iostream>

class libUTAU {

};

class UTAUPara {
public:
    std::string localName;
    std::string inputFileName;
    std::string outputFileName;
    std::string scale;
    int scaleNum;
    int timePercent;
    std::string flags;
    double offset;
    double requiredLength;
    double firstHalfFixedPart;
    double lastUnusedPart;
    int modulation;
    double pitchBend;
    std::string pitch;
};


#endif //LIBUTAU_LIBUTAU_H
