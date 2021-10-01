#include "test.h"


int main() {
		
	DWORD maj, min, build; char* buffer = nullptr;
	getWindowsVersion(&maj, &min, &build, buffer);

	free(buffer);
	buffer = nullptr;


	return 0;
}