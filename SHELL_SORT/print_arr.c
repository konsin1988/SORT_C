#include <stdio.h>

void print_arr(int* arr, size_t n)
{
	for(size_t i=0; i<n; ++i)
	{
		printf("%3d ", arr[i]);
	}
	printf("\n");
}
