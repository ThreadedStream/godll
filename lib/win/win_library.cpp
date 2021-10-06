#include "win_library.h"
#include <cstdio>
#define TEXT_LENGTH 8

uint32_t extractWindowsVersion(DWORD* major_version, DWORD* minor_version, DWORD* build_number , char** buffer ) {

	DWORD build{ 0 };
		
	const auto version = GetVersion();
	const auto major_version_l = (DWORD)(LOBYTE(LOWORD(version)));
	const auto minor_version_l = (DWORD)(LOBYTE(HIWORD(version)));

	if (version < 0x80000000)
		build = (DWORD)(HIWORD(version));
		
	*major_version = major_version_l;
	*minor_version = minor_version_l;
	*build_number = build;
	
	sprintf(*buffer, "%d.%d.%d", *major_version, *minor_version, *build_number);
	
	// null-terminate a buffer
	*(*buffer + TEXT_LENGTH) = '0';

	return ERROR_SUCCESS;
}
