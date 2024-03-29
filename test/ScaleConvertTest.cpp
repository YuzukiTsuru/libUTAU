//
// Created by YuzukiTsuru on 2021/3/13.
//
#include <iostream>
#include "../src/ScaleConvert.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return -1;
    }
    std::string scaleName = argv[1];
    ScaleConvert scaleConvert(scaleName);
    std::cout << scaleConvert.GetScaleNum() << std::endl;
    return 0;
}