#ifndef MINMAX_H

#include "GameTree.h"

enum target
{
	min=-1,
	max= 1,
};

template<typename data, typename move=int, typename rating=double>
rating deepSearch(target goal, std::vector<move>* prediction, GameTree<data, move, rating>* current, int depth = -1);

template<typename data, typename move=int, typename rating=double>
rating abPruning (target goal, std::vector<move>* prediction, GameTree<data, move, rating>* current, int depth = -1);

template<typename data, typename move=int, typename rating=double>
rating abPruning (target goal, std::vector<move> prediction, GameTree<data, move, rating>* current, rating a, rating b, int depth = -1);


#define MINMAX_H
#endif