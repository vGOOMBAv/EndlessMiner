#pragma once
#include "worldElem.h"
#include <vector>

class Interface {
public:
	//void showInterface();
	void showField(const std::vector<WorldElem>& enteredVector, unsigned int xSize);
	void showElement(WorldElem worldElem);
};
