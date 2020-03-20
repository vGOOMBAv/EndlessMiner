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
		//std::cout << "2.Load\n";
		std::cout << "2.Help\n";
		std::cout << "3.Exit\n";
		if (errorStatus == 1)std::cout << "No such option\n";
		int choice = controller.readKeyboard();
		switch (choice)
		{
		case 49:
			menuFirstOption.showOption();
			break;
		/*case 50:
			break;*/
		case 50:
			clearScreen();
			std::cout << "Your goal is to destroy as many rocks and trees as you can" << std::endl;
			std::cout <<"T-tree R-rock S-soil G-grass #-player"<< std::endl;
			std::cout <<"For movement use WASD. After each time you clear the field the game will regenerate the field"<< std::endl;
			std::cout << "and place you in a new position " << std::endl;
			std::cout << "In the beginning of the game you can choose if you want static ammount of health and dropped ammount of the resources from the elements or a random one" << std::endl;
			std::cout << "If you prefer random ammount after each field cleaning the level of the game will be increased and the parameters of the elements will be increased as well" << std::endl;
			std::cout << "Press Z to end the game" << std::endl;
			std::cout << std::endl << std::endl;
			std::cout << "Press any key to continue";
			controller.readKeyboard();
			showMenu();
			break;
		case 51:
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
