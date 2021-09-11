#pragma once

class LegPart
{
public:
	LegPart(PCA9685Servo* servoBoard, int pin, int minAngle = 0, int maxAngle = 0);

	//Setters
	void setAngle(int angle, bool smooth = true, int delay = 32);

	void setMaxAngle(int maxAngle);
	void setMinAngle(int minAngle);

	//Getters
	int getAngle() { return this->angle; }
	int getPin() { return this->pin; }

private:
	int clamp(int value, int min, int max);

private:
	PCA9685Servo* servoBoard;

	int pin;
	int angle;

	int maxAngle;
	int minAngle;

};

