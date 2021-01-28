#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "create_array.h"
#include "read_number.h"
#include "array_fill.h"
#include "array_sort_alphabetic.h"
#include "array_print.h"
#include "array_free.h"

#define N 100
#define M 30

int main(int argc, char** argv)
{
	char** str = create_array(N, M);
	size_t n; 
	read_number(&n); 
	array_fill(str, n);
	printf("\n");
	array_sort_alphabetic(str, n, M);
	printf("Sorted array:\n");
	array_print(str, n);
	array_free(str);
	return 0;
}
