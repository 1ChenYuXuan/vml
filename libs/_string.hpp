
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#pragma once

#include "stddef.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>
#include <algorithm>
#include <cctype>
#include <set>

extern const std::set<char> SYMBOL;

std::vector<std::string> good_str(const std::string& utf8_str);
std::vector<std::string> split(const std::string& s, char sep);
std::string join(const std::vector<std::string>& strs, const std::string& sep);
bool is_digit(const std::string& str);
void ltrim(std::string& s);
void rtrim(std::string& s);
void trim(std::string& s);
std::vector<std::string> ssars(const std::string& str);
std::vector<std::string> ssarsass(const std::string& str);
