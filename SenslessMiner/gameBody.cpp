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

void GameBody::start(size_t x, size_t y, bool randomElemHealth, bool randomAmmountOfDroppedResources, bool newPlayer)
{
	Menu menu;
	Controller controller;
	Player player;
	if (newPlayer) {
		getPlayerName(player);
	}
	GameField gameField;
	Interface interface;
	gameField.generateNewField(x, y, randomElemHealth, randomAmmountOfDroppedResources, level);
	auto playerPOS = spawnPlayer(gameField.field);
	interface.showInterface(gameField, player, x, level, playerPOS);

	while (true)
	{
		int choice = controller.readKeyboard();
		if (choice == 32)controller.playerHIT(gameField, playerPOS, x, player);
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
		interface.showInterface(gameField, player, x, level, playerPOS);
		if (gameField.numberOfObstacles == 0) {
			level++;
			gameField.generateNewField(x, y, randomElemHealth, randomAmmountOfDroppedResources, level);
			playerPOS = spawnPlayer(gameField.field);
		}
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

void GameBody::getPlayerName(Player& player)
{
	clearScreen();
	std::cout << "Enter your name: ";
	std::cin >> player.playerName;
}

