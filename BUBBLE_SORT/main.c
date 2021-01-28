#include <stdio.h>
#include <inttypes.h>
#include <stddef.h>
#include "my_getch.h"
#include "array_1D_create.h"
#include "array_1D_fill.h"
#include "bubble_sort.h"
#include "array_1D_print.h"
#include "array_1D_free.h"

int main(int argc, char** argv)
{
	size_t N;
	printf("Enter the number of items: \n");
	scanf("%zu", &N);
	int64_t* arr = array_1D_create(N);
	printf("Enter array items\n");
	array_1D_fill(arr, N);
	bubble_sort(arr, N);
	array_1D_print(arr, N);
	array_1D_free(arr);
	return 0;
}
