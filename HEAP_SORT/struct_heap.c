#include "std.h"

extern double insert_time;
extern double delete_root_time;

void load_func( heap_ptr, char* );
void add_func( heap_ptr );
void print_func( heap_ptr );
void save_func( heap_ptr );
void free_memory( heap_ptr );
void insert(heap_ptr, int);

/*********** STRUCT CONSTRUCTOR ***************/
HEAP create_heap() {
	HEAP heap;
	int* data = (int*)malloc(N * sizeof(int));
	heap.load = (load_func_ptr)load_func;
	heap.add = (add_func_ptr)add_func;
	heap.print = (print_func_ptr)print_func;
	heap.save = (save_func_ptr)save_func;
	heap.free_memory = (free_memory_func_ptr)free_memory;

	heap.data = data;
	heap.size = 0;
	heap.factor = FACTOR;
	heap.limit = N;	
	
	return heap;
}
/*____________________________________________*/
//
/***************** MENU ***********************/
char* menu_items[] = {
	"a - add new data to the heap;",
	"p - print sorted heap;",
	"s - save sorted data to the file",
	"q - quit without saving",
	NULL,
};

void menu(heap_ptr ptr) {
	int choise = 0;
	FILE* input;
	FILE* output;
	char** option = NULL;

	struct termios init_set, mod_set;

	if (!isatty(STDIN_FILENO)) {
		fprintf(stderr, "You are not a terminal.\n");
		return;
	}

	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");

	if (!(input = fopen("/dev/tty", "r")) || 
		!(output = fopen("/dev/tty", "w")))  {
		fprintf(stderr, "Unable to open /dev/tty\n");
		return;
	}

	tcgetattr(fileno(input), &init_set);
	mod_set = init_set;
	mod_set.c_lflag &= ~ICANON;
	mod_set.c_lflag &= ~ECHO;
	mod_set.c_cc[VMIN] = 1;
	mod_set.c_cc[VTIME] = 0;
	mod_set.c_lflag &= ~ISIG;

	if (tcsetattr(fileno(input), TCSANOW, &mod_set) != 0) {
		fprintf(stderr, "Could not set attributes\n");
	}

	do {
		system("clear");
		option = menu_items;
		while(*option) {
			fprintf(output, "%s\n", *option);
			option++;
		}
		choise = my_getch();
		switch (choise) {
			case 'a':
				tcsetattr(fileno(input), TCSANOW, &init_set);
				(*ptr).add(ptr);
				tcsetattr(fileno(input), TCSANOW, &mod_set);
				break;
			case 'p':
				(*ptr).print(ptr);
				break;
			case 's':
				tcsetattr(fileno(input), TCSANOW, &init_set);
				(*ptr).save(ptr);
				tcsetattr(fileno(input), TCSANOW, &mod_set);
				break;
			case 'q':
				system("clear");
				printf("Quit...\n\t...Press any "
					"key to continue...");
				while( !_kbhit() ) {
					printf(".");
					fflush(stdout);
					usleep(200000);
				}
				my_getch();
				system("clear");
				break;	
		}

	
	} while (choise != 'q');

	tcsetattr(fileno(input), TCSANOW, &init_set);
	return;
}
/*____________________________________________*/
//
/*************** FUNCTIONS *******************/

void check_size(heap_ptr ptr) {
	if ((*ptr).size == (*ptr).limit - 1) {
		(*ptr).limit += (*ptr).factor;
		(*ptr).data = (int*)realloc((*ptr).data, 
			(*ptr).limit * sizeof(int));
	}
}

void insert(heap_ptr ptr, int value) {
	int i = (*ptr).size;
	int p, tmp;
	check_size(ptr);
	(*ptr).data[i] = value;
	while (i > 0) {
		p = (int)floor((i -1)/2.0);
		if ((*ptr).data[p] > (*ptr).data[i]) {
			tmp = (*ptr).data[i];
			(*ptr).data[i] = (*ptr).data[p];
			(*ptr).data[p] = tmp;
			i = p;
		} else {
			break;
		}
	}
	(*ptr).size++;
}

int delete_root( heap_ptr ptr ) {
	int c, tmp, t;
	int ret_val = (*ptr).data[0];
	register int i = 0;
	register size_t stop = (*ptr).size;

	t = (*ptr).data[0];
	(*ptr).data[0] = (*ptr).data[stop - 1];
	(*ptr).data[stop - 1] = t;
	(*ptr).size--;
	stop--;
	while (i < stop) {
		c = 2*i + 1;
		if (c >= stop)
			break;
		if (c + 1 < stop && (*ptr).data[c] > (*ptr).data[c + 1])
			c++;
		if ((*ptr).data[c] < (*ptr).data[i]) {
			tmp = (*ptr).data[c];
			(*ptr).data[c] = (*ptr).data[i];
			(*ptr).data[i] = tmp;
			i = c;
		} else {
			break;
		}
	}
	return ret_val;
}

void reverse( heap_ptr ptr ) {
	register int i;
	register int tmp;
	register int stop = (*ptr).size;
	for(i = 0; i < stop/2; ++i) {
		tmp = (*ptr).data[i];
		(*ptr).data[i] = (*ptr).data[stop - i - 1];
		(*ptr).data[stop - i - 1] = tmp;
	}
}

void load_func( heap_ptr ptr, char* file_name ) {
	FILE *F;
	int tmp;
	clock_t begin, end;
	if ((F = fopen(file_name, "rt")) == NULL) {
		fprintf(stderr, "Unable to open '%s'\n", file_name);
		return;
	}
	fscanf(F, "%d", &tmp);
	begin = clock();
	while(tmp) {
		insert(ptr, tmp);
		tmp = 0;	
		fscanf(F, "%d", &tmp);
	}
	end = clock();
	insert_time = (double)(end - begin) / CLOCKS_PER_SEC; 
}
void add_func( heap_ptr ptr ) {
	system("clear");
	printf("Addition\n");
	int value;
	printf("Enter value to add: ");
	scanf("%d", &value);
	insert(ptr, value);
	my_getch();
}

void print_func( heap_ptr ptr ) {
	clock_t begin, end;
	size_t tmp_size = (*ptr).size;
	system("clear");
	printf("Sorted array:\n");
	register size_t i;
	register size_t stop = (*ptr).size;
	begin = clock();
	for (i = 0; i < stop; ++i)
		printf("%d ", delete_root(ptr));
	end = clock();
	delete_root_time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nPress any key to continue...");
	while(!_kbhit() ) {
		printf(".");
		fflush(stdout);
		usleep(200000);
	}
	(*ptr).size = tmp_size;
	reverse( ptr );
	my_getch();
}
void save_func( heap_ptr ptr ) {
	char* result_file = (char*)malloc(40 * sizeof(char));
	system("clear");
	printf("Saving\n");
	printf("Enter filename to save data: ");
	scanf("%s", result_file);
	result_file = (char*)realloc(result_file, 
		strlen(result_file) * sizeof(char));

	register size_t i;
	register size_t stop = (*ptr).size;
	FILE *F;
	if((F = fopen(result_file, "wt")) == NULL) {
		fprintf(stderr, "Unable to open '%s'\n", result_file);
		return;
	}
	for (i = 0; i < stop; ++i) {
		fprintf(F, "%d ", delete_root(ptr));
	}
	fprintf(F, "\n");

	fclose(F);
	my_getch();
}
void free_memory( heap_ptr ptr ) {
	free((*ptr).data);
}
/*__________________________________________*/
