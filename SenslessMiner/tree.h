#pragma once
#include "worldElem.h"

class Tree :public WorldElem {
public:
	unsigned int type = 2;
	bool canWalkThrough = 1;

};