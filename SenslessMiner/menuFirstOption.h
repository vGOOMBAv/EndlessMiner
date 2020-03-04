#pragma once
#include <string>

class MenuFirstOption {
private:
	std::string errorReason;
	bool errorStatus = 0;
public:
	void showOption();
	void fieldSizeGetter(unsigned int& variable, std::string variableName);
	void showMessageSize(std::string variableName);
	void fieldRandomGetter(bool& variable, std::string variableName);
	void showMessageRandomGetter(std::string variableName);
};