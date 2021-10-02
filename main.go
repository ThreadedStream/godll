package main

// #include "lib/test.h"
import "C"

import (
	"fmt"
	"unsafe"
)

func main() {
	var majorVersion, minorVersion, buildNumber C.DWORD
	var str *C.char
	var ret = C.getWindowsVersion(&majorVersion, &minorVersion, &buildNumber, str)

	if (int)(ret) == 0{
		fmt.Printf("%d.%d.%d", (int) (majorVersion), (int) (minorVersion), (int) (buildNumber))
	} else {
		fmt.Printf("err_code: %d", (int) (ret))
	}

	// NOTE(threadedstream): free the memory allocated for a buffer
	C.free(unsafe.Pointer(str))
}