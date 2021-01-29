#include <inttypes.h>
#include <stddef.h>

void q_sort (int64_t* arr, size_t first, size_t last)
{
	if(first<last)
	{
		size_t left = first, right = last;
		int64_t mid = arr[(left + right) / 2];
		do
		{
			while(arr[left] < mid) ++left;
			while(arr[right] > mid) --right;

			if(left<=right)
			{
				int64_t tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				++left;
				--right;
			}
		} 
		while (left <= right);
		q_sort(arr, first, right);
		q_sort(arr, left, last);
	}
}
