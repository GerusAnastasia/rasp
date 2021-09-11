#include "stdafx.h"
#include "LegChooseMenu.h"

void LegChooseMenu::printCommands()
{
	std::cout << "1 - leg 1 (servo board 0)" << "\n";
	std::cout << "2 - leg 2 (servo board 0)" << "\n";
	std::cout << "3 - leg 3 (servo board 0)" << "\n";
	std::cout << "4 - leg 4 (servo board 1)" << "\n";
	std::cout << "5 - leg 5 (servo board 1)" << "\n";
	std::cout << "6 - leg 6 (servo board 1)" << "\n";
	std::cout << "0 - back" << "\n";
}


LegChooseMenu::LegChooseMenu(std::stack<Menu*>& stack, Spider& spider)
	: Menu(stack, spider)
{
}

void LegChooseMenu::start()
{
	printCommands();

	int command;
	std::cin >> command;

	switch (command)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		stack.push(new ChangeLegAngleMenu(stack, spider, command - 1));
		break;
	case 0:
		setExit();
		break;
	default:
		std::cout << "Unknown command" << "\n";
		break;
	}
}