#pragma once
#include <stddef.h>

void random_filled_array(int* A, int** ptr, int N, 
		int LOWER, int UPPER_RANGE);
void without_changing(int** ptr, size_t n);
void print_arr(int* arr, size_t n);
void print_arr_ptr(int** ptr, size_t n);
