#ifndef LESSAMPLER_UTAUFLAGPASER_H
#define LESSAMPLER_UTAUFLAGPASER_H

#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <string>
#include <array>

#if (defined (__linux__) || defined(__CYGWIN__) || defined(__APPLE__))
#define sscanf_s sscanf
#endif

/*
 * a ~ z: function setting
 * A ~ Z: turning function
 * The type of flag can be customized
 */

typedef struct {
    int flag_A;
    int flag_B;
    int flag_C;
    double flag_D;
    double flag_E;
    int flag_F;
    int flag_G;
    int flag_H;
    int flag_I;

    // Unused
    int flag_J;
    int flag_K;
    int flag_L;
    int flag_M;
    int flag_N;
    int flag_O;
    int flag_P;
    int flag_Q;
    int flag_R;
    int flag_S;
    int flag_T;
    int flag_U;
    int flag_V;
    int flag_W;
    int flag_X;
    int flag_Y;
    int flag_Z;

    int flag_a;
    int flag_b;
    int flag_c;
    int flag_d;
    int flag_e;
    int flag_f;
    int flag_g;
    int flag_h;
    int flag_i;
    int flag_j;
    int flag_k;
    int flag_l;
    int flag_m;
    int flag_n;
    int flag_o;
    int flag_p;
    int flag_q;
    int flag_r;
    int flag_s;
    int flag_t;
    int flag_u;
    int flag_v;
    int flag_w;
    int flag_x;
    int flag_y;
    int flag_z;
}UTAUFLAG;

void UtauFlagPaser(int argc, char *argv[], UTAUFLAG *flag);

using std::min;
using std::max;

#endif //LESSAMPLER_UTAUFLAGPASER_H
