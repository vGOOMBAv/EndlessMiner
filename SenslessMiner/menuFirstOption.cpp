#include "menuFirstOption.h"
#include <iostream>
#include "basicFunctions.h"
#include "gameBody.h"

void MenuFirstOption::showOption()
{
	size_t x = 0;
	size_t y = 0;
	bool randomElemHealth = 0;
	bool randomAmmountOfDroppedResources = 0;
	
	fieldSizeGetter(x, "x");
	std::cin.clear();
	fieldSizeGetter(y, "y");
	std::cin.clear();
	fieldRandomGetter(randomElemHealth, "random ammount of health of field elements");
	std::cin.clear();
	fieldRandomGetter(randomAmmountOfDroppedResources, "random ammount of dropped resources");

	GameBody gameBody;
	gameBody.start(x, y, randomElemHealth, randomAmmountOfDroppedResources);

}

void MenuFirstOption::showMessageSize(std::string variableName) {
	clearScreen();
	if (errorStatus == 1)std::cout << errorReason << std::endl;
	std::cout << "Please enter " << variableName << " size of the field: ";
}

void MenuFirstOption::fieldSizeGetter(unsigned int& variable, std::string variableName)
{
	std::string buff;
	showMessageSize(variableName);
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
void MenuFirstOption::fieldRandomGetter(bool variable, std::string variableName)
{
	errorReason = "Please use only 0 or 1";
	std::string buff;
	showMessageRandomGetter(variableName);
	std::cin >> buff;
	size_t boolCheck;

	errorStatus = 0;
	for (auto i = 0; i < buff.size(); i++) {
		unsigned int stringElementNumber = 0;
		stringElementNumber = (int)buff[i];
		if (!(stringElementNumber >= 48 && stringElementNumber <= 49)) {
			errorStatus = 1;
			break;
		}
	}
	if (errorStatus != 1) {
		boolCheck = std::stoi(buff);
		if (boolCheck > 1) {
			errorStatus = 1;
		}
	}
	
	if (errorStatus == 1) {
		fieldRandomGetter(variable, variableName);
	}
}

void MenuFirstOption::showMessageRandomGetter(std::string variableName)
{
	clearScreen();
	if (errorStatus == 1)std::cout << errorReason << std::endl;
	std::cout << "Do you want "<<variableName<<std::endl<<"1-yes 0-no"<<std::endl<<"Your choice: ";
}



