#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "defs.h"
#include "s7.h"

__declspec(dllexport) void add1_init(s7_scheme *sc);