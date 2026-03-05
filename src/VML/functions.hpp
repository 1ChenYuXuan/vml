
#pragma once

#include "../../libs/algorithm.hpp"
#include "../../libs/stddef.hpp"
#include <array>
#include <functional>
#include <stdexcept>

#define FUNCTION void
#define FUNCTION_ARG ui8 *p, Array<ui8, 0x10000>& memory, ui32 &ptr
#define CREATE_FUNC(name) FUNCTION name(FUNCTION_ARG)

using FuncSig = FUNCTION(FUNCTION_ARG);

namespace funcs {
    CREATE_FUNC(MOV);
    CREATE_FUNC(ADD);
    CREATE_FUNC(SUB);
    CREATE_FUNC(MUL);
    CREATE_FUNC(DIV);
};

extern std::array<std::function<FuncSig>, 0x10000> functions;

void functionsInit();
