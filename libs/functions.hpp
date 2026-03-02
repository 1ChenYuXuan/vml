
#pragma once

#include "stddef.hpp"
#include <array>
#include <functional>
#include <stdexcept>

#define FUNCTION void
#define FUNCTION_ARG char *p, Array<ui8, 0xA0000> memory

using FuncSig = FUNCTION(FUNCTION_ARG);

namespace funcs {
    FUNCTION MOV(FUNCTION_ARG);
};

extern std::array<std::function<FuncSig>, 65536> functions;

void functionsInit();
