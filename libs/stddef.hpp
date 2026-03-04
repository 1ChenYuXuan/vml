
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

// frist

#pragma once

#include <cstdint>
#include <cmath>
#include <array>
#include <cstdlib>

#if defined(_MSC_VER)
  #define ALWAYS_INLINE __forceinline
#else
  #define ALWAYS_INLINE inline __attribute__((always_inline)) // I use it but the Vscodse dosen't support it. But I will use it.
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

enum : ui16 {
    VML_add, // 00
    VML_sub, // 01
    VML_mul, // 02
    VML_div, // 03
    VML_big, // 04
    VML_small, // 05
    VML_equal, // 06
    VML_band, // 07
    VML_bor, // 08
    VML_bnot, // 09
    
    VML_output, // 10
    VML_input, // 11
    VML_mov, // 12
    VML_load, // 13
    VML_store, // 14
    VML_inc, // 15
    VML_dec, // 16
    
    VML_cmp, // 17
    VML_go, // 18
    VML_capi // 19
} cmd;

template<typename T, ui32 size>
class Array // myself array
{
private:
    T *p;
public:
    Array();
    ~Array();
    T &operator[](ui32 index);
    const T &operator[](ui32 index) const;
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
T &Array<T, size>::operator[](ui32 index) {
    return p[index]; // Maybe cause Segment Error.
                     // TODO: Throw
}

template<typename T, ui32 size>
const T &Array<T, size>::operator[](ui32 index) const {
    return p[index]; // Maybe cause Segment Error.
                     // TODO: Throw
}

template<typename T, ui32 size>
T *Array<T, size>::get() {
    return p;
}
