#pragma once
#include <conio.h>
#include <vector>
#include "gameField.h"
#include "player.h"

class Controller {
public:
	int readKeyboard();
	void changePlayerPos(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int& newPlayerPos);
	void playerUP(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerDOWN(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerLEFT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerRIGHT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);

	void playerHIT(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player);

	void cellDestruction(GameField& gameField, unsigned int cellPos, Player& player);
	void cellHit(GameField& gameField, unsigned int cellPos, Player& player);
	void playerHitUP(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerHitDOWN(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerHitLEFT(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerHitRIGHT(GameField& gameField, unsigned int& playerPOS, unsigned int x, Player& player);
};