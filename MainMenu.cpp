#include "stdafx.h"
#include "MainMenu.h"

void MainMenu::printCommands()
{
	std::cout << "1 - prepared movements" << "\n";
	std::cout << "2 - manual control of leg's angles" << "\n";
	std::cout << "0 - exit" << "\n";
}

MainMenu::MainMenu(std::stack<Menu*>& stack, Spider& spider)
	: Menu(stack, spider)
{
}

void MainMenu::start()
{
	printCommands();

	int command;
	std::cin >> command;

	switch (command)
	{
	case 1:
		stack.push(new SpiderControllMenu(stack, spider));
		break;
	case 2:
		stack.push(new LegChooseMenu(stack, spider));
		break;
	case 0:
		setExit();
		break;
	default:
		std::cout << "Unknown command" << "\n";
		break;
	}

}


