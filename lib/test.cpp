#include "test.h"
#include <stdio.h>



int main(int argc, const char* argv[]) {

    DWORD maj, min, build; char* buffer = nullptr;
    const auto res = getWindowsVersion(&maj, &min, &build, &buffer);

    printf("%s", buffer);

    return 0;
}