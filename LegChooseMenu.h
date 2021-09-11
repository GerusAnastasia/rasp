#pragma once
#include "ChangeLegAngleMenu.h"

class LegChooseMenu :
    public Menu
{
public:
    LegChooseMenu(std::stack<Menu*>& stack, Spider& spider);
    void start();

private:
    void printCommands();
};

