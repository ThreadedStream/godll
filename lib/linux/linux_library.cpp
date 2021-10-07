#include "linux_library.h"
#include <cstdlib>
#include <cstdio>
#include <defs.h>
#include <sys/utsname.h>

uint32_t extractKernelInfo(utsname** kernel_info) {
    if (!(*kernel_info)) {
        *kernel_info = static_cast<utsname*>(calloc(1, sizeof(utsname)));
        if (!(*kernel_info)) {
            return OUT_OF_MEMORY;
        }
    }

    return uname(*kernel_info);
}
