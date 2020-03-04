#include "interface.h"
#include "basicFunctions.h"
#include <iostream>

void Interface::showInterface(const GameField& gameField, const Player& player, size_t xSize, size_t level, size_t playerPos)
{
	showField(gameField.field, xSize);
	showPlayerStats(player);
	showGameStatus(gameField, player, level);
	playerLookingAt(gameField, playerPos, player, xSize);
}

void Interface::showField(const std::vector<WorldElem>& enteredVector, size_t xSize)
{
	clearScreen();
	std::cout << "ENDLESS MINER\n\n";
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

void Interface::showPlayerStats(const Player& player)
{
	newline();
	std::cout<<"*-*-*-*-*-*-*-*-*-*"<<std::endl;
	std::cout << player.playerName<<std::endl;
	std::cout << "Ammount of wood: " << player.ammountOfWood << std::endl;
	std::cout << "Ammount of rock: " << player.ammoutOfRock << std::endl;
	//Ammount of destroyed elements
	//
}

void Interface::showGameStatus(const GameField& gameField, const Player& player, size_t level)
{
	std::cout << "*-*-*-*-*-*-*-*-*-*" << std::endl;
	std::cout << "Level: " << level << std::endl;
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
			std::cout << "#";
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
			std::cout << "#";
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
			std::cout << "#";
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
			std::cout << "#";
			space();
			break;
		}
	default:
		std::cout << "Interface Switch error";
		exit(-1);
		break;
	}
}

void Interface::playerLookingAt(const GameField& gameField, size_t playerPos, const Player& player, size_t x)
{
	std::cout << "*-*-*-*-*-*-*-*-*-*" << std::endl;
	switch (player.playerDirection)
	{
	case direction::UP:
		playerLookingAtDataDisplay(playerLookingUp(playerPos, player, x), gameField.field);
		break;
	case direction::DOWN:
		playerLookingAtDataDisplay(playerLookingDOWN(gameField.field, playerPos, player, x), gameField.field);
		break;
	case direction::LEFT:
		playerLookingAtDataDisplay(playerLookingLEFT(playerPos, player, x), gameField.field);
		break;
	case direction::RIGHT:
		playerLookingAtDataDisplay(playerLookingRIGHT(playerPos, player, x), gameField.field);
		break;
	case direction::UNDEFINED:
		break;
	default:
		clearScreen();
		std::cout << "PlayerLookingAt switch error";
		exit(-1);
		break;
	}
}

int Interface::playerLookingUp(size_t playerPos, const Player& player, size_t x)
{
	size_t playerRow = playerPos / x;
	size_t playerColumn = playerPos - playerRow * x;

	if (playerRow == 0) {
		return -1;
	}
	else {
		size_t newPlayerRow = playerRow - 1;
		size_t newPlayerPos = x * newPlayerRow + playerColumn;
		return newPlayerPos;
	}
}

int Interface::playerLookingDOWN(const std::vector<WorldElem> field, size_t playerPos, const Player& player, size_t x)
{
	size_t playerRow = playerPos / x;
	size_t playerColumn = playerPos - playerRow * x;
	if (playerRow == ((field.size() / x) - 1)) {
		return -1;
	}
	else {
		size_t newPlayerRow = playerRow + 1;
		size_t newPlayerPos = x * newPlayerRow + playerColumn;
		return newPlayerPos;
	}
}

int Interface::playerLookingLEFT(size_t playerPos, const Player& player, size_t x)
{
	size_t playerRow = playerPos / x;
	size_t playerColumn = playerPos - playerRow * x;
	if (playerColumn == 0) {
		return -1;
	}
	else {
		size_t newPlayerRow = playerRow;
		size_t newPlayerPos = x * newPlayerRow + playerColumn - 1;
		return newPlayerPos;
	}
}

int Interface::playerLookingRIGHT(size_t playerPos, const Player& player, size_t x)
{
	size_t playerRow = playerPos / x;
	size_t playerColumn = playerPos - playerRow * x;
	if (playerColumn == x - 1) {
		return -1;
	}
	else {
		size_t newPlayerRow = playerRow;
		size_t newPlayerPos = x * newPlayerRow + playerColumn + 1;
		return newPlayerPos;
	}
}

void Interface::playerLookingAtDataDisplay(int cellPos, const std::vector<WorldElem>& field)
{
	if (cellPos == -1) {
		std::cout << "You`re looking at the wall" << std::endl;
	}
	else {
		std::cout << "You`re looking at " << returnFieldType(cellPos, field) << std::endl;
		if (field[cellPos].type == 2 || field[cellPos].type == 3) {
			std::cout << "Element health: " << field[cellPos].elemHealth << std::endl;
		}
	}
}

std::string Interface::returnFieldType(int cellPos, const std::vector<WorldElem>& field)
{
	switch (field[cellPos].type) {
	case 0:
		return "soil";
		break;
	case 1:
		return "grass";
		break;
	case 2:
		return "tree";
		break;
	case 3:
		return "rock";
		break;
	default:
		clearScreen();
		std::cout << "Interface: returnFieldTypeError";
		exit(-1);
	}
}


