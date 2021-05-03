//
// Created by YuzukiTsuru on 2021/5/3.
//

#ifndef LIBUTAU_UTAUEXCEPTION_H
#define LIBUTAU_UTAUEXCEPTION_H

#include <stdexcept>
#include <string>

class parameter_error : public std::runtime_error {
public:
    explicit parameter_error(const std::string &what) : std::runtime_error("Parameter error: " + what + ".") {};
};

class type_error : public std::runtime_error {
public:
    explicit type_error(const std::string &what) : std::runtime_error("Type error: " + what + ".") {};
};

#endif //LIBUTAU_UTAUEXCEPTION_H
