#pragma once
#include <conio.h>
#include <vector>
#include "worldElem.h"
#include "player.h"

class Controller {
public:
	int readKeyboard();
	void changePlayerPos(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int& newPlayerPos);
	void playerUP(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerDOWN(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerLEFT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);
	void playerRIGHT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);

	void playerHIT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x, Player& player);

	void cellDestruction(std::vector<WorldElem>& field, unsigned int cellPos);
	void cellHit(std::vector<WorldElem>& field, unsigned int cellPos);
	void playerHitUP(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);
	void playerHitDOWN(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);
	void playerHitLEFT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);
	void playerHitRIGHT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);
};