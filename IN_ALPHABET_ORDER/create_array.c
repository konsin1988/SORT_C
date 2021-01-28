#include <stdlib.h>

char** create_array(size_t N, size_t M)
{
	char** A = malloc(N * sizeof(char*) + N * M * sizeof(char));
	char* start =(char*)A + N * sizeof(char*);
	for(int i=0; i<N; ++i)
		A[i] = start + i * M;
	return A;

}
