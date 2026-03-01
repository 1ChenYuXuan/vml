
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

// frist

#pragma once

#include <cmath>
#include <array>
#include <cstdlib>

#if defined(_MSC_VER)
  #define ALWAYS_INLINE __forceinline
#else
  #define ALWAYS_INLINE __attribute__((always_inline))
#endif

#define transmitc auto&
#define transmitv auto
#define transmitvc auto&&

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

template<typename T, ui32 size>
class Array // myself array
{
private:
    T *p;
public:
    Array();
    ~Array();
    T operator[](ui32 index);
    T *get();
};

template<typename T, ui32 size>
Array<T, size>::Array() {
    p = new T[size];
}

template<typename T, ui32 size>
Array<T, size>::~Array() {
    delete[] p;
}

template<typename T, ui32 size>
T Array<T, size>::operator[](ui32 index) {
    return p[index]; // Maybe cause Segment Error.
                     // TODO: Throw
}

template<typename T, ui32 size>
T *Array<T, size>::get() {
    return p;
}
