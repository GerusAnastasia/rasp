#include "stdafx.h"
#include "ChangeLegAngleMenu.h"

void ChangeLegAngleMenu::printCommands()
{
	std::cout << "Enter the angles in the sequence shown: " << "\n";
	std::cout << "*hip, *knee, *step" << "\n";
	std::cout << "Put any angle for '-1' to exit" << "\n";
}

ChangeLegAngleMenu::ChangeLegAngleMenu(std::stack<Menu*>& stack, Spider& spider, int legId)
	: Menu (stack, spider)
{
	this->legId = legId;
}

void ChangeLegAngleMenu::start()
{
	printCommands();

	int hipAngle = 0;
	int kneeAngle = 0;
	int stepAngle = 0;

	std::cin >> hipAngle >> kneeAngle >> stepAngle;

	if (hipAngle != -1 && kneeAngle != -1 && stepAngle != -1)
	{
		spider.getLegById(legId)->setAngles(hipAngle, kneeAngle, stepAngle);
	}
	else 
	{
		setExit();
	}
}


