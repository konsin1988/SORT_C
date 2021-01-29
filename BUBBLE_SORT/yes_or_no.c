#include <stdbool.h>
#include "my_getch.h"

bool yes_or_no ()
{
	char key = my_getch();
	do
	{
		if(key=='y') return true;
		else if(key=='n') return false;
		else key=my_getch();
	}
	while (1);
}
