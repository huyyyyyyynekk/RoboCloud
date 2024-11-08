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
void Attach_Servos();
void Funny_HT_Head();
void Funny_HT_Hand();
void Funny_HT_Plinth();
void Happy_HT_Head();
void Happy_HT_Hand();
void Happy_HT_Plinth();
void Balance_Head();
void Balance_Hand();
void Balance_Plinth();
void Happy_Head();
void Happy_Hand();
void Happy_Plinth();
void Funny_Head();
void Funny_Hand();
void Funny_Plinth();
void Excited_Head();
void Excited_Hand ();
void Excited_Plinth();
void Confident_Head();
void Confident_Hand();
void Action_Servo(const char* action);

// Declare Servo objects
extern Servo servoRightHand;
extern Servo servoLeftHand;
extern Servo servoHead;
extern Servo servoBody;
#endif
