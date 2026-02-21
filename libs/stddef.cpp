
#include "stddef.hpp"

constexpr ui16 bufferSize = 0x1000;

std::array<ui8, bufferSize> buffer;

#if defined(__LDBL_MANT_DIG__) || defined(LDBL_MANT_DIG)
    bool has_f128 = true;
#else
    bool has_f128 = false;
#endif
