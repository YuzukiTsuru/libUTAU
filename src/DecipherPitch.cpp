#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include "UTAU/DecipherPitch.h"
#include "UTAU/GetUTAU64.h"


int DecipherPitch(char *pitch_input, int *destination, int dest_size) {
    int input_size = 0;
    int i, j;
    int pitch_unchanged_num;
    int pitch_value = 0;
    int cur_dest_index = 0;
    if (pitch_input != NULL) {
        input_size = strlen(pitch_input);
        for (i = 0; i < input_size; i += 2) {
            // Decode "#somenumber#" for repeated pitch values.
            if (pitch_input[i] == '#') {
                i++;
                sscanf_s(pitch_input + i, "%d", &pitch_unchanged_num);
                for (j = 0; j < pitch_unchanged_num && cur_dest_index < dest_size; j++) {
                    destination[cur_dest_index] = pitch_value;
                    cur_dest_index++;
                }
                while (pitch_input[i] != '#' && pitch_input[i] != 0) i++;
                i--;
            }
                // Decode a 2-char pitch value between -2048 and 2047.
            else {
                pitch_value = GetUTAU64(pitch_input[i]) * 64 + GetUTAU64(pitch_input[i + 1]);
                if (pitch_value > 2047) {
                    pitch_value -= 4096;
                }
                if (cur_dest_index < dest_size) {
                    destination[cur_dest_index] = pitch_value;
                    cur_dest_index++;
                }
            }
        }
    }
    return input_size;
}
