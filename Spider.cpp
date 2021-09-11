#include "stdafx.h"
#include "Spider.h"

Spider::Spider(PCA9685Servo* servoBoard0, PCA9685Servo* servoBoard1)
{
    this->servoBoard0 = servoBoard0;
    this->servoBoard1 = servoBoard1;

    initLegs();
}

void Spider::initPos()
{
    //Init
    legs[0]->setAngles(65, 0, 80);
    legs[1]->setAngles(93, 0, 80);
    legs[2]->setAngles(85, 0, 80);

    legs[3]->setAngles(90, 180, 100);
    legs[4]->setAngles(95, 180, 100);
    legs[5]->setAngles(90, 180, 100);
}

void Spider::raise()
{

    int _delay = 10;
    int _delay_between_legs = 0;

    //Leg 0
    legs[0]->setAngles(65, 0, 90, false);
    delay(_delay);
    legs[0]->setAngles(65, 45, 90, false);

    delay(_delay_between_legs);

    //Leg 1
    legs[1]->setAngles(90, 0, 90, false);
    delay(_delay);
    legs[1]->setAngles(90, 51, 90, false);

    delay(_delay_between_legs);

    //Leg 2
    legs[2]->setAngles(85, 0, 90, false);
    delay(_delay);
    legs[2]->setAngles(85, 44, 90, false);

    delay(_delay_between_legs);


    //////////////////////////////////////////

    //Leg 3
    legs[3]->setAngles(90, 180, 60, false);
    delay(_delay);
    legs[3]->setAngles(90, 158, 60, false);

    delay(_delay_between_legs);

    //Leg 4
    legs[4]->setAngles(95, 180, 60, false);
    delay(_delay);
    legs[4]->setAngles(95, 157, 60, false);

    delay(_delay_between_legs);

    //Leg 5
    legs[5]->setAngles(90, 180, 60, false);
    delay(_delay);
    legs[5]->setAngles(90, 159, 60, false);

    delay(_delay_between_legs);
}

void Spider::liftBody(int deltaAngle, int wait)
{
    deltaAngle = 30;

    legs[0]->setAngles(65, legs[0]->getKnee()->getAngle() + deltaAngle, 90, false);
    delay(wait);
    legs[1]->setAngles(90, legs[1]->getKnee()->getAngle() + deltaAngle, 90, false);
    delay(wait);
    legs[2]->setAngles(85, legs[2]->getKnee()->getAngle() + deltaAngle, 90, false);
    delay(wait);
    legs[3]->setAngles(90, legs[3]->getKnee()->getAngle() - deltaAngle, 60, false);
    delay(wait);
    legs[4]->setAngles(95, legs[4]->getKnee()->getAngle() - deltaAngle, 60, false);
    delay(wait);
    legs[5]->setAngles(90, legs[5]->getKnee()->getAngle() - deltaAngle, 60, false);
}

void Spider::standUp()
{
    int _delay_between_legs = 200;

    //Ставим первые три ноги
    legs[0]->setAngles(65, 30, 50, true, 10);
    legs[2]->setAngles(85, 30, 50, true, 10);
    legs[4]->setAngles(95, 180, 90, true, 10);

    delay(_delay_between_legs);

    legs[0]->setAngles(65, 40, 131);
    legs[2]->setAngles(85, 25, 128);
    legs[4]->setAngles(95, 146, 45);

    delay(_delay_between_legs);

    //////////////
    legs[1]->setAngles(93, 30, 50, true, 10);
    legs[3]->setAngles(93, 180, 90, true, 10);
    legs[5]->setAngles(93, 180, 90, true, 10);

    delay(_delay_between_legs);

    legs[1]->setAngles(93, 35, 131);
    legs[3]->setAngles(90, 146, 45);
    legs[5]->setAngles(90, 146, 45);

}

void Spider::moveForward()
{
    int _delay_between_legs = 200;
    int _moving_angle = 25;
    int _half_move = _moving_angle / 2;

    //Raise first 3 legs (0, 2 ,4)
    legs[0]->getKnee()->setAngle(0, true, 10);
    legs[2]->getKnee()->setAngle(0, true, 10);
    legs[4]->getKnee()->setAngle(180, true, 10);

    delay(_delay_between_legs);

    //Moving them forward
    legs[0]->getHip()->setAngle(legs[0]->getHip()->getAngle() - _half_move);
    legs[2]->getHip()->setAngle(legs[2]->getHip()->getAngle() - _half_move);
    legs[4]->getHip()->setAngle(legs[4]->getHip()->getAngle() + _moving_angle);

    delay(_delay_between_legs);

    //Move the rest of the legs back
    legs[1]->getHip()->setAngle(legs[1]->getHip()->getAngle() + _moving_angle, false);
    legs[3]->getHip()->setAngle(legs[3]->getHip()->getAngle() - _half_move, false);
    legs[5]->getHip()->setAngle(legs[5]->getHip()->getAngle() - _half_move, false);

    delay(_delay_between_legs);

    //Put fits down
    legs[0]->getKnee()->setAngle(40, true, 10);
    legs[2]->getKnee()->setAngle(25, true, 10);
    legs[4]->getKnee()->setAngle(146, true, 10);

    delay(_delay_between_legs);

    ///////////////////////////////////////////////////////////////////////////////////
    //Raise second 3 legs (1, 3 ,5)
    legs[1]->getKnee()->setAngle(0, true, 10);
    legs[3]->getKnee()->setAngle(180, true, 10);
    legs[5]->getKnee()->setAngle(180, true, 10);

    delay(_delay_between_legs);

    //Moving them forward
    legs[1]->getHip()->setAngle(legs[1]->getHip()->getAngle() - _moving_angle);
    legs[3]->getHip()->setAngle(legs[3]->getHip()->getAngle() + _half_move);
    legs[5]->getHip()->setAngle(legs[5]->getHip()->getAngle() + _half_move);

    delay(_delay_between_legs);

    //Move the rest of the legs back
    legs[0]->getHip()->setAngle(legs[0]->getHip()->getAngle() + _half_move, false);
    legs[2]->getHip()->setAngle(legs[2]->getHip()->getAngle() + _half_move, false);
    legs[4]->getHip()->setAngle(legs[4]->getHip()->getAngle() - _moving_angle, false);

    delay(_delay_between_legs);

    //Put fits down
    legs[1]->getKnee()->setAngle(35, true, 10);
    legs[3]->getKnee()->setAngle(146, true, 10);
    legs[5]->getKnee()->setAngle(146, true, 10);

    delay(_delay_between_legs);

}

void Spider::moveBack()
{
    int _delay_between_legs = 200;
    int _moving_angle = 25;

    //Raise second 3 legs (1, 3 ,5)
    legs[1]->getKnee()->setAngle(0, true, 10);
    legs[3]->getKnee()->setAngle(180, true, 10);
    legs[5]->getKnee()->setAngle(180, true, 10);

    delay(_delay_between_legs);

    //Moving them back
    legs[1]->getHip()->setAngle(legs[1]->getHip()->getAngle() + _moving_angle);
    legs[3]->getHip()->setAngle(legs[3]->getHip()->getAngle() - _moving_angle);
    legs[5]->getHip()->setAngle(legs[5]->getHip()->getAngle() - _moving_angle);

    delay(_delay_between_legs);

    //Move the rest of the legs forward
    legs[0]->getHip()->setAngle(legs[0]->getHip()->getAngle() - _moving_angle, false);
    legs[2]->getHip()->setAngle(legs[2]->getHip()->getAngle() - _moving_angle, false);
    legs[4]->getHip()->setAngle(legs[4]->getHip()->getAngle() + _moving_angle, false);

    delay(_delay_between_legs);

    //Put fits down
    legs[1]->getKnee()->setAngle(35, true, 10);
    legs[3]->getKnee()->setAngle(146, true, 10);
    legs[5]->getKnee()->setAngle(146, true, 10);

    delay(_delay_between_legs);
    //////////////////////////////////////////////////////////////////

    //Raise first 3 legs (0, 2 ,4)
    legs[0]->getKnee()->setAngle(0, true, 10);
    legs[2]->getKnee()->setAngle(0, true, 10);
    legs[4]->getKnee()->setAngle(180, true, 10);

    delay(_delay_between_legs);

    //Moving them back
    legs[0]->getHip()->setAngle(legs[0]->getHip()->getAngle() + _moving_angle);
    legs[2]->getHip()->setAngle(legs[2]->getHip()->getAngle() + _moving_angle);
    legs[4]->getHip()->setAngle(legs[4]->getHip()->getAngle() - _moving_angle);

    delay(_delay_between_legs);

    //Move the rest of the legs forward
    legs[1]->getHip()->setAngle(legs[1]->getHip()->getAngle() - _moving_angle, false);
    legs[3]->getHip()->setAngle(legs[3]->getHip()->getAngle() + _moving_angle, false);
    legs[5]->getHip()->setAngle(legs[5]->getHip()->getAngle() + _moving_angle, false);

    delay(_delay_between_legs);

    //Put fits down
    legs[0]->getKnee()->setAngle(40, true, 10);
    legs[2]->getKnee()->setAngle(25, true, 10);
    legs[4]->getKnee()->setAngle(146, true, 10);

    delay(_delay_between_legs);

}

void Spider::moveLeft()
{

}

void Spider::moveRight()
{

}

Leg* Spider::getLegById(int legId)
{
    return legs[legId];
}

void Spider::initLegs()
{
    legs[0] = new Leg(servoBoard0, 7, 6, 5);
    legs[1] = new Leg(servoBoard0, 9, 3, 4);
    legs[2] = new Leg(servoBoard0, 10, 12, 11);

    legs[3] = new Leg(servoBoard1, 11, 12, 10);
    legs[4] = new Leg(servoBoard1, 9, 6, 8);
    legs[5] = new Leg(servoBoard1, 3, 4, 5);

    //initPos();
}
