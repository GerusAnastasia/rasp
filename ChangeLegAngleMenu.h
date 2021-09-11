#pragma once
#include "Menu.h"
class ChangeLegAngleMenu :
    public Menu
{
public:
    ChangeLegAngleMenu(std::stack<Menu*>& stack, Spider& spider, int legId);
    void start();

private:
    void printCommands();

private:
    int legId;
};
