#pragma once
#include "fieldGenerator.h"
#include "worldElem.h"
#include "tree.h"
#include "grass.h"
#include "rock.h"

class GameField {
public:
	GameField(unsigned int x, unsigned int y);
	std::vector<WorldElem> field;
};
