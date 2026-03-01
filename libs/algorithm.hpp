
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
