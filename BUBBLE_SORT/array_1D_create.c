#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

int64_t* array_1D_create(size_t N)
{
	return (int64_t*)malloc(N * sizeof(int64_t));
}
