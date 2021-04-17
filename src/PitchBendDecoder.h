//
// Created by YuzukiTsuru on 2021/3/13.
//

#ifndef LIBUTAU_PITCHBENDDECODER_H
#define LIBUTAU_PITCHBENDDECODER_H

#include <iostream>

class PitchBendDecoder {
public:
    explicit PitchBendDecoder(char *str);

    explicit PitchBendDecoder(std::string &str);

private:
    char *pitch = nullptr;
    int cnt = 0;
    [[maybe_unused]] int *dst = nullptr;

    static int GetDataFromUTAU64(int i);

    void PitchBendDecode();
};


#endif //LIBUTAU_PITCHBENDDECODER_H
