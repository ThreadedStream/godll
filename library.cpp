#include "library.h"
#include <cstdio>


#define TEXT_LENGTH 8

uint32_t extractWindowsVersion(DWORD* version_data, char* buffer) {
	if (version_data == nullptr) {
		version_data = static_cast<DWORD*>(calloc(3, sizeof(DWORD)));
		if (!version_data) {
			return ERROR_OUTOFMEMORY;
		}
	}

	if (buffer == nullptr) {
		buffer = static_cast<char*>(calloc(TEXT_LENGTH + 1, sizeof(char)));
		if (!buffer) {
			return ERROR_OUTOFMEMORY;
		}
	}

	DWORD build{ 0 };
		
	const auto version = GetVersion();
	const auto major_version = (DWORD)(LOBYTE(LOWORD(version)));
	const auto minor_version = (DWORD)(LOBYTE(HIWORD(version)));

	if (version < 0x80000000)
		build = (DWORD)(HIWORD(version));
		
	*version_data = major_version;
	*(version_data + 1) = minor_version;
	*(version_data + 2) = build;
	
	sprintf(buffer, "%d.%d.%d", major_version, minor_version, build);
	// null-terminate a buffer
	buffer[TEXT_LENGTH] = '\0';

	return ERROR_SUCCESS;

}
