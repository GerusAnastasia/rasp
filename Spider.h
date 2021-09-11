#pragma once
#include "Leg.h"

class Spider
{
public:
	Spider(PCA9685Servo* servoBoard0, PCA9685Servo* servoBoard1);

	void initPos();
	void raise();
	void liftBody(int deltaAngle = 30, int wait = 10);
	void standUp();
	void moveForward();
	void moveBack();
	void moveLeft();
	void moveRight();

	Leg* getLegById(int legId);

private:
	void initLegs();

private:
	PCA9685Servo* servoBoard0;
	PCA9685Servo* servoBoard1;

	Leg* legs[6];

};

