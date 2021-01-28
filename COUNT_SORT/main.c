#include <stdio.h>
#include "counting_sort.h"
#include "random_filled_array.h"
#include "print_array.h"

int main(int argc, char* argv[])
{
	//Ввод условия
	int N;
	int LOWER, UPPER_RANGE;
	printf("Enter the arrow's range: \n");
	scanf("%d", &N);
	int A[N];
	printf("Enter LOWER and UPPER numbers of RANDOM function: \n");
	scanf("%d%d", &LOWER, &UPPER_RANGE);
	random_filled_array(A, N, LOWER, UPPER_RANGE);
	printf("***Original array***\n");
	print_array(A, N);
	counting_sort(A, N, LOWER, UPPER_RANGE);
	printf("***Sorted array***\n");
	print_array(A, N);
	return 0;
}
