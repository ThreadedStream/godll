#pragma once

#include <cstdint>
#include <sys/utsname.h>


typedef struct kernel_info_wrapper kernel_info_wrapper_t;

extern "C" __attribute__((visibility("default"))) uint32_t extractKernelInfo(utsname** kernel_info);
