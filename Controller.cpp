#include "stdafx.h"
#include "Controller.h"

void Controller::initMenu()
{
    stack.push(new MainMenu(stack, *spider));
}


Controller::Controller(PCA9685Servo* servo_board_0, PCA9685Servo* servo_board_1)
{
    this->servoBoard0 = servo_board_0;
    this->servoBoard1 = servo_board_1;

    spider = new Spider(servo_board_0, servo_board_1);
    
    initMenu();
}

void Controller::start()
{
    while (!stack.empty()) {
        stack.top()->start();
        if (stack.top()->isExit()) {
            //delete stack.top();
            stack.pop();
        }
    }
}

