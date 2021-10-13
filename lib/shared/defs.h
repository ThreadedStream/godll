#pragma once


#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#endif

enum LinuxErrorCodes{
    NO_ERR = 0,
    LIB_NOT_FOUND = -2,
    FUNC_NOT_FOUND = -3,
    OUT_OF_MEMORY = -4,
};

struct kernel_info_wrapper {
   char *sysname;
   char *nodename;
   char *release;
   char *version;
   char *machine;
};

#ifdef _WIN32
static const char* getHumanReadableErrorDescription(const int32_t error) {
	switch (error) {
	case ERROR_FILE_NOT_FOUND:
		return "file not found";
	case ERROR_PROC_NOT_FOUND:
		return "procedure not found";
	case ERROR_OUTOFMEMORY:
		return "out of memory";
	case ERROR_SUCCESS:
		return "success";
	default:
		return "unknown error";
	}
}
#elif defined(__linux__)
static const char* getHumanReadableErrorDescription(const int32_t error) {
	switch (error) {
        case LIB_NOT_FOUND:
            return "library not found";
        case FUNC_NOT_FOUND:
            return "function not found";
        case OUT_OF_MEMORY:
            return "out of memory";
        case NO_ERR:
            return "success";
        default:
            return "unknown error";
    }
#endif