
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#include "stddef.hpp"

#if defined(__LDBL_MANT_DIG__) || defined(LDBL_MANT_DIG)
    constexpr bool has_f128 = true;
#else
    constexpr bool has_f128 = false;
#endif

