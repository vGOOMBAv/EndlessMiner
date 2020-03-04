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

void Controller::cellHit(GameField& gameField, unsigned int cellPos, Player& player)
{
	if (gameField.field[cellPos].type == 2 || gameField.field[cellPos].type == 3) {
		if (--gameField.field[cellPos].elemHealth == 0) {
			cellDestruction(gameField, cellPos, player);
		}
	}
}

void Controller::cellDestruction(GameField& gameField, unsigned int cellPos, Player& player)
{
	gameField.numberOfObstacles--;
	//tree
	if (gameField.field[cellPos].type == 2) {
		gameField.field[cellPos].type = 1;
		gameField.field[cellPos].canWalkThrough = 1;
		player.ammountOfWood = player.ammountOfWood + gameField.field[cellPos].droppedAmmountOfRes;
	}
	//rock
	if (gameField.field[cellPos].type == 3) {
		gameField.field[cellPos].type = 0;
		gameField.field[cellPos].canWalkThrough = 1;
		player.ammoutOfRock = player.ammoutOfRock + gameField.field[cellPos].droppedAmmountOfRes;
	}
}

void Controller::playerHitUP(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player)
{

	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionRow != 0) {
		unsigned int hitPositionRow = playerPositionRow - 1;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn;

		cellHit(gameField, hitPos, player);
	}
}

void Controller::playerHitDOWN(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionRow != ((gameField.field.size() / x) - 1)) {
		unsigned int hitPositionRow = playerPositionRow + 1;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn;
		cellHit(gameField, hitPos, player);
	}
}

void Controller::playerHitLEFT(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionColumn != 0) {
		unsigned int hitPositionRow = playerPositionRow;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn - 1;
		cellHit(gameField, hitPos, player);
	}
}

void Controller::playerHitRIGHT(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player)
{
	unsigned int playerPositionRow = playerPOS / x;
	unsigned int playerPositionColumn = playerPOS - playerPositionRow * x;

	if (playerPositionColumn != x) {
		unsigned int hitPositionRow = playerPositionRow;
		unsigned int hitPos = hitPositionRow * x + playerPositionColumn + 1;
		cellHit(gameField, hitPos, player);
	}
}

void Controller::playerHIT(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player)
{
	direction playerDirection = player.playerDirection;
	switch(playerDirection){
	
	case(direction::UP):
		playerHitUP(gameField, playerPOS, x, player);
		break;
	case(direction::DOWN):
		playerHitDOWN(gameField, playerPOS, x, player);
		break;
	case(direction::LEFT):
		playerHitLEFT(gameField, playerPOS, x, player);
		break;
	case(direction::RIGHT):
		playerHitRIGHT(gameField, playerPOS, x, player);
		break;
	case(direction::UNDEFINED):
		break;
	default:
		std::cout << "playerHIT switch error";
		exit(-1);
	
	}
}


