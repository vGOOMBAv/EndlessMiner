#pragma once
#include <string>

class MenuFirstOption {
private:
	std::string errorReason;
	bool errorStatus = 0;
public:
	void showOption();
	void showMessage(std::string variableName);
	void fieldSizeGetter(unsigned int& variable, std::string variableName);
};