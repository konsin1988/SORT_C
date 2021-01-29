#include <stdio.h>
#include <inttypes.h>
#include <stddef.h>
#include "my_getch.h"
#include "array_1D_create.h"
#include "random_filled_array.h"
#include "q_sort.h"
#include "array_1D_print.h"
#include "array_1D_free.h"
#include "yes_or_no.h"

int main(int argc, char** argv)
{
	size_t N;
	printf("Enter the number of items: \n");
	scanf("%zu", &N);
	int64_t* arr = array_1D_create(N);
	printf("Enter the LOWER and the UPPER element of\n"
		"random filled array (two decimal numbers \nwith SPACEBAR: x y):\n");
	int64_t LOWER, UPPER;
	scanf("%"SCNd64" %"SCNd64, &LOWER, &UPPER);
	random_filled_array(arr, N, LOWER, UPPER);
	printf("Do you want to print original array?(y/n)\n");
	if(yes_or_no())
	{
		printf("\nOriginal random genereted array:\n");
		array_1D_print(arr, N);
		printf("\n");
	}
	q_sort(arr, 0, N-1);
	printf("Do you want to print sorted array?(y/n)\n");
	if(yes_or_no())
	{
		printf("\nSorted (qsort) random genereted array:\n");
		array_1D_print(arr, N);
	}
	array_1D_free(arr);
	return 0;
}
