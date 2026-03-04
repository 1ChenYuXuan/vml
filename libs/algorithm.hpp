
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#pragma once

#include "stddef.hpp"
#include "_string.hpp"
#include <cstdio>
#include <string>

ALWAYS_INLINE void output(const std::string& str);
ALWAYS_INLINE void output(const char* str);
ALWAYS_INLINE void output(const char c);
ALWAYS_INLINE std::string input();
ALWAYS_INLINE std::string input(const std::string &str);
ALWAYS_INLINE std::string input(const char str);
ALWAYS_INLINE void flush();

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

ALWAYS_INLINE void flush() {
    fflush(stdout);
}
