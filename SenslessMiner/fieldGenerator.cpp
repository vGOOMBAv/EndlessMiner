#include "fieldGenerator.h"
#include <time.h>
#include <math.h>
#include <iostream>

#include "soil.h"
#include "grass.h"
#include "tree.h"
#include "rock.h"

FieldGenerator::FieldGenerator(unsigned int xE, unsigned int yE)
{
	x = xE;
	y = yE;
	for (auto i=0; i < x * y; i++) {
		GeneratorWorldElem generatorWorldElem;
		fieldGeneratorArray.push_back(generatorWorldElem);
	}

	auto ammounOfColumns = x;
	auto ammounOfRows = y;
	auto sizeOfField = ammounOfColumns * ammounOfRows;
	srand(time(NULL));

	if (sizeOfField == 1) {
		fieldGeneratorArray[0].statusOfGeneration = 1;
		fieldGeneratorArray[0].type = 0;
	}
	else {
		for (auto i = 0; i < sizeOfField; i++) {
			auto typeRAND = rand() % 4;
			if (typeRAND == 0 || typeRAND == 1) {
				fieldGeneratorArray[i].type = typeRAND;
				fieldGeneratorArray[i].statusOfGeneration = 1;
			}
			if (typeRAND == 2 || typeRAND == 3) {
				if (checkNearbyCells(i)) {
					fieldGeneratorArray[i].type = typeRAND;
					fieldGeneratorArray[i].statusOfGeneration = 1;
				}
				else {
					typeRAND = rand() % 2;
					fieldGeneratorArray[i].type = typeRAND;
					fieldGeneratorArray[i].statusOfGeneration = 1;
				}
			}
		}
	}

	for (auto i = 0; i < sizeOfField; i++) {
		unsigned int switchType = fieldGeneratorArray[i].type;
		Soil soil;
		Grass grass;
		Tree tree;
		Rock rock;
		switch (switchType) {
		case 0:
			fieldGeneratorEndArray.push_back(soil);
			break;
		case 1:
			fieldGeneratorEndArray.push_back(grass);
			break;
		case 2:
			fieldGeneratorEndArray.push_back(tree);
			break;
		case 3:
			fieldGeneratorEndArray.push_back(rock);
			break;
		default:
			std::cout << "Field generator Switch error";
			exit(-1);
			break;
		}
	}
}

FieldGenerator::FieldGenerator()
{
	x = 8;
	y = 5;
}

bool FieldGenerator::checkNearbyCells(unsigned int cellPosition)
{
	unsigned int truthCounter = 0;
	std::cout << cellPosition << std::endl;
	unsigned int cellPositionRow = cellPosition / x;
	std::cout << "cellPositionRow: " << cellPositionRow << std::endl;
	unsigned int cellPositionColumn = cellPosition - cellPositionRow * x;
	std::cout << "cellPositionColumn: " << cellPositionColumn << std::endl;
	//right check
	if (cellPositionColumn != x-1) {
		if (
			fieldGeneratorArray[cellPosition + 1].type == 1 ||
			fieldGeneratorArray[cellPosition + 1].type == 2
			){
				truthCounter++;
			}
	}
	//left check
	if (cellPositionColumn != 0) {
		if (
			fieldGeneratorArray[cellPosition - 1].type == 1 ||
			fieldGeneratorArray[cellPosition - 1].type == 2
			) {
			truthCounter++;
			}
	}
	//up check
	if (cellPositionRow != 0) {
		if (
			fieldGeneratorArray[cellPosition - x].type == 1 ||
			fieldGeneratorArray[cellPosition - x].type == 2
			) {
			truthCounter++;
		}
	}
	//down check
	if (cellPositionRow != y-1) {
		if (
			fieldGeneratorArray[cellPosition + x].type == 1 ||
			fieldGeneratorArray[cellPosition + x].type == 2
			) {
			truthCounter++;
		}
	}
	
	if (truthCounter != 0) {
		return true;
	}
	else {
		return false;
	}

}

void FieldGenerator::debug()
{
	for (auto i = 0; i < x * y; i++) {
		std::cout << "i: " << i << std::endl;
		unsigned int cellPositionRow = i / x;
		std::cout << "cellPositionRow: " << cellPositionRow << std::endl;
		unsigned int cellPositionColumn = i - cellPositionRow * x;
		std::cout << "cellPositionColumn: " << cellPositionColumn << std::endl;
	}
}

