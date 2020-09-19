#include<stdio.h>
#include"Tic.h"

void printout(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d ", ticGet(i,j));
		}
		printf("\n");
	}
}

int main(){
	int x, y;
	while(isWin()==blank){

		printout();
		printf("please select\n");
		do{scanf("%d,%d",&x,&y);}while(!ticPlay(circle,x,y));
		
	}
	
	return 0;
}