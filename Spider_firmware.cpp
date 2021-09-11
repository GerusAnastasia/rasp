#include "stdafx.h"
#include "Controller.h"

#include "Spider_firmware.h"

int main(int argc, char** argv) {
    if (getuid() != 0) {
        fprintf(stderr, "Program is not started as \'root\' (sudo)\n");
        return -1;
    }

    if (bcm2835_init() != 1) {
        fprintf(stderr, "bcm2835_init() failed\n");
        return -2;
    }
    PCA9685Servo servo_board_0(0x40);
    PCA9685Servo servo_board_1(0x41);
    //servo board 0  baud rate init
    servo_board_0.SetLeftUs(600);
    servo_board_0.SetRightUs(2700);

    //servo board 1 baud rate init
    servo_board_1.SetLeftUs(600);

    servo_board_1.SetRightUs(2700);

    servo_board_0.Dump();
    servo_board_1.Dump();

    Controller* controller = new Controller(&servo_board_0, &servo_board_1);
    controller->start();

    delete controller;

    return 0;
}