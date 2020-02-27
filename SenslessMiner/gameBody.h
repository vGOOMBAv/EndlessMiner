#pragma once
#include <vector>
#include "worldElem.h"

class GameBody{
public:
	void start(unsigned int x, unsigned int y);
	void spawnPlayer(std::vector<WorldElem>& field);
};
