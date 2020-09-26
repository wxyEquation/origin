#include "interface.h"

struct game TicTree::childData(struct cordinate index) const
{
	setGame(tree_data);
	ticPlay(index.player, index.x, index.y);
	return getGame();
}

int TicTree::setValue()
{
	setGame(tree_data);
	return isWin();
}

bool TicTree::isEnd()
{
	setGame(tree_data);
	return isWin()!=0;
}

bool TicTree::setChilds()
{
	Piece next_player = tree_data.cur_player==circle?cross:circle;
	for (int i = 0; i < 3; ++i){
	for (int j = 0; j < 3; ++j){
		if(ticGet(i, j)==blank){childs.push_back({i, j, next_player});}
	}}
	return true;
}

