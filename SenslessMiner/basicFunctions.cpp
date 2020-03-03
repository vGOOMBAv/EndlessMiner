#include <string>
#include <iostream>
#include "basicFunctions.h"

void clearScreen()
{
	std::cout << "\033[H\033[J";
}

void space()
{
	std::cout << " ";
}

void newline()
{
	std::cout << std::endl;
}


