#pragma once
#include <vector>
#include "worldElem.h"

class GameBody{
public:
	void start(size_t x, size_t y, bool randomElemHealth, bool randomAmmountOfDroppedResources);
	unsigned int spawnPlayer(std::vector<WorldElem>& field);
};
