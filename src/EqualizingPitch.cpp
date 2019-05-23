#include <cmath>
#include "UTAU/EqualizingPitch.h"
#include "UTAU/GetFreqAvg.h"

void EqualizingPitch(double *f0, int num_frames, char *scaleParam, int modulationParam, int flag_t) {
    int i;
    // First, find the average value.
    double averageF0;
    double modulation;

    modulation = static_cast<double>(modulationParam / 100.0);

    averageF0 = GetFreqAvg(f0, num_frames);

    int scale;
    int octave;
    double targetF0;
    int bias = 0;

    // Identify the desired pitch.
    if (scaleParam[1] == '#') bias = 1;

    switch (scaleParam[0]) {
        case 'C':
            scale = -9 + bias;
            break;
        case 'D':
            scale = -7 + bias;
            break;
        case 'E':
            scale = -5;
            break;
        case 'F':
            scale = -4 + bias;
            break;
        case 'G':
            scale = -2 + bias;
            break;
        case 'A':
            scale = bias;
            break;
        case 'B':
            scale = 2;
            break;
        default:
            scale = 0;
            break;
    }
    octave = scaleParam[1 + bias] - '0' - 4;
    targetF0 = 440 * pow(2.0, static_cast<double>(octave)) * pow(2.0, static_cast<double>(scale) / 12.0);
    targetF0 *= pow(2, static_cast<double>(flag_t) / 120);

    double tmp;

    if (averageF0 != 0.0) {
        for (i = 0; i < num_frames; i++) {
            if (f0[i] != 0.0) {
                tmp = ((f0[i] - averageF0) * modulation) + averageF0;
                f0[i] = tmp * targetF0 / averageF0;
            }
        }
    } else {
        for (i = 0; i < num_frames; i++) {
            if (f0[i] != 0.0) {
                f0[i] = targetF0;
            }
        }
    }
}
