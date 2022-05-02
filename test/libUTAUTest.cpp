//
// Created by YuzukiTsuru on 2021/3/17.
//

#include "../src/libUTAU.h"

int main(int argc, char **argv) {
    try {
        libUTAU libUtau(argc, argv);
        libUtau.printUTAUPara();
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}