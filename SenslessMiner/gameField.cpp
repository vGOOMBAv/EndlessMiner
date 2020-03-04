#include <iostream>

#include "gameField.h"
#include "fieldGenerator.h"
#include "grass.h"
#include "rock.h"
#include "tree.h"
#include "soil.h"

void GameField::generateNewField(size_t x, size_t y, bool randomElemHealth, bool randomAmmountOfDroppedResources)
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
			field.push_back(tree);
			numberOfObstacles++;
			break;
		case 3:
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
