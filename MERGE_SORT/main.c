#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "arr_work.h"
#include "print_annotation.h"
#include "in_param.h"
#include "merge_sort.h"
#include "yes_no.h"

#define N 10000

size_t n;
int START, END;

int main(int argc, char** argv)
{
	if(in_param(argc, argv, &n, &START, &END))
	{
		int* arr = alloc_arr(N);
		print_annotation();
		fill_arr(arr, n, START, END);
		if(yes_no("initial", "print"))
			print_arr(arr, n);
		merge_sort(arr, 0, n);
		if(yes_no("sorted", "print"))
			print_arr(arr, n);
		if(yes_no("sorted", "write"))
			write_to_file(arr, n);
		free(arr);
	}

	return 0;
}




