#pragma once
#include <Windows.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t (*ExtractWindowsVersionPtr)(DWORD* major_version, DWORD* minor_version, DWORD* build_number, char** buffer);

#define TEXT_LENGTH 8

uint32_t getWindowsVersion(DWORD* major_version, DWORD* minor_version, DWORD* build_number, char** output_buffer) {
    HINSTANCE lib_instance;

    lib_instance = LoadLibrary(TEXT("D:\\toys\\godll\\build64\\Debug\\godll.dll"));
    //printf("%x", &lib_instance);
    if (!lib_instance) {
        return ERROR_FILE_NOT_FOUND;
    }

    ExtractWindowsVersionPtr extractWindowsVersion = (ExtractWindowsVersionPtr)GetProcAddress(lib_instance, "extractWindowsVersion");
    if (!extractWindowsVersion) {
        FreeLibrary(lib_instance);
        return ERROR_PROC_NOT_FOUND;
    }

    if (*output_buffer == NULL) {
        *output_buffer = (char*) (calloc(TEXT_LENGTH + 1, sizeof(char)));
        if (!(*output_buffer)) {
            FreeLibrary(lib_instance);
            return ERROR_OUTOFMEMORY;
        }
    }

    DWORD result = extractWindowsVersion(major_version, minor_version, build_number , output_buffer);
    if (result != ERROR_SUCCESS) {
        FreeLibrary(lib_instance);
        return result;
    }

    FreeLibrary(lib_instance);

    return ERROR_SUCCESS;

}