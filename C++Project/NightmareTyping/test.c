#include <stdio.h>
#include <string.h>

int main(){

	char a[2] = "\b";
	char str1[10], str2[10];
	strcpy(str1, "hello");
	strcpy(str2, a);
	strcat(str1, str2);
	strcat(str1, "world");
	printf(str1);
	return 0;
}
//bell \a
//backone \b