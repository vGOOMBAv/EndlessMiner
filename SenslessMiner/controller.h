#pragma once
#include <conio.h>
#include <vector>
#include "worldElem.h"

class Controller {
public:
	int readKeyboard();
	void changePlayerPos(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int& newPlayerPos);
	void playerUP(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);
	void playerDOWN(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);
	void playerLEFT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);
	void playerRIGHT(std::vector<WorldElem>& field, unsigned int& playerPOS, unsigned int x);

};