#include <iostream>
#include <time.h>
#include <math.h>

#include "gameField.h"
#include "fieldGenerator.h"
#include "grass.h"
#include "rock.h"
#include "tree.h"
#include "soil.h"

void GameField::generateNewField(size_t x, size_t y, bool randomElemHealth, bool randomAmmountOfDroppedResources, size_t level)
{
	if (field.empty() == false) {
		field.clear();
	}

	FieldGenerator fieldGenerator(x, y);

	for (auto i = 0; i < x * y; i++) {
		size_t switchType = fieldGenerator.fieldGeneratorArray[i].type;
		Soil soil;
		Grass grass;
		Tree tree;
		Rock rock;
		switch (switchType) {
		case 0:
			field.push_back(soil);
			break;
		case 1:
			field.push_back(grass);
			break;
		case 2:
			randomHealthSetter(tree, randomElemHealth, level);
			randomResDropSetter(tree, randomAmmountOfDroppedResources, level);
			field.push_back(tree);
			numberOfObstacles++;
			break;
		case 3:
			randomHealthSetter(rock, randomElemHealth, level);
			randomResDropSetter(rock, randomAmmountOfDroppedResources, level);
			field.push_back(rock);
			numberOfObstacles++;
			break;
		default:
			std::cout << "GameField Switch error";
			exit(-1);
			break;
		}
	}
}

void GameField::randomHealthSetter(WorldElem& fieldElem, bool randomElemHealth, size_t level)
{
	if (randomElemHealth == 1) {
		srand(time(NULL));
		fieldElem.elemHealth = size_t(rand() % level + 1 + log(level) / log(2));
	}
}

void GameField::randomResDropSetter(WorldElem& fieldElem, bool randomAmmountOfDroppedResources, size_t level)
{
	if (randomAmmountOfDroppedResources == 1) {
		fieldElem.droppedAmmountOfRes = rand() % level + 1;
	}
}
