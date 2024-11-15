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
void Head_Plinth_Return(int Target, int &Body_pos, int time, Servo &servo);
void Funny_HT_Head();
void Funny_HT_Hand();
void Happy_HT_Hand();
void Happy_HT_Plinth();
void Cute_HT_LeftHand();
void Cute_HT_RightHand();
void Cute_HT_Plinth();
void Shy_HT_Head();
void Shy_HT_Hand();
void Guilty_HT_Hand();
void Considering_HT_Hand();
void Flattering_HT_Hand();
void Presenting_HT_Hand();
void Presenting_HT_Plinth();
void Demonstrate_HT_Hand();
void Demonstrate_HT_Plinth();
void Thinking_HT_LeftHand();
void Thinking_HT_RightHand();
void Thinking_HT_Plinth();
void Woo_HT_Head();
void Woo_HT_Hand();
void Woo_HT_Plinth();
void Balance_Head();
void Balance_Hand();
void Balance_Plinth();
void Action_Servo(const char* action);

// Declare Servo objects
extern Servo servoRightHand;
extern Servo servoLeftHand;
extern Servo servoHead;
extern Servo servoBody;

#endif
