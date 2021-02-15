#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "in_param.h"
#include "arr_work.h"

// The size of the array
size_t n;

// Min and max of random function
int MIN, MAX;

int main(int argc, char** argv)
{
	if(in_param(argc, argv, &n, &MIN, &MAX))
	{
		int* arr = (int*)malloc(n * sizeof(int));
		random_filled_array(arr, n, MIN, MAX);
		print_arr(arr, n);
		shell_sort(arr, n);
		print_arr(arr, n);
		free(arr);
	}
	return 0;
}
	
