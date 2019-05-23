#include "UTAU/GetFreqAvg.h"

double GetFreqAvg(double f0[], int num_frames) {
    int i, j;
    double value = 0, r;
    double p[6], q;
    double freq_avg = 0;
    double base_value = 0;
    for (i = 0; i < num_frames; i++) {
        value = f0[i];
        if (value < 1000.0 && value > 55.0) {
            r = 1.0;
            // Continuously weight nearby variables more heavily.=
            for (j = 0; j <= 5; j++) {
                if (i > j) {
                    q = f0[i - j - 1] - value;
                    p[j] = value / (value + q * q);
                } else {
                    p[j] = 1 / (1 + value);
                }
                r *= p[j];
            }
            freq_avg += value * r;
            base_value += r;
        }
    }
    if (base_value > 0) {
        freq_avg /= base_value;
    }
    return freq_avg;
}