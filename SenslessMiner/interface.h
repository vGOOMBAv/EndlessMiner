#pragma once
#include "gameField.h"
#include "player.h"
#include <vector>

class Interface {
public:
	void showInterface(const GameField& gameField, const Player& player, size_t xSize, size_t level, size_t playerPos);
	void showField(const std::vector<WorldElem>& enteredVector, size_t xSize);
	void showPlayerStats(const Player& player);
	void showGameStatus(const GameField& gameField, const Player& player, size_t level);
	void showElement(WorldElem worldElem);
	void playerLookingAt(const GameField& gameField, size_t playerPos, const Player& player, size_t x);

	int playerLookingUp(size_t playerPos, const Player& player, size_t x);
	int playerLookingDOWN(const std::vector<WorldElem> field, size_t playerPos, const Player& player, size_t x);
	int playerLookingLEFT(size_t playerPos, const Player& player, size_t x);
	int playerLookingRIGHT(size_t playerPos, const Player& player, size_t x);

	void playerLookingAtDataDisplay(int cellPos, const std::vector<WorldElem>& field);
	std::string returnFieldType(int cellPos, const std::vector<WorldElem>& field);
};
