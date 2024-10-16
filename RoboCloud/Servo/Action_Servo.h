#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include "Arduino.h"
#include "Servo.h"

// Servo pin definitions
#define Servo_Right_Hand 12
#define Servo_Left_Hand 13
#define Servo_Head 14 
#define Servo_Body 15 

// Function prototypes
void Action_Servo(const char* emotion);
void Attach_Servos();

// Declare Servo objects
extern Servo servoRightHand;
extern Servo servoLeftHand;
extern Servo servoHead;
extern Servo servoBody;

#endif
