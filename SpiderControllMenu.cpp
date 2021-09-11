#include "stdafx.h"
#include "SpiderControllMenu.h"

SpiderControllMenu::SpiderControllMenu(std::stack<Menu*>& stack, Spider& spider)
	: Menu(stack, spider)
{
}

void SpiderControllMenu::printCommands()
{
	std::cout << "1 - init position()" << "\n";
	std::cout << "2 - raise legs()" << "\n";
	std::cout << "3 - lift body(angle, delay time)" << "\n";
	std::cout << "4 - stand up()" << "\n";
	std::cout << "5 - move forward" << "\n";
	std::cout << "6 - move back" << "\n";
	std::cout << "7 - move left" << "\n";
	std::cout << "8 - move right" << "\n";
	std::cout << "0 - back" << "\n";
}

void SpiderControllMenu::start()
{
	printCommands();

	int command;
	std::cin >> command;

	switch (command)
	{
	case 1:
		spider.initPos();
		break;
	case 2:
		spider.raise();
		break;
	case 3:
		spider.liftBody();
		break;
	case 4:
		spider.standUp();
		break;
	case 5:
		spider.moveForward();
		break;
	case 6:
		spider.moveBack();
		break;
	case 7:
		spider.moveLeft();
		break;
	case 8:
		spider.moveRight();
		break;
	case 0:
		setExit();
		break;
	default:
		std::cout << "Unknown command" << "\n";
		break;
	}
}
