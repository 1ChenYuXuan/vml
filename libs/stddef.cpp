
#include "stddef.hpp"

std::array<ui8, bufferSize> buffer;
std::array<ui8, registerSize> registers;

#if defined(__LDBL_MANT_DIG__) || defined(LDBL_MANT_DIG)
    bool has_f128 = true;
#else
    bool has_f128 = false;
#endif
