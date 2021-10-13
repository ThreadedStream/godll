package main

// #cgo CFLAGS: -g -Wall
//  #include <Windows.h>
//  #include <stdint.h>
//  #include <stdio.h>
//  #include "lib/shared/defs.h"
//
//   typedef uint32_t (*ExtractWindowsVersionPtr)(DWORD* major_version, DWORD* minor_version, DWORD* build_number, char** buffer);
//
//   #define TEXT_LENGTH 8
//
//   uint32_t getWindowsVersion(DWORD* major_version, DWORD* minor_version, DWORD* build_number, char** output_buffer) {
//       HINSTANCE lib_instance;
//
//       lib_instance = LoadLibrary(TEXT("godll.dll"));
//       if (!lib_instance) {
//           return ERROR_FILE_NOT_FOUND;
//       }
//
//       ExtractWindowsVersionPtr extractWindowsVersion = (ExtractWindowsVersionPtr)GetProcAddress(lib_instance, "extractWindowsVersion");
//       if (!extractWindowsVersion) {
//           FreeLibrary(lib_instance);
//           return ERROR_PROC_NOT_FOUND;
//       }
//
//       if (*output_buffer == NULL) {
//           *output_buffer = (char*) (calloc(TEXT_LENGTH + 1, sizeof(char)));
//           if (!(*output_buffer)) {
//               FreeLibrary(lib_instance);
//               return ERROR_OUTOFMEMORY;
//           }
//       }
//
//       DWORD result = extractWindowsVersion(major_version, minor_version, build_number , output_buffer);
//       if (result != ERROR_SUCCESS) {
//           FreeLibrary(lib_instance);
//           return result;
//       }
//
//       FreeLibrary(lib_instance);
//
//       return ERROR_SUCCESS;
//
//   }
import "C"

import (
	"fmt"
	"unsafe"
)

func main() {
	var (
		majorVersion, minorVersion, buildNumber C.DWORD
		str *C.char
		ret = C.getWindowsVersion(&majorVersion, &minorVersion, &buildNumber, &str)
	)
	var returnValue = (int) (ret)

	if returnValue == 0{
		fmt.Printf("major: %d, minor: %d, build number: %d\n", (int) (majorVersion), (int) (minorVersion), (int) (buildNumber))
		fmt.Printf("buffer: %s", C.GoString(str))
	} else {
	    var reason = C.getHumanReadableErrorDescription((C.int32_t) (ret))
		fmt.Printf("failed to get windows version, reason: %s", C.GoString(reason))
	}

	// NOTE(threadedstream): free the memory allocated for a buffer
	// In case if str is nullptr, free won't do anything
	C.free(unsafe.Pointer(str))
}