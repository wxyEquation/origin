#include"Tic.h"

static struct game inGame;

Piece ticGet(int x, int y){
	return inGame.Board[x][y];
}

void ticReset(){
	int* p = inGame.Row;
	for(int i=0; i<17; i++){
		*(p+i)=0;
	}
}

bool ticPlay(Piece player, int x, int y){
	if(inGame.Board[x][y]==0){
		
		inGame.Board[x][y]=player;
		
		inGame.Col[x]+=player;
		inGame.Row[y]+=player;
		x==y?(inGame.Dag[0]+=player):0;
		x==(2-y)?(inGame.Dag[1]+=player):0;
		inGame.cur_player = inGame.cur_player==circle?cross:circle; 

		return 1;

	}else{
		return 0;
	}
	
}

Piece isWin() {
	int* p = inGame.Row;
	int count;
	for(int i=0; i<8; i++){
		count=*(p+i);
		switch(count){
			case  3: return circle;
			case -3: return cross; 
			default: break;
		}
	}
	return blank;
}

struct game getGame() {return inGame;}
void setGame(struct game curGame) {inGame = curGame;}
