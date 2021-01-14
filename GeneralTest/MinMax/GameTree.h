#ifndef GAME_TREE
#define GAME_TREE

#include <vector>

template<typename data, typename move=int, typename rating=double>
class GameTree
{
public:
	
	GameTree(data initial, GameTree* parent=NULL);
	virtual ~ GameTree();
	
	GameTree* toParent() const {return parent;}
	rating    getValue() const {return value;}
	data      getData()  const {return tree_data;}

	virtual bool setData(data new_data) {tree_data = new_data; return true;}
	virtual bool setValue(rating value) {this->value = value; return true;}
	
	virtual GameTree* toChild(move index) const;
	virtual data childData(move index) const =0;
	
	virtual rating setValue()  =0;
	virtual bool   isEnd()     =0;
	virtual bool   setChilds() =0;
	
	virtual rating inf()    const =0;
	virtual rating negInf() const =0;

	std::vector<move> childs;

protected:
	
	rating value;
	data tree_data;
	GameTree* parent;

};

#endif