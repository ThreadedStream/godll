package main

// #cgo CFLAGS: -g -Wall
// #cgo LDFLAGS: -ldl
// #include <dlfcn.h>
// #include <sys/utsname.h>
// #include <stdio.h>
// #include <stdint.h>
// #include <stdlib.h>
// #include "lib/shared/defs.h"
//
// typedef struct utsname utsname_t;
// typedef uint32_t (*ExtractKernelInfoPtr) (utsname_t** kernel_info);
//
// uint32_t getLinuxKernelInfo(utsname_t** kernel_info) {
//     const char* const library_path = "build/libgodll.so";
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

func convertCharArrToByteArr(charPtr unsafe.Pointer, arrSize int) []byte{
    var out []byte = make([]byte, arrSize)
    for i := 0; i < arrSize; i++ {
        out[i] = *( (*byte) (unsafe.Pointer(uintptr(charPtr) + uintptr(i))) )
    }

    return out
}

func main() {
    var (
        kernel_info_wrapper *C.utsname_t
        ret = C.getLinuxKernelInfo(&kernel_info_wrapper)
    )
    if ret != 0{

       fmt.Printf("failed to get linux kernel info, reason: %s", ret)
       C.free(unsafe.Pointer(kernel_info_wrapper))
       return
    }

    // sysname's dedicated block
    var (
        sysNameSize     =   (int) (C._UTSNAME_SYSNAME_LENGTH)
        sysNamePtr      =   unsafe.Pointer(&kernel_info_wrapper.sysname[0])
        sysName []byte  =   convertCharArrToByteArr(sysNamePtr, sysNameSize)
    )

    // nodename's dedicated block
    var (
        nodeNameSize    =   (int) (C._UTSNAME_NODENAME_LENGTH)
        nodeNamePtr     =   unsafe.Pointer(&kernel_info_wrapper.nodename[0])
        nodeName []byte =   convertCharArrToByteArr(nodeNamePtr, nodeNameSize)
    )

    // release's dedicated block
    var (
        releaseSize     =   (int) (C._UTSNAME_RELEASE_LENGTH)
        releasePtr      =   unsafe.Pointer(&kernel_info_wrapper.release[0])
        release []byte  =   convertCharArrToByteArr(releasePtr, releaseSize)
    )

    // version's dedicated block
    var (
        versionSize     =   (int) (C._UTSNAME_VERSION_LENGTH)
        versionPtr      =   unsafe.Pointer(&kernel_info_wrapper.version[0])
        version []byte  =   convertCharArrToByteArr(versionPtr, versionSize)
    )

    // machine's dedicated block
    var (
        machineSize     =   (int) (C._UTSNAME_MACHINE_LENGTH)
        machinePtr      =   unsafe.Pointer(&kernel_info_wrapper.machine[0])
        machine []byte  =   convertCharArrToByteArr(machinePtr, machineSize)
    )

    fmt.Printf("System name: %s\n", string(sysName))
    fmt.Printf("Node name: %s\n", string(nodeName))
    fmt.Printf("Release: %s\n", string(release))
    fmt.Printf("Version: %s\n", string(version))
    fmt.Printf("Machine: %s\n", string(machine))


    C.free(unsafe.Pointer(kernel_info_wrapper))
}