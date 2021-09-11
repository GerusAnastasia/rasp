#pragma once
#include "MainMenu.h"

class Controller
{
public:
	Controller(PCA9685Servo* servo_board_0, PCA9685Servo* servo_board_1);

	void start();

private:
	void initMenu();

private:
	Spider* spider;
	PCA9685Servo* servoBoard0;
	PCA9685Servo* servoBoard1;
	std::stack<Menu*> stack;

};

