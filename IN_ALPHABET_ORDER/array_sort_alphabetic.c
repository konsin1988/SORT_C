#include <stdlib.h>
#include <string.h>

void array_sort_alphabetic(char** str, size_t n, size_t M)
{
	for(size_t k=0; k<n; ++k)
	{
		for(size_t i=0; i<n-1; ++i)
		{
			if(strcmp(str[i], str[i+1]) > 0)
			{
				char* tmp = str[i];
				str[i] = str[i+1];
				str[i + 1] = tmp;
			}
		}
	}

}
