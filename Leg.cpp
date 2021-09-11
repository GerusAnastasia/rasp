#include "stdafx.h"
#include "Leg.h"

Leg::Leg(PCA9685Servo* servoBoard, int hipPin, int kneePin, int stepPin)
{
	this->servoBoard = servoBoard;

	this->hip = new LegPart(servoBoard, hipPin);
	this->knee = new LegPart(servoBoard, kneePin);
	this->step = new LegPart(servoBoard, stepPin);
}

Leg::~Leg()
{
	delete hip;
	delete knee;
	delete step;
}

Leg* Leg::setAngles(int hipAngle, int kneeAngel, int stepAngel, bool smooth, int delay)
{
	hip->setAngle(hipAngle, smooth, delay);
	knee->setAngle(kneeAngel, smooth, delay);
	step->setAngle(stepAngel, smooth, delay);

	return this;
}

Leg* Leg::setMinLimits(int hipMinAngle, int kneeMinAngel, int stepMinAngel)
{
	hip->setMinAngle(hipMinAngle);
	knee->setMinAngle(kneeMinAngel);
	step->setMinAngle(stepMinAngel);

	return this;
}

Leg* Leg::setMaxLimits(int hipMaxAngle, int kneeMaxAngel, int stepMaxAngel)
{
	hip->setMaxAngle(hipMaxAngle);
	knee->setMaxAngle(kneeMaxAngel);
	step->setMaxAngle(stepMaxAngel);

	return this;
}
