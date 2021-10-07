#pragma once
#include <Windows.h>
#include <stdint.h>

extern "C" __declspec(dllexport) uint32_t extractWindowsVersion (DWORD* major_version,
																DWORD*	minor_version,
																DWORD*  build_number,
																char** buffer);
