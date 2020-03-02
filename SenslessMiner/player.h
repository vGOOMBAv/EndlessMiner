#pragma once
#include <string>

enum class direction{
	UNDEFINED, UP, DOWN, RIGHT, LEFT
};

class Player {
public:
	direction playerDirection = direction::UNDEFINED;
	std::string playerName;
	unsigned int ammountOfWood = 0;
	unsigned int ammoutOfRock = 0;
};