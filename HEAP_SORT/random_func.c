#include "std.h"
#include <time.h>

#define RAND 10000000
#define MIN 1
#define MAX 1000000

int main( int argc, char** argv )
{
	FILE *F;
	if ((F = fopen("test.dat", "wt")) == NULL) {
		fprintf(stderr, "Unable to open 'test.dat'");
		exit(1);
	}
	srand(time(NULL));
	register size_t i = 0;
	for (; i < RAND; ++i) {
		fprintf(F, "%d ", rand() % (MAX - MIN) + MIN); 
	}

	return EXIT_SUCCESS;

}
