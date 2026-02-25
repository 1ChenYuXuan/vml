
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#include "algorithm.hpp"

// although it is non-conforming,
// it as a syntactic sugar is very useful
// Maybe

ALWAYS_INLINE void output(const std::string& str) {
    fputs(str.c_str(), stdout);
}

ALWAYS_INLINE void output(const char* str) {
    fputs(str, stdout);
}

ALWAYS_INLINE void output(const char c) {
    putchar( c );
}

ALWAYS_INLINE std::string input() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}

ALWAYS_INLINE std::string input(const std::string &str) {
    output(str);
    std::string s;
    std::getline(std::cin, s);
    return s;
}

ALWAYS_INLINE std::string input(const char str) {
    output(str);
    std::string s;
    std::getline(std::cin, s);
    return s;
}
