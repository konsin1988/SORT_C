#include <stdio.h>
#include <stddef.h>
#include <string.h>

void array_print(char** str, size_t n)
{
	for(size_t i=0; i<n; ++i) {
		printf("%s\n", str[i]);
	}

}
