#pragma once
#include "fieldGenerator.h"
#include "worldElem.h"
#include "tree.h"
#include "grass.h"
#include "rock.h"

class GameField {
public:
	void generateNewField(size_t x, size_t y, bool randomElemHealth, bool randomAmmountOfDroppedResources, size_t level);
	std::vector<WorldElem> field;
	size_t numberOfObstacles = 0;
	void randomHealthSetter(WorldElem& fieldElem, bool randomElemHealth, size_t level);
	void randomResDropSetter(WorldElem& fieldElem, bool randomAmmountOfDroppedResources, size_t level);

};
