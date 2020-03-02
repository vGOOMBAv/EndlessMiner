#include <string>
#include <iostream>
#include "basicFunctions.h"

void clearScreen()
{
	//for (auto i = 0; i < 100; i++)std::cout << "\n";
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


