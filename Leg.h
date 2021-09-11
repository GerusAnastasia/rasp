#pragma once
#include "LegPart.h"

class Leg
{
public:
	Leg(PCA9685Servo* servoBoard, int hipPin, int kneePin, int stepPin);
	~Leg();

	//Setters
	Leg* setAngles(int hipAngle, int kneeAngel, int stepAngel, bool smooth = true, int delay = 32);
	Leg* setMinLimits(int hipMinAngle, int kneeMinAngel, int stepMinAngel);
	Leg* setMaxLimits(int hipMaxAngle, int kneeMaxAngel, int stepMaxAngel);

	//Getters
	PCA9685Servo* getServoBoard() { return servoBoard; }

	LegPart* getHip() const { return hip; }
	LegPart* getKnee() const { return knee; }
	LegPart* getStep() const  { return step; }

private:
	PCA9685Servo* servoBoard;

	LegPart* hip;
	LegPart* knee;
	LegPart* step;
};

