#include <stdio.h>
#include <inttypes.h>

void array_1D_print(int64_t* arr, size_t N)
{
	for(size_t i=0; i<N; ++i)
		printf("%4d ", arr[i]);
	printf("\n");
}
