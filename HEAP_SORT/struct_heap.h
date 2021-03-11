#pragma once

#define N 100000
#define FACTOR 100000

typedef struct HEAP* heap_ptr;

typedef const char* (*load_func_ptr)( heap_ptr, char* );
typedef const char* (*add_func_ptr)( heap_ptr );
typedef const char* (*print_func_ptr)( heap_ptr );
typedef const char* (*save_func_ptr)( heap_ptr );
typedef const char* (*free_memory_func_ptr)( heap_ptr );

/************* HEAP struct ********************/
struct HEAP
{
	load_func_ptr load;
	add_func_ptr add;
	print_func_ptr print;
	save_func_ptr save;
	free_memory_func_ptr free_memory;

	int* data;
	size_t size;
	size_t factor;	/* the value by which the array will
			   grow in case of overflow */
	size_t limit;	/* max number of elements; if overflow, 
			   the array will grow by factor number */
};
typedef struct HEAP HEAP;
/*_________________________________________*/
//
/************** struct constructor **********/
HEAP create_heap();

int in_param( int, char**, char**);
void print_help( char** argv );
void menu(heap_ptr);
int my_getch();
int _kbhit();
