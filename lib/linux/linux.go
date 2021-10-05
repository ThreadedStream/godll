package main

// #cgo CFLAGS: -g -Wall
// #cgo LDFLAGS: -ldl
// #include <dlfcn.h>
// #include <sys/utsname.h>
// #include <stdio.h>
// #include <stdint.h>
// #include <stdlib.h>
// #include "../shared/defs.h"
// typedef struct {
//   struct utsname * kernel_info;
// }pooper;
//
// typedef uint32_t (*ExtractKernelInfoPtr) (struct utsname** kernel_info);
//
// uint32_t getLinuxKernelInfo(struct utsname** kernel_info) {
//     const char* const library_path = "../cmake-build-debug/libgodll.so";
//     const char* const function_name = "extractKernelInfo";
//     void * handle = dlopen(library_path, RTLD_NOW);
//     if (!handle){
//       return LIB_NOT_FOUND;
//     }
//     const ExtractKernelInfoPtr kernel_info_func = (ExtractKernelInfoPtr) (dlsym(handle, function_name));
//     if (!kernel_info_func) {
//       return FUNC_NOT_FOUND;
//     }
//
//     uint32_t return_value = kernel_info_func(kernel_info);
//
//     return return_value;
// }
import "C"

import (
     "fmt"
     "unsafe"
)


func main() {
    var (
        pooper C.pooper
        ret = C.getLinuxKernelInfo(&pooper.kernel_info)
    )

    var returnValue = (int) (ret)

    var castValue = (*C.char) (pooper.kernel_info.sysname)
    if ret == 0{
        fmt.Printf("sysname: %s", C.GoString(castValue))
    } else {
        fmt.Printf("error exited with code %d", returnValue)
    }

    C.free(unsafe.Pointer(pooper.kernel_info))
}