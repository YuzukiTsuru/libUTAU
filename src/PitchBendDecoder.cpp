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

PitchBendDecoder::PitchBendDecoder(std::string& str) {
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
    int k = 0, n = 0, num = 0;
    std::string pitBendStr = pitch;
    int len = pitBendStr.length();
    if (!pitBendStr.empty()) {
        for (int i = 0; i < len; i += 2) {
            if (pitBendStr[i] == '#') {
                std::istringstream inStr(pitch + i + 1);
                inStr >> num;
                for (int j = 0; j < num && k < cnt; ++j) {
                    dst[k++] = n;
                }
                while (pitBendStr[i + 1] != '#' && pitBendStr[i + 1] != 0) {
                    ++i;
                }
            } else {
                n = GetDataFromUTAU64(pitch[i]) * 64 + GetDataFromUTAU64(pitch[i + 1]);
                if (n > 2047) {
                    n -= 4096;
                }
                if (k < cnt) {
                    dst[k++] = n;
                }
            }
        }
    }
}
