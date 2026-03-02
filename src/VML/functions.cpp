
#include "functions.hpp"

FUNCTION funcs::MOV(FUNCTION_ARG) {
    // frist number is the number of the bits.
    // such as
    // 1 is 1bytes.
    // 2 is 2bytes.
    // 4 is 4bytes.
    // 8 is 8bytes.
    // else thing is error.
    ui8 bytes;
    ui32 location;
    
    bytes = *p;
    p++;
    location = *(ui32*)p;
    p+=4;
    if (!(bytes == 1 || bytes == 2 || bytes == 4 || bytes == 8)) 
        throw std::runtime_error("Try to move noncompliant bytes.");
    for (ui8 i = 0; i < bytes; ++i) {
       memory[location + i] = p[i];
    }
}

std::array<std::function<FuncSig>, 65536> functions;

void functionsInit() {
    functions[0] = funcs::MOV;
}
