#include "controller.h"
#include <vector>

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

void Controller::playerUP(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
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
	

}

void Controller::playerDOWN(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
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
}

void Controller::playerLEFT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
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
}

void Controller::playerRIGHT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x)
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
}


