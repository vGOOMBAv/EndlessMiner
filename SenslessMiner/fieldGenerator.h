#pragma once
#include <vector>
#include "generatorWorldElem.h"
#include "worldElem.h"
#include "tree.h"
#include "grass.h"
#include "rock.h"

class FieldGenerator {
private:
	bool randomElemHealth = 0;
	bool randomElemDrop = 0;
public:
	std::vector<GeneratorWorldElem> fieldGeneratorArray;
	FieldGenerator(unsigned int x, unsigned int y);
	void generateElement();
};
