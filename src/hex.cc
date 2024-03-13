#include <string>
#include <stdexcept>

int fhex(char v1, char v2) {
    int acc = 0;
    switch (v1) {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            acc += v1 - 48; break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            acc += v1 - 87; break;
        default: throw std::length_error("Only allowed hexadecimals in braces"); break;
    }
    acc *= 16;
    switch (v2) {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            acc += v2 - 48; break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            acc += v2 - 87; break;
        default: throw std::length_error("Only allowed hexadecimals in braces"); break;
    }
    return acc;
}