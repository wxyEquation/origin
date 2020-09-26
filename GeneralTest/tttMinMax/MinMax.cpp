#include "MinMax.h"

template<typename data, typename move, typename rating>
rating deepSearch(target goal, std::vector<move> prediction, GameTree<data, move, rating>* current, int depth)
{
	if(current->isEnd()||depth==0){
		return current->getValue();
	}

	move next  = current->childs.front();
	rating fin, now;
	if(goal == min)
	{
		now = current->inf();
		fin = now;
		for(move index : current->childs){
			now  = deepSearch(max, depth-1, current->toChild(index));
			if(now < fin){
				fin  = now;
				next = index;
			}
		}
	}
	else if(goal == max)
	{
		now = current->negInf();
		fin = now;
		for(move index : current->childs){
			now  = deepSearch(min, depth-1, current->toChild(index));
			if(now > fin){
				fin  = now;
				next = index;
			}
		}
	}

	prediction->push_back(next);
	return fin;
}

template<typename data, typename move, typename rating>
rating abPruning (target goal, std::vector<move> prediction, GameTree<data, move, rating>* current, rating a, rating b, int depth)
{
	if(current->isEnd()||depth==0){
		return current->getValue();
	}

	move next  = current->childs.front();
	rating fin, now;

	if(goal == min)
	{
		now = current->inf();
		fin = now;
		for(move index : current->childs){
			now  = deepSearch(max, depth-1, current->toChild(index));
			if(now < fin){
				fin  = now;
				next = index;
				if(a > fin){break;}
				if(b > fin){b = fin;}
			}
		}
	}
	else if(goal == max)
	{
		now = current->negInf();
		fin = now;
		for(move index : current->childs){
			now  = deepSearch(min, depth-1, current->toChild(index));
			if(now > fin){
				fin  = now;
				next = index;
				if(b < fin){break;}
				if(a < fin){a = fin;}
			}
		}
	}

	prediction->push_back(next);
	return fin;
}

template<typename data, typename move, typename rating>
rating abPruning (target goal, std::vector<move>* prediction, GameTree<data, move, rating>* current, int depth)
{
	return abPruning(goal, prediction, current, current->negInf(), current->inf(), depth);
}