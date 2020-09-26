#ifndef TIC_H

#define TIC_H

typedef enum piece{cross=-1, circle=1, blank=0}Piece;

struct game{
	int Row[3];
	int Col[3];
	int Dag[2];
	Piece Board[3][3];

	Piece cur_player;
};

Piece ticGet(int x, int y);

void ticReset();

bool ticPlay(Piece player, int x, int y);

Piece isWin();

struct game getGame();
void setGame(struct game curGame);


#endif