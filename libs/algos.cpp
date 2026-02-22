
#pragma once

#include "algos.hpp"

template <typename T>
ALWAYS_INLINE add(std::vector<T> v)
{
    return v[0] + v[1];
}

template <typename T>
ALWAYS_INLINE sub(std::vector<T> v)
{
    return v[0] - v[1];
}

template <typename T>
ALWAYS_INLINE mul(std::vector<T> v)
{
    return v[0] * v[1];
}

template <typename T>
ALWAYS_INLINE div(std::vector<T> v)
{
    return v[0] / v[1];
}

