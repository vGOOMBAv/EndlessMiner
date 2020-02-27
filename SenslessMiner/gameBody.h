#pragma once
#include <vector>
#include "worldElem.h"

class GameBody{
public:
	void start(unsigned int x, unsigned int y);
	unsigned int spawnPlayer(std::vector<WorldElem>& field);
};
