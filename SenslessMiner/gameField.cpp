#include <iostream>

#include "gameField.h"
#include "fieldGenerator.h"
#include "grass.h"
#include "rock.h"
#include "tree.h"
#include "soil.h"


GameField::GameField(unsigned int x, unsigned int y)
{
	FieldGenerator fieldGenerator(x,y);

	for (auto i = 0; i < x*y; i++) {
		unsigned int switchType = fieldGenerator.fieldGeneratorArray[i].type;
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
			break;
		case 3:
			field.push_back(rock);
			break;
		default:
			std::cout << "GameField Switch error";
			exit(-1);
			break;
		}
	}

}
