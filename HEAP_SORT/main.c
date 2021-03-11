#include "std.h"

char* file_name = NULL;		/* load data from */
double insert_time;
double delete_root_time;

int main(int argc, char** argv)
{
	if (in_param(argc, argv, &file_name)) {
		HEAP heap = create_heap();
		heap.load(&heap, file_name);
		menu(&heap);
		heap.free_memory(&heap);
		printf("Costs of heap sorting (N = 10000000, min item = 1\n"
				"max item = 1000000), data was created "
				"by rand() function:"
			"\n\t- insert_time: %lf sec."
			"\n\t- delete_root_time: %lf sec.\n", 
			insert_time, delete_root_time);
	}
	my_getch();
	system("clear");

	return EXIT_SUCCESS;
}
	
