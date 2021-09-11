#include "stdafx.h"
#include "Menu.h"

Menu::Menu(std::stack<Menu*>& stack, Spider& spider)
	: stack(stack), spider(spider)
{
	this->exit = false;
}

bool Menu::isExit()
{
	return exit;
}

void Menu::setExit()
{
	exit = true;
}
