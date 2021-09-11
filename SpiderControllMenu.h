#pragma once
#include "Menu.h"
class SpiderControllMenu :
    public Menu
{
public:
    SpiderControllMenu(std::stack<Menu*>& stack, Spider& spider);

    void start();
private:

    void printCommands();

};

