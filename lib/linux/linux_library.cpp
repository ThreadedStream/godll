#include "linux_library.h"
#include <cstdlib>
#include <defs.h>

uint32_t extractKernelInfo(utsname** kernel_info) {
    if (!(*kernel_info)) {
        *kernel_info = (utsname*) calloc(1, sizeof(utsname));
        if (!(*kernel_info)) {
            return OUT_OF_MEMORY;
        }
    }
    return uname(*kernel_info);
}
