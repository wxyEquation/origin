#include "GameTree.h"

#define GT GameTree<data, move, rating>

template<typename data, typename move, typename rating>
GT::GameTree(data initial, GT* parent):
	parent(parent)
{
	setData(initial);
	setValue();
	setChilds();
}

template<typename data, typename move, typename rating>
GT* GT::toParent() const
{
	return parent;
}

template<typename data, typename move, typename rating>
GT* GT::toChild(move index) const
{
	return new GameTree(childData(index), this);
}

