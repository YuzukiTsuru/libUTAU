//
// Created by YuzukiTsuru on 2021/3/13.
//

#ifndef LIBUTAU_PITCHBENDDECODER_H
#define LIBUTAU_PITCHBENDDECODER_H


class PitchBendDecoder {
public:
    explicit PitchBendDecoder(char *str);

private:
    char *pitch = nullptr;
    int cnt = 0;
    int *dst = nullptr;

    static int GetDataFromUTAU64(int i);

    void PitchBendDecode();
};


#endif //LIBUTAU_PITCHBENDDECODER_H
