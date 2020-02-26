#include "fieldGenerator.h"
#include <time.h>

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
			
		}
	}
	
	
}

bool FieldGenerator::checkNearbyCells(unsigned int cellPosition)
{
	unsigned int cellPositionRow = cellPosition / y;
	unsigned int cellPositionColumn = cellPosition - cellPositionRow * x;
	
	return true;
}
