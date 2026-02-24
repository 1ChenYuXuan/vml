
#pragma once

#include "_string.hpp"
#include <cstdio>
#include <string>

ALWAYS_INLINE auto output(const std::string& str);
ALWAYS_INLINE auto output(const char* str);
ALWAYS_INLINE auto output(const char c);
ALWAYS_INLINE std::string input();
ALWAYS_INLINE std::string input(const std::string &str);
ALWAYS_INLINE std::string input(const char str);
