#include "stdafx.h"
#include "LegPart.h"

int LegPart::clamp(int value, int min, int max)
{

	if (min != 0 && value < min) {
		std::cout << "Value clamped up to " << min << "\n";
		return min;
	}
	else if (max != 0 && value > max) {
		std::cout << "Value clamped down to " << max << "\n";
		return max;
	}

	return value;
}

LegPart::LegPart(PCA9685Servo* servoBoard, int pin, int minAngle, int maxAngle)
{
	this->servoBoard = servoBoard;

	this->angle = 0;
	this->pin = pin;
	this->minAngle = minAngle;
	this->maxAngle = maxAngle;
}

void LegPart::setAngle(int angle, bool smooth, int delay)
{

	if (this->angle != 0 && smooth) 
	{
		int _oldAngle = this->angle;
		int _newAngle = angle;

		int _multiplicityAngle = 5;
		int _sign = _oldAngle < _newAngle ? 1 : -1;

		int _itarations = std::abs(_oldAngle - _newAngle) / _multiplicityAngle;
		

		for (int i = 0; i < _itarations; i++) {
			servoBoard->SetAngle(CHANNEL(pin), ANGLE(clamp(_oldAngle + i * _multiplicityAngle * _sign, minAngle, maxAngle)));
			delay(delay);
		}

	}

	this->angle = angle;
	servoBoard->SetAngle(CHANNEL(pin), ANGLE(clamp(this->angle, minAngle, maxAngle)));


}

void LegPart::setMaxAngle(int maxAngle)
{
	this->maxAngle = maxAngle;
}

void LegPart::setMinAngle(int minAngle)
{
	this->minAngle = minAngle;
}


