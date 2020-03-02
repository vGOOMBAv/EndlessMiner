#include "controller.h"
#include "player.h"
#include <vector>
#include <iostream>

int Controller::readKeyboard()
{
	return _getch();
}

void Controller::changePlayerPos(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int& newPlayerPos)
{
	if (field[newPlayerPos].canWalkThrough) {
		field[newPlayerPos].playerPosition = true;
		field[playerPOS].playerPosition = false;
		playerPOS = newPlayerPos;
	}
}

void Controller::playerUP(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;
	unsigned int newPlayerPositionRow;
	unsigned int newPlayerPos;

	if (playerPositionRow == 0) {
		newPlayerPositionRow = (field.size() / x) - 1;
		newPlayerPos = newPlayerPositionRow * x + playerPositionColumn;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	else {
		newPlayerPositionRow = playerPositionRow - 1;
		newPlayerPos = newPlayerPositionRow * x + playerPositionColumn;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	player.playerDirection = direction::UP;
}

void Controller::playerDOWN(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;
	unsigned int newPlayerPositionRow;
	unsigned int newPlayerPos;

	if (playerPositionRow == ((field.size()/x)-1)) {
		newPlayerPositionRow = 0;
		newPlayerPos = playerPositionColumn;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	else {
		newPlayerPositionRow = playerPositionRow + 1;
		newPlayerPos = newPlayerPositionRow * x + playerPositionColumn;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	player.playerDirection = direction::DOWN;
}

void Controller::playerLEFT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;
	unsigned int newPlayerPositionRow;
	unsigned int newPlayerPos;

	if (playerPositionColumn == 0) {
		playerPositionColumn = x - 1;
		newPlayerPositionRow = playerPositionRow;
		newPlayerPos = newPlayerPositionRow * x + playerPositionColumn;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	else {
		newPlayerPositionRow = playerPositionRow;
		newPlayerPos = newPlayerPositionRow * x + playerPositionColumn-1;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	player.playerDirection = direction::LEFT;
}

void Controller::playerRIGHT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;
	unsigned int newPlayerPositionRow;
	unsigned int newPlayerPos;

	if (playerPositionColumn == x-1) {
		playerPositionColumn = 0;
		newPlayerPositionRow = playerPositionRow;
		newPlayerPos = newPlayerPositionRow * x + playerPositionColumn;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	else {
		newPlayerPositionRow = playerPositionRow;
		newPlayerPos = newPlayerPositionRow * x + playerPositionColumn + 1;
		changePlayerPos(field, playerPOS, newPlayerPos);
	}
	player.playerDirection = direction::RIGHT;
}

void Controller::cellHit(std::vector<WorldElem>& field, unsigned int cellPos)
{
	if (--field[cellPos].elemHealth == 0) {
		cellDestruction(field, cellPos);
	}
}

void Controller::cellDestruction(std::vector<WorldElem>& field, unsigned int cellPos)
{
	if (field[cellPos].type == 2) {
		field[cellPos].type = 1;
		field[cellPos].canWalkThrough = 1;
	}
	if (field[cellPos].type == 3) {
		field[cellPos].type = 0;
		field[cellPos].canWalkThrough = 1;
	}
}

void Controller::playerHitUP(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
{

	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionRow != 0) {
		unsigned int hitPositionRow = playerPositionRow - 1;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn;

		cellHit(field, hitPos);
	}
}

void Controller::playerHitDOWN(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionRow != ((field.size() / x) - 1)) {
		unsigned int hitPositionRow = playerPositionRow + 1;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn;
		cellHit(field, hitPos);
	}
}

void Controller::playerHitLEFT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionColumn != 0) {
		unsigned int hitPositionRow = playerPositionRow;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn - 1;
		cellHit(field, hitPos);
	}
}

void Controller::playerHitRIGHT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionColumn != x) {
		unsigned int hitPositionRow = playerPositionRow;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn + 1;
		cellHit(field, hitPos);
	}
}

void Controller::playerHIT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player)
{
	direction playerDirection = player.playerDirection;
	switch(playerDirection){
	
	case(direction::UP):
		playerHitUP(field, playerPOS, x);
		break;
	case(direction::DOWN):
		playerHitDOWN(field, playerPOS, x);
		break;
	case(direction::LEFT):
		playerHitLEFT(field, playerPOS, x);
		break;
	case(direction::RIGHT):
		playerHitRIGHT(field, playerPOS, x);
		break;
	case(direction::UNDEFINED):
		break;
	default:
		std::cout << "playerHIT switch error";
		exit(-1);
	
	}
}


