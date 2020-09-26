#ifndef GAME_TREE
#define GAME_TREE

#include <vector>

template<typename data, typename move=int, typename rating=double>
class GameTree
{
public:
	
	GameTree(data initial, GameTree* parent=NULL);
	virtual ~ GameTree();
	
	GameTree* toParent() const;
	virtual GameTree* toChild(move index) const;
	virtual data childData(move index) const =0;

	data getData() const    {return tree_data;}
	rating getValue() const {return value;}
	virtual bool   setData(data new_data) {tree_data = new_data; return true;}
	virtual bool   setValue(rating value) {this->value = value; return true;}
	
	virtual rating setValue()  =0;
	virtual bool   isEnd() =0;

	virtual bool setChilds() =0;
	std::vector<move> childs;

	virtual rating inf() const =0;
	virtual rating negInf() const =0;

protected:
	
	rating value;
	data tree_data;
	GameTree* parent;

};

#endif