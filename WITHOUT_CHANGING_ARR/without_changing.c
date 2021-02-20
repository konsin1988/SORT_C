#include <stddef.h>

void without_changing( int** ptr, size_t n )
{
	int* tmp = NULL;
	for( size_t i=1; i<n; ++i )
	{
		size_t j = i;
		while( j>0 && *ptr[j] < *ptr[j-1] )
		{
			tmp = ptr[j];
			ptr[j] = ptr[j-1];
			ptr[j-1] = tmp;
			--j;
		}
	}
}
