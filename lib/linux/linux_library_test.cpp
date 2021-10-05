#include "linux_library.h"
#include <cassert>
#include <dlfcn.h>
#include <cstdlib>
#include <cstdio>
#include <defs.h>

typedef uint32_t (*ExtractKernelInfoPtr) (utsname** kernel_info);

void testExtractKernelInfo() {
    const char* const library_path = "./libgodll.so";
    const char* const function_name = "extractKernelInfo";
    void * handle = dlopen(library_path, RTLD_LAZY);

    assert(handle != nullptr && "failed to load handle");

    const auto kernel_info_func = (ExtractKernelInfoPtr) (dlsym(handle, function_name));

    assert(kernel_info_func != nullptr && "failed to load function");

    utsname *kernel_info = nullptr;

    uint32_t return_value = kernel_info_func(&kernel_info);

    if (return_value != 0) {
        printf("exited with error code %d", return_value);
    }

    free(kernel_info);
    kernel_info = nullptr;
}


int main(int argc, const char* argv[]) {
    testExtractKernelInfo();
}
