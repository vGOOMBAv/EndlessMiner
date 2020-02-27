#include "interface.h"
#include "basicFunctions.h"
#include <iostream>

void Interface::showField(const std::vector<WorldElem>& enteredVector, unsigned int xSize)
{
	clearScreen();
	auto xCheck = 0;
	for (auto i = 0; i < enteredVector.size(); i++) {
		showElement(enteredVector[i]);
		xCheck++;
		if (xCheck == xSize) {
			newline();
			newline();
			xCheck = 0;
		}
	}
}

void Interface::showElement(WorldElem worldElem)
{
	switch (worldElem.type) {
	case 0:
		if (worldElem.playerPosition == false) {
			std::cout << "S";
			space();
			break;
		}
		else {
			std::cout << "P";
			space();
			break;
		}
	case 1:
		if (worldElem.playerPosition == false) {
			std::cout << "G";
			space();
			break;
		}
		else {
			std::cout << "P";
			space();
			break;
		}
	case 2:
		if (worldElem.playerPosition == false) {
			std::cout << "T";
			space();
			break;
		}
		else {
			std::cout << "P";
			space();
			break;
		}
	case 3:
		if (worldElem.playerPosition == false) {
			std::cout << "R";
			space();
			break;
		}
		else {
			std::cout << "P";
			space();
			break;
		}
	default:
		std::cout << "Interface Switch error";
		exit(-1);
		break;
	}
}
