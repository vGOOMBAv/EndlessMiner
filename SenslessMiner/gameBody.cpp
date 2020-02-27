#include <iostream>
#include <string>
#include "basicFunctions.h"
#include "gameBody.h"
#include "fieldGenerator.h"
#include "gameField.h"
#include "interface.h"
#include "player.h"
#include "controller.h"
#include <time.h>

void GameBody::start(unsigned int x, unsigned int y)
{
	Player player;
	GameField gameField(x, y);
	Interface interface;
	spawnPlayer(gameField.field);
	interface.showField(gameField.field, x);


}

void GameBody::spawnPlayer(std::vector<WorldElem>& field)
{
	std::vector<unsigned int> freeCell;
	for (auto i = 0; i < field.size(); i++) {
		if (field[i].type == 0 || field[i].type == 1) {
			freeCell.push_back(i);
		}
	}
	srand(time(NULL));
	auto i = rand() % freeCell.size();
	field[i].playerPosition = 1;
}

