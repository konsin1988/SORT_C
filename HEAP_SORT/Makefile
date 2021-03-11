obj=struct_heap.o std.o in_param.o print_help.o my_getch.o _kbhit.o
struct_heap: main.c $(obj)
	gcc $^ -o $@ -lm

clean:
	rm *.o
	
