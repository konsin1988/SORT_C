#include <stdio.h>
#include "print_array.h"
void print_array(int A[], int N)
{
	for(int i = 0; i<N; ++i) printf("%3d ", A[i]);
	printf("\n");
}
