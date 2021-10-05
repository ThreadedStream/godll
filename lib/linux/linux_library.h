#pragma once

#include <sys/utsname.h>
#include <cstdint>


extern "C" __attribute__((visibility("default"))) uint32_t extractKernelInfo(utsname** kernel_info);
