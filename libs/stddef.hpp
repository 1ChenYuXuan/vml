
// frist

#pragma once

#include <cmath>
#include <array>
#include <cstdlib>

#if defined(_MSC_VER)
#define ALWAYS_INLINE __forceinline
#else
#define ALWAYS_INLINE inline __attribute__((always_inline))
#endif

using ui8  = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using f32 = float;
using f64 = double;

#if defined(__LDBL_MANT_DIG__) || defined(LDBL_MANT_DIG)
    using f128 = long double;
#endif

extern bool has_f128;
constexpr ui16 bufferSize = 0x1000;
extern std::array<ui8, bufferSize> buffer;

constexpr ui16 registerSize = 0x0400;
extern std::array<ui8, registerSize> registers;

enum class cmd: ui16 {
    add,
    sub,
    mul,
    div,
    big,
    small,
    equal,
    band,
    bor,
    bnot,
    
    output,
    input,
    mov,
    load,
    store,
    inc,
    dec,
    
    cmp,
    go,
    capi
};


