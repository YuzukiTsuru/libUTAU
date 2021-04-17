//
// Created by YuzukiTsuru on 2021/3/13.
//
#include <iostream>
#include <sstream>
#include "PitchBendDecoder.h"


PitchBendDecoder::PitchBendDecoder(char *str) {
    pitch = str;
    PitchBendDecode();
}

PitchBendDecoder::PitchBendDecoder(std::string &str) {
    pitch = str.data();
    PitchBendDecode();
}

int PitchBendDecoder::GetDataFromUTAU64(int i) {
    if (i >= '0' && i <= '9') {
        return i - '0' + 52;
    } else if (i >= 'A' && i <= 'Z') {
        return i - 'A';
    } else if (i >= 'a' && i <= 'z') {
        return i - 'a' + 26;
    } else if (i == '+') {
        return 62;
    } else if (i == '/') {
        return 63;
    } else {
        return 0;
    }
}

void PitchBendDecoder::PitchBendDecode() {
}
