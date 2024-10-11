#include "Action_Servo.h"

Servo servoRightHand;
Servo servoLeftHand;
Servo servoHead;
Servo servoBody;

// Attach the servos to their respective pins
void Attach_Servos() {
    servoRightHand.attach(Servo_Right_Hand);
    servoLeftHand.attach(Servo_Left_Hand);
    servoHead.attach(Servo_Head);
    servoBody.attach(Servo_Body);
}

void Action_Servo(const char* emotion) {
    if (strcmp(emotion, "Smile") == 0) {
        for (int pos = 0; pos <= 180; pos++) {
            servoLeftHand.write(pos);
            delay(10);
        }
        for (int pos = 0; pos <= 180; pos++) {
            servoRightHand.write(pos);
            delay(10);
        }
        for (int pos = 0; pos <= 180; pos++) {
            servoHead.write(pos);
            delay(10);
        }
        for (int pos = 0; pos <= 180; pos++) {
            servoBody.write(pos);
            delay(10);
        }
    }
}

