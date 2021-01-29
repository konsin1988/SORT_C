#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <stddef.h>

void random_filled_array(int64_t* A, size_t N, int64_t LOWER, int64_t UPPER_RANGE)
{
	srand(time(NULL));
	for (size_t i=0; i<N; ++i)
	{
		int64_t d = (int64_t)rand()%(UPPER_RANGE-LOWER) + LOWER;
		A[i] = d;
	}
}
