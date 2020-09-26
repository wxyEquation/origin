#include "MinMax.h"
#include "Tic.h"

struct cordinate
{
	int x;
	int y;
	Piece player;
};

class TicTree: public GameTree<struct game, struct cordinate, int>
{
public:
	virtual struct game childData(struct cordinate index) const;
	virtual int setValue();
	virtual bool isEnd();
	virtual bool setChilds();
	virtual int inf() {return 2;};
	virtual int negInf() {return -2;}
};

