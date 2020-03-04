#include <iostream>
#include "basicFunctions.h"
#include "menu.h"
#include "menuFirstOption.h"
#include "controller.h"
#include "gameBody.h"

void Menu::showMenu()
{
	clearScreen();
	MenuFirstOption menuFirstOption;
	Controller controller;
	if (state == 0) {
		std::cout << "ENDLESS MINER\n\n";
		std::cout << "Press any key to continue";
		controller.readKeyboard();
		state = 1;
		showMenu();
	}
	else {
		std::cout << "ENDLESS MINER\n\n\n";
		std::cout << "1.Start new game\n";
		std::cout << "2.Load\n";
		std::cout << "3.Help\n";
		std::cout << "4.Exit\n";
		if (errorStatus == 1)std::cout << "No such option\n";
		int choice = controller.readKeyboard();
		switch (choice)
		{
		case 49:
			menuFirstOption.showOption();
			break;
		case 50:
			break;
		case 51:
			break;
		case 52:
			exit(-1);
			break;
		default:
			clearScreen();
			errorStatus = 1;
			showMenu();
			break;
		}
	}
	
}
