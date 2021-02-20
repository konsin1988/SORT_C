#include <stdio.h>

void print_arr_ptr(int** ptr, size_t n)
{
	for(size_t i=0; i<n; ++i)
	{
		printf("%3d ", *ptr[i]);
	}
	printf("\n");
}
