#include <stddef.h>

void shell_sort(int* arr, size_t n)
{
	//Steps used in sorting
	int steps[4] = { 15, 7, 3, 1 }; 
	int tmp;

	// choose step
	//for(size_t k=n/2; k>0; k/=2)
	for(size_t s=0; s<4; ++s)
	{
		int k = steps[s];
		// choose array
		for(size_t i=k; i<n; ++i)
		{
			size_t j=i;
			while(j>=k && arr[j] < arr[j-k])
			{
				tmp = arr[j];
				arr[j] = arr[j-k];
				arr[j-k] = tmp;
				j-=k;
			}
		}
	}
}
