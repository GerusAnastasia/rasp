#pragma once
#include "SpiderControllMenu.h"
#include "LegChooseMenu.h"

class MainMenu :
    public Menu
{
public:
    MainMenu(std::stack<Menu*>& stack, Spider& spider);
    void start();

private:
    void printCommands();  
};

