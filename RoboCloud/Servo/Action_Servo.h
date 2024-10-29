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

void Head_Shake();
void Head_Balance();
void Head_Look_From_Left_To_Right();
void Head_Look_From_Right_To_Left();
void Head_Turn_Small_Right();
void Head_Turn_Small_Left();
void Head_Turn_Big_Left();
void Head_Turn_Big_Right();

void One_Hand_Rising(const char* action, int X);
void One_Hand_Balance(const char* action);
void One_Hand_Waving(int X, const char* action);
void One_Hand_Pointing(int X , const char* action);

void Two_Hand_Rising(int X);
void Two_Hand_Return();
void Two_Hand_Waving(int X);
void Two_Hand_Pointing(int X);

void Plinth_Turn_Small_Left();
void Plinth_Turn_Small_Right();
void Plinth_Turn_Big_Left();
void Plinth_Turn_Big_Right();
void Plinth_Balance();
void Plinth_Shaking();

void Action_Servo(const char* action);

// Declare Servo objects
extern Servo servoRightHand;
extern Servo servoLeftHand;
extern Servo servoHead;
extern Servo servoBody;
#endif
