#include "std.h"

int _kbhit()
{
	static const int STDIN = 0;
	static bool initialized = false;

	if(!initialized)
	{
		//Use termios to turn off line buffering
		
		struct termios term;
		tcgetattr(STDIN, &term);
		term.c_lflag &= ~ICANON;
		tcsetattr(STDIN, TCSANOW, &term);
		setbuf(stdin, NULL);
		initialized = true;
	}

	int byteswaiting;
	ioctl(STDIN, FIONREAD, &byteswaiting);
	return byteswaiting;
}
