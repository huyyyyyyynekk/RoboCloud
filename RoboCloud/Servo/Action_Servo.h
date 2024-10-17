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
void Head_Rise();
void Head_Balance();
void Head_Bow();
void Head_Nod();

void Rising_One_Hand_80(const char* action);
void Rising_One_Hand_90(const char* action);
void Rising_One_Hand_120(const char* action);
void Rising_One_Hand_150(const char* action);
void One_Hand_Return(const char* action);
void One_Hand_Waving(int X, const char* action);
void One_Hand_Pointing(int X , const char* action);

void Two_Hand_Rising_80();
void Two_Hand_Rising_90();
void Two_Hand_Rising_120();
void Two_Hand_Rising_150();
void Two_Hand_Return();
void Two_Hand_Waving(int X);
void Two_Hand_Pointing(int X);

void Plinth_Turn_Small_Left();
void Plinth_Turn_Small_Right();
void Plinth_Turn_Big_Left();
void Plinth_Turn_Big_Right();
void Plinth_Return();
void Plinth_Shaking();

// Declare Servo objects
extern Servo servoRightHand;
extern Servo servoLeftHand;
extern Servo servoHead;
extern Servo servoBody;

#endif
