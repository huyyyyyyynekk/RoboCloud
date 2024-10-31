#include "Action_Servo.h"

int Head_Pos = 90;
int Plinth_Pos = 90;
int Left_Hand_Pos = 60;
int Right_Hand_Pos = 60;  
int Two_Hand_Pos = 60;

unsigned long previousMillis_Happy = 0;
unsigned long previousMillis_Excited = 0;
unsigned long previousMillis_Funny = 0;
unsigned long previousMillis_Confident = 0;

int step_Happy = 0;
int step_Excited = 0;
int step_Confident = 0;
int step_Funny = 0;

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

/*==============================EMOTION=================================*/
void Action_Servo(const char* action){
  if (strcmp(action,"Happy") == 0){
    unsigned long currentMillis_Happy = millis();  
    if (currentMillis_Happy - previousMillis_Happy >= 100) {
    previousMillis_Happy = currentMillis_Happy;    
    switch (step_Happy) {
      case 0:
         if (Head_Pos > 90){
            Head_Pos -= 5;
            servoHead.write(Head_Pos);
          }
         else if (Head_Pos < 90){
            Head_Pos += 5;
            servoHead.write(Head_Pos);
         }
         if (Head_Pos == 90){
          step_Happy = 1;
          break;
         }
         break;
      case 1:
         Left_Hand_Pos += 5;
         servoLeftHand.write(Left_Hand_Pos);
         if (Left_Hand_Pos >= 150){
          Left_Hand_Pos = 150;
          step_Happy = 2;
          break;
         }
         break;
      case 2:
         Right_Hand_Pos += 5;
         servoRightHand.write(Right_Hand_Pos);
         if (Right_Hand_Pos >= 150){
          Right_Hand_Pos = 150;
          step_Happy = 3;
          break;
         }
         break;
      case 3:
         Plinth_Pos += 5;
         servoBody.write(Plinth_Pos);
         if (Plinth_Pos >= 120){
          Plinth_Pos = 120;
          step_Happy = 4;
          break;
         }
         break;
      case 4:
         Plinth_Pos -= 5;
         servoBody.write(Plinth_Pos);
         if (Plinth_Pos <= 60){
          Plinth_Pos = 60;
          step_Happy = 5;
          break;
         }
         break;
      case 5:
         Plinth_Pos += 5;
         servoBody.write(Plinth_Pos);
         if (Plinth_Pos >= 120){
          Plinth_Pos = 120;
          step_Happy = 6;
          break;
         }
         break;
      case 6:
         Plinth_Pos -= 5;
         servoBody.write(Plinth_Pos);
         if (Plinth_Pos <= 60){
          Plinth_Pos = 60;
          break;
         }
         break;      
    }
  }
 }
 else if (strcmp(action,"Funny") == 0){
  unsigned long currentMillis_Funny = millis();  
  if (currentMillis_Funny - previousMillis_Funny >= 200) {
    previousMillis_Funny = currentMillis_Funny;    
    switch (step_Funny) {
      case 0:
         Head_Pos += 5;
         servoHead.write(Head_Pos);
         if (Head_Pos >=120){
            Head_Pos = 120;
            step_Funny = 1;
            break;
         }
         break;
      case 1:
         Head_Pos -= 5;
         servoHead.write(Head_Pos);
         if (Head_Pos <= 60){
            Head_Pos = 60;
            step_Funny = 2;
            break;
         }
         break;
      case 2:
         Two_Hand_Pos += 5;
         servoLeftHand.write(Two_Hand_Pos);
         servoRightHand.write(Two_Hand_Pos);
         if (Two_Hand_Pos >= 90){
            Two_Hand_Pos = 90;
            Left_Hand_Pos = 90;
            Right_Hand_Pos = 90;
            step_Funny = 3;
            break;
         }
         break;
      case 3:
         Two_Hand_Pos -= 5;
         servoLeftHand.write(Two_Hand_Pos);
         servoRightHand.write(Two_Hand_Pos);
         if (Two_Hand_Pos <= 30){
            Two_Hand_Pos = 30;
            Left_Hand_Pos = 30;
            Right_Hand_Pos = 30;
            break;
         }
         break;       
    }
  }
 }
 else if (strcmp(action,"Excited") == 0){
  Head_Shake();
  unsigned long currentMillis_Excited = millis();  
  if (currentMillis_Excited - previousMillis_Excited >= 140) {
    previousMillis_Excited = currentMillis_Excited;    
    switch (step_Excited) {
      case 0:
         Two_Hand_Pos += 10;
         servoLeftHand.write(Two_Hand_Pos);
         servoRightHand.write(Two_Hand_Pos);
         if (Two_Hand_Pos >= 150){
          Two_Hand_Pos = 150;
          Left_Hand_Pos = 150;
          Right_Hand_Pos = 150;
          step_Excited = 1;
          break;
         }
         break;
      case 1:
         Plinth_Pos += 5;
         servoBody.write(Plinth_Pos);
         if (Plinth_Pos >= 110){
          Plinth_Pos = 110;
          step_Excited = 2;
          break;
         }
         break;
      case 2:
         Plinth_Pos -= 5;
         servoBody.write(Plinth_Pos);
         if (Plinth_Pos <= 70){
          Plinth_Pos = 70;
          break;
         }
         break;            
    }
  }
 }
 else if (strcmp(action,"Confident") == 0){
  unsigned long currentMillis_Confident = millis();  
  if (currentMillis_Confident - previousMillis_Confident >= 200) {
    previousMillis_Confident = currentMillis_Confident;    
    switch (step_Confident) {
      case 0 :
        if (Head_Pos > 90){
            Head_Pos -= 5;
            servoHead.write(Head_Pos);
          }
         else if (Head_Pos < 90){
            Head_Pos += 5;
            servoHead.write(Head_Pos);
         }
         if (Head_Pos == 90){
          step_Confident = 1;
          break;
         }
         break;
      case 1 :
        Right_Hand_Pos += 5;
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos >= 120){
          Right_Hand_Pos = 120;
          step_Confident = 2;
          break;
        }
        break;
      case 2 :
        Right_Hand_Pos -= 5;
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos <= 90){
          Right_Hand_Pos = 90;
          break;
        }
        break;    
    }
  }
 }
}