#include <stdlib.h>
#include <time.h>

void random_filled_array(int A[], int N, int LOWER, int UPPER_RANGE)
{
	srand(time(NULL));
	for (int i=0; i<N; ++i)
	{
		int d = rand()%(UPPER_RANGE-LOWER) + LOWER;
		A[i] = d;
	}
}
