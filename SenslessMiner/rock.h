#pragma once
#include "worldElem.h"

class Rock :public WorldElem {
public:
	unsigned int type = 3;
	bool canWalkThrough = 1;

};