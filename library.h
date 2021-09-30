#pragma once
#include <Windows.h>
#include <cstdint>

extern "C" __declspec(dllexport) uint32_t extractWindowsVersion (DWORD* version_data,
																char* buffer);