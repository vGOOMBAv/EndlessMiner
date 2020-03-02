#include <iostream>
#include <string>
#include "basicFunctions.h"
#include "gameBody.h"
#include "fieldGenerator.h"
#include "gameField.h"
#include "interface.h"
#include "player.h"
#include "controller.h"
#include "menu.h"
#include <time.h>

void GameBody::start(unsigned int x, unsigned int y)
{
	Menu menu;
	Controller controller;
	Player player;
	GameField gameField(x, y);
	Interface interface;
	auto playerPOS = spawnPlayer(gameField.field);
	interface.showField(gameField.field, x);

	while (true)
	{
		int choice = controller.readKeyboard();
		if (choice == 32)controller.playerHIT(gameField.field, playerPOS, x, player);
		if (choice == 122 || choice == 90)menu.showMenu();
		//W
		if (choice == 87 || choice == 119) {
			controller.playerUP(gameField.field, playerPOS, x, player);
		}
		//S
		if (choice == 83 || choice == 115) {
			controller.playerDOWN(gameField.field, playerPOS, x, player);
		}
		//A
		if (choice == 65 || choice == 97) {
			controller.playerLEFT(gameField.field, playerPOS, x, player);
		}
		//D
		if (choice == 68 || choice == 100) {
			controller.playerRIGHT(gameField.field, playerPOS, x, player);
		}
		interface.showField(gameField.field, x);
		//std::cout << (int)player.playerDirection;
	}


}

unsigned int GameBody::spawnPlayer(std::vector<WorldElem>& field)
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
	return i;
}

