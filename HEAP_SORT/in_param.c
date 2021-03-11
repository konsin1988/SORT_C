#include "std.h"

int in_param(int argc, char** argv, char** file_name)
{
	if(argc<=1)
	{
		printf("\n\t%s requires name of the file with data "
				"as argument.\n"
			"\tSee '--help' for more information.\n", argv[0]);
	}
	else if(!strcmp(argv[1], "--help"))
	{
		print_help(argv);
	}
	else if( argc != 2 )
	{
		printf("\n\t%s requires only one argument - "
			"name of the file\n", argv[0]);	
	}
	else
	{
		(*file_name) = (char*)malloc(100 * sizeof(char));
		memcpy((*file_name), argv[1], strlen(argv[1]));
		(*file_name) = (char*)realloc((*file_name), 
			strlen((*file_name)) * sizeof(char));
		return 1;
	}
	return 0;
}

