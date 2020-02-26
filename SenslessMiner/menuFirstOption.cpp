#include "menuFirstOption.h"
#include <iostream>
#include "basicFunctions.h"
#include "gameBody.h"

void MenuFirstOption::showOption()
{
	unsigned int x=0;
	unsigned int y=0;
	
	fieldSizeGetter(x, "x");
	std::cin.clear();
	fieldSizeGetter(y, "y");

	GameBody gameBody;
	gameBody.start(x, y);

}

void MenuFirstOption::showMessage(std::string variableName) {
	clearScreen();
	if (errorStatus == 1)std::cout << errorReason << std::endl;
	std::cout << "Please enter " << variableName << " size of the field: ";
}

void MenuFirstOption::fieldSizeGetter(unsigned int& variable, std::string variableName)
{
	std::string buff;
	showMessage(variableName);
	std::cin >> buff;

	bool noZeroCheck = 0;//Checks if there are other digits in the number except 0
	errorStatus = 0;
	for (auto i = 0; i < buff.size(); i++) {
		unsigned int stringElementNumber = 0;
		stringElementNumber = (int)buff[i];
		if (!(stringElementNumber >= 48 && stringElementNumber <= 57)) {
			errorStatus = 1;
			errorReason = "Please use pozitiv numbers";
			break;
		}
		if (stringElementNumber != 48)noZeroCheck++;
	}
	
	if (errorStatus != 1) {
		if (noZeroCheck != 0) {
			variable = std::stoi(buff);
			errorStatus = 0;
		}
		else {
			errorStatus = 1;
			errorReason = "Please use not null value";
		}
	}

	if (errorStatus == 1) {
		fieldSizeGetter(variable, variableName);
	}
}



