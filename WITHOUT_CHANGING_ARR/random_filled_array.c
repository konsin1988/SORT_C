#include <stdlib.h>
#include <time.h>

void random_filled_array(int* A, int** ptr, int N, int LOWER, int UPPER_RANGE)
{
	int i;
	srand(time(NULL));
	for (i=0; i<N; ++i)
	{
		A[i] = rand()%(UPPER_RANGE-LOWER) + LOWER;
		ptr[i] = &A[i];
	}

	
}
