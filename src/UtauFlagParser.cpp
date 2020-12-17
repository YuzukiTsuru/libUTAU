#include "UTAU/UtauFlagParser.h"

void UtauFlagParser(int argc, char *argv[], UTAUFLAG *flag) {
    char *string_buf;
    int cur_char_index;

    /*
     * Breath: flag_A:A
     * IN:
     *      argv[5]
     * Default:
     *      int 50
     * Out:
     *      int Breath
     */

    flag->flag_A = 50;

    if (argc > 5 && (string_buf = strchr(argv[5], 'A')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%d", &flag->flag_A);
            flag->flag_A = max(0, min(100, flag->flag_A));
        }
    }

    /*
    * Consonant strength: flag_B:B
    * IN:
    *      argv[5]
    * Default:
    *      int 0
    * Out:
    *      int Consonant strength
    */

    flag->flag_B = 0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'B')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%d", &flag->flag_B);
            flag->flag_B = max(0, min(100, flag->flag_B));
        }
    }

    /*
    * Pitch fine tuning: flag_C:C
    * IN:
    *      argv[5]
    * Default:
    *      int 0
    * Out:
    *      int Pitch fine tuning
    */

    flag->flag_C = 0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'C')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%d", &flag->flag_C);
        }
    }

    /*
    * Gender: flag_D:D
    * IN:
    *      argv[5]
    * Default:
    *      double 0.0
    * Out:
    *      double Pitch fine tuning
    */

    flag->flag_D = 0.0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'D')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%lf", &flag->flag_D);
            if (flag->flag_D > 100) {
                flag->flag_D = 100;
            }
            if (flag->flag_D < -100) {
                flag->flag_D = -100;
            }
        }
    }

    /*
    * （frequency enforcement settings）F<0 unvoiced  F=0 no effect  50>=F<=1000 : flag_E:E
    * IN:
    *      argv[5]
    * Default:
    *      double 0.0
    * Out:
    *      double frequency enforcement settings
    */

    flag->flag_E = 0.0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'E')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%lf", &flag->flag_E);
            if (flag->flag_E > 1000) {
                flag->flag_E = 1000;
            }
            if ((flag->flag_E < 50) && (flag->flag_E > 0)) {
                flag->flag_E = 0;
            }
            if (flag->flag_E < 0) {
                flag->flag_E = -1;
            }
        }
    }

    /*
    * LPF on DIO's F0 analysis result. : flag_F:F
    * IN:
    *      argv[5]
    * Default:
    *      int 5
    * Out:
    *      None
    */
    flag->flag_F = 5;

    /*
    * Original flag: Correct volume of combined pitch changes. : flag_G:G
    * IN:
    *      argv[5]
    * Default:
    *      int 0
    * Out:
    *      int volume
    */
    flag->flag_G = 0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'G')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%d", &flag->flag_G);
            flag->flag_G = max(0, min(100, flag->flag_G));
        }
    }

    /*
    * voice strength : flag_H:H
    * IN:
    *      argv[5]
    * Default:
    *      int 0
    * Out:
    *      int strength
    */
    flag->flag_H = 0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'H')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%d", &flag->flag_H);
            flag->flag_H = max(-100, min(100, flag->flag_H));
        }
    }

    /*
    * Change the vowel stretching method: default is loops. : flag_I:I
    * IN:
    *      argv[5]
    * Default:
    *      int 0
    * Out:
    *      int stretching method
    */
    flag->flag_I = 0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'I')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            flag->flag_I = 1;
        }
    }

    /*
    * Select F0 Estimation method: flag_a:a
    * IN:
    *      argv[5]
    * Default:
    *      int 0
    * Out:
    *      int F0 Estimation method
    */
    flag->flag_a = 0;
    if (argc > 5 && (string_buf = strchr(argv[5], 'a')) != 0) {
        cur_char_index = string_buf - argv[5];
        if ((cur_char_index == 0) || (argv[5][cur_char_index - 1] != 'M')) {
            sscanf_s(string_buf + 1, "%d", &flag->flag_a);
            flag->flag_a = max(-100, min(100, flag->flag_a));
        }
    }
}
