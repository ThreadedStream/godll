#pragma once


#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#endif

enum LinuxErrorCodes{
    LIB_NOT_FOUND = -2,
    FUNC_NOT_FOUND = -3,
    OUT_OF_MEMORY = -4,
};