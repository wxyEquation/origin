#include <iostream>
//#include"Tic.h"4

class something{
public:
	something(){x=1;}
	int x;
};

class something2 : public something
{
public:
	something2(){x=0.5;y=1.5;}
	double x;
	double y;
};

int inf(){
	return 3;
}




int main(){
	
	something2 test;
	something2* p=&test;
	std::cout<<inf();

	
	return 0;
}