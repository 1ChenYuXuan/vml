
#include "functions.hpp"

FUNCTION funcs::MOV(FUNCTION_ARG) {
    // frist number is the number of the bits.
    // such as
    // 1 is 1bytes.
    // 2 is 2bytes.
    // 4 is 4bytes.
    // 8 is 8bytes.
    // else thing is error.
    ui8 bytes = *p;
    p++;
    if (!(bytes == 1 || bytes == 2 || bytes == 4 || bytes == 8)) 
        throw std::runtime_error("Try to move noncompliant bytes.");
    for (ui8 h = 0; h < bytes; ++h) {
        // TODO: Do move datas.
    }
}

std::array<std::function<FuncSig>, 65536> functions;

void functionsInit() {
    functions[0] = funcs::MOV;
}
