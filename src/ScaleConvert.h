//
// Created by YuzukiTsuru on 2021/3/13.
//

#ifndef LIBUTAU_SCALECONVERT_H
#define LIBUTAU_SCALECONVERT_H

#include <cmath>
#include <iostream>

class ScaleConvert {
public:
    explicit ScaleConvert(std::string scaleName);

    [[nodiscard]] double GetScaleNum() const;

private:
    double scaleNum = 0.0;
    /*
     * Scale Name Convert to number as double
     * IN: std::string scaleName
     * RET: bool
     *   true -> success
     *   false -> fail
     * OUT： double scaleNum
     */
    bool ScaleConvertToDouble(std::string scaleName);
};


#endif //LIBUTAU_SCALECONVERT_H
