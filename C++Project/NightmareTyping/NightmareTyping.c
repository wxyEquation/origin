#include <conio.h>
#include <stdio.h>
#include <string.h>

int main(){
	char a = '	';
	while(a != 'q'){
		a = getch();
		putchar(a);
	}
	return 0;
}

char row0[15] = "`1234567890-=\b";
char row1[15] = "\tqwertyuiop[]\\";
char row2[15] = "asdfghjkl;'\n\v\v";
char row3[15] = "zxcvbnm,./\v\v\v\v";
char keyboard[15][4] = {row0, row1, row2, row3}; 

char misplaced(char a, double p){
	char* position = NULL;
	int row = -1;
	while(position != NULL){
		char* position = strchr(keyboard[i], a);
		row++;
	}
	return a;
}