#pragma once

#include <termios.h>
#include <unistd.h>

class BufferToggle{
	struct termios t;
public:
	void off(void){
		tcgetattr(STDIN_FILENO, &t); 
		t.c_lflag &= ~ICANON; 
		tcsetattr(STDIN_FILENO, TCSANOW, &t);
	}

	void on(void){
		tcgetattr(STDIN_FILENO, &t); 
		t.c_lflag |= ICANON;
		tcsetattr(STDIN_FILENO, TCSANOW, &t);
	}
};
