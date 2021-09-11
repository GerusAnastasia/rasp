#pragma once
#include "Spider.h"

class Menu
{
public:
	Menu(std::stack<Menu*>& stack, Spider& spider);

	bool isExit();
	virtual void start() = 0;

protected:
	void setExit();

	virtual void printCommands() = 0;

protected:
	std::stack<Menu*>& stack;
	Spider& spider;

	bool exit;

};

