#include "counting_sort.h"

int push_array(int A[], int top, int x)
{
	A[top] = x;
	top += 1;
	return top;
}

void counting_sort(int A[], int N, int LOWER, int UPPER_RANGE)
{
	int counters[UPPER_RANGE];
	for (int i=0; i<UPPER_RANGE; ++i) counters[i] = 0;
	for(int i=0; i<N; ++i)
		counters[A[i]] += 1;
	int top = 0;
	for (int i=LOWER; i<UPPER_RANGE; ++i)
	{
		for(int j=0; j<counters[i]; ++j)
		{
			top = push_array(A, top, i);
		}
	}
}
