#include "UTAU/GetUTAU64.h"

int GetUTAU64(int b64) {
    if (b64 >= '0' && b64 <= '9') {
        return b64 - '0' + 52;
    } else if (b64 >= 'A' && b64 <= 'Z') {
        return b64 - 'A';
    } else if (b64 >= 'a' && b64 <= 'z') {
        return b64 - 'a' + 26;
    } else if (b64 == '+') {
        return 62;
    } else if (b64 == '/') {
        return 63;
    } else {
        return 0;
    }
}