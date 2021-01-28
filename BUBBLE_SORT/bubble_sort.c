#include <inttypes.h>
#include <stddef.h>
void bubble_sort (int64_t* arr, size_t N)
{
	for(size_t i=0; i<N; ++i)
	{
		for(size_t j=0; j<N-1; ++j)
		{
			if(arr[j] > arr[j+1])
			{
				int64_t tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
