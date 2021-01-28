#include <stdio.h>
#include <stdlib.h>

void array_fill(char** str, size_t n)
{
	for(size_t i=0; i<n; ++i)
		scanf("%s", str[i]);
}
