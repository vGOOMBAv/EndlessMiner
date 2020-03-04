#pragma once
#include <vector>
#include "worldElem.h"
#include "player.h"

class GameBody{
public:
	size_t level = 1;
	void start(size_t x, size_t y, bool randomElemHealth, bool randomAmmountOfDroppedResources, bool newPlayer = 1);
	unsigned int spawnPlayer(std::vector<WorldElem>& field);
	void getPlayerName(Player& player);
};
