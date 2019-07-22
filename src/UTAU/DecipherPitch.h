#ifndef LESSAMPLER_DECIPHERPITCH_H
#define LESSAMPLER_DECIPHERPITCH_H

/*
 * Decode the pit parameters of utau
 */

#if (defined (__linux__) || defined(__CYGWIN__) || defined(__APPLE__))
#define sscanf_s sscanf
#endif

int DecipherPitch(char *pitch_input, int *destination, int dest_size);

#endif //LESSAMPLER_DECIPHERPITCH_H
