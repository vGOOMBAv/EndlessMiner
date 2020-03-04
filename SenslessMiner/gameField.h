#pragma once
#include "fieldGenerator.h"
#include "worldElem.h"
#include "tree.h"
#include "grass.h"
#include "rock.h"

class GameField {
public:
	void generateNewField(size_t x, size_t y, bool randomElemHealth, bool randomAmmountOfDroppedResources);
	std::vector<WorldElem> field;
	size_t numberOfObstacles = 0;
};
