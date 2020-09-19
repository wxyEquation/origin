#ifndef TIC_H

#define TIC_H

typedef enum piece{cross=-1, circle=1, blank=0}Piece;

struct game{
	int Row[3];
	int Col[3];
	int Dag[2];
	int Board[3][3];
};

Piece ticGet(int x, int y);

void ticReset();

_Bool ticPlay(Piece player, int x, int y);

Piece isWin();



#endif