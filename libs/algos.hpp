
#pragma once

#include <vector>

#define ALWAYS_INLINE __attribute__((always_inline)) inline

template <typename T>
ALWAYS_INLINE add(std::vector<T> v);

template <typename T>
ALWAYS_INLINE sub(std::vector<T> v);

template <typename T>
ALWAYS_INLINE mul(std::vector<T> v);

template <typename T>
ALWAYS_INLINE div(std::vector<T> v);
