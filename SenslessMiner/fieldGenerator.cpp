#include "fieldGenerator.h"
#include <time.h>

FieldGenerator::FieldGenerator(unsigned int x, unsigned int y)
{
	for (auto i=0; i < x * y; i++) {
		GeneratorWorldElem generatorWorldElem;
		fieldGeneratorArray.push_back(generatorWorldElem);
	}
	srand(time(NULL));
	
}

void FieldGenerator::generateElement()
{
}
