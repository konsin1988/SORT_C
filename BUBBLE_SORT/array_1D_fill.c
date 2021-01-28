#include <inttypes.h>
#include <stdio.h>

void array_1D_fill(int64_t* arr, size_t N)
{
	for(size_t i=0; i<N; ++i)
		scanf("%"SCNd64, &arr[i]);
}
