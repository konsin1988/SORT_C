#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "print_help.h"

int in_param(int argc, char** argv, size_t* n, int* MIN, int* MAX)
{
	if(argc <= 1)
	{
		printf("\n\t%s requires three parameters.\n"
			"\tSee '--help' for more information.\n", argv[0]);
		return 0;
	}
	else if(!strcmp(argv[1], "--help"))
	{
		print_help(argv[0]);
		return 0;
	}
	else if(argc != 4)
	{
		printf("\n\t%s requires three parameters.\n"
			"\tSee '--help' for more information.\n", argv[0]);
		return 0;
	}
	else if(sscanf(argv[1], "%zu", n) != 1 ||
		sscanf(argv[2], "%d", MIN)!= 1 || 
		sscanf(argv[3], "%d", MAX) != 1)
	{
		printf("%s function requires three "
			"integer params.\n", argv[0]);
		return 0;
	}
	else
	{
		return 1;
	}
}

