#include <stddef.h>

void insert_sort(int* arr, size_t p, size_t r)
{
	for(size_t i =p + 1; i<r; ++i)
	{
		int k = i;
		while(k>p && arr[k-1] > arr[k])
		{
			int tmp = arr[k-1];
			arr[k-1] = arr[k];
			arr[k] = tmp;
			k--;
		}
	}
}
