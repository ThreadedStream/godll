package main

// #include "lib/test.h"
import "C"

import (
	"fmt"
	"unsafe"
)

func main() {
	var (
		majorVersion, minorVersion, buildNumber C.DWORD
		str *C.char
		ret = C.getWindowsVersion(&majorVersion, &minorVersion, &buildNumber, str)
	)
	var returnValue = (int) (ret)

	if returnValue == 0{
		fmt.Printf("%d.%d.%d", (int) (majorVersion), (int) (minorVersion), (int) (buildNumber))
	} else {
		fmt.Printf("error code: %d", returnValue)
	}

	// NOTE(threadedstream): free the memory allocated for a buffer
	C.free(unsafe.Pointer(str))
}