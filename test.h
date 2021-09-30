#pragma once
#include <Windows.h>
#include <cstdio>
#include <cstdint>

typedef uint32_t (*ExtractWindowsVersionPtr)(DWORD* version_data, char* buffer);


uint32_t printWindowsVersion(int32_t *version_slice, char* version_string) {
	HINSTANCE lib_instance;

	lib_instance = LoadLibrary(TEXT("godll.dll"));
	if (!lib_instance) {
		return ERROR_FILE_NOT_FOUND;
	}

	const auto extractWindowsVersion = (ExtractWindowsVersionPtr)GetProcAddress(lib_instance, "extractWindowsVersion");
	if (!extractWindowsVersion) {
		FreeLibrary(lib_instance);
		return ERROR_PROC_NOT_FOUND;
	}

	DWORD* version_data = nullptr; char *buffer = nullptr;
	uint32_t result = extractWindowsVersion(version_data, buffer);
	if (result != ERROR_SUCCESS) {
		FreeLibrary(lib_instance);
		return result;
	}

	version_slice = version_data;
	version_string = buffer;
	
	free(version_data);
	free(buffer);

	version_data = nullptr;
	buffer = nullptr;

	return ERROR_SUCCESS;

}