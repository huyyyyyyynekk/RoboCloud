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

/* =================================== HEAD ================================= */
void Head_Rise(){
  servoHead.write(25);
}

void Head_Balance(){
  servoHead.write(15);
}

void Head_Bow(){
  servoHead.write(5);
}

void Head_Nod(){
  servoHead.write(25);
  delay(200);
  servoHead.write(5);
  delay(200);
  servoHead.write(15);
  delay(200);
}

/* =================================== ONE - HAND ================================= */
void Rising_One_Hand_80(const char* action){
  if (strcmp(action, "Left Hand") == 0){
    servoLeftHand.write(80);
  }
  else if (strcmp(action, "Right Hand") == 0){
    servoRightHand.write(80);
  }
}

void Rising_One_Hand_90(const char* action){
  if (strcmp(action, "Left Hand") == 0){
    servoLeftHand.write(90);
  }
  else if (strcmp(action, "Right Hand") == 0){
    servoRightHand.write(90);
  }
}

void Rising_One_Hand_120(const char* action){
  if (strcmp(action, "Left Hand") == 0){
    servoLeftHand.write(120);
  }
  else if (strcmp(action, "Right Hand") == 0){
    servoRightHand.write(120);
  }
}

void Rising_One_Hand_150(const char* action){
  if (strcmp(action, "Left Hand") == 0){
    servoLeftHand.write(150);
  }
  else if (strcmp(action, "Right Hand") == 0){
    servoRightHand.write(150);
  }
}

void One_Hand_Return(const char* action){
  if (strcmp(action, "Left Hand") == 0){
    servoLeftHand.write(30);
  }
  else if (strcmp(action, "Right Hand") == 0){
    servoRightHand.write(30);
  }
}

void One_Hand_Waving(int X, const char* action){
    if (strcmp(action, "Left Hand") == 0){
      servoLeftHand.write(X);
      delay(200);
      servoLeftHand.write(X + 30);
      delay(200);
      servoLeftHand.write(X);
      delay(200);
    }
    else if (strcmp(action, "Right Hand") == 0){
      servoRightHand.write(X);
      delay(200);
      servoRightHand.write(X + 30);
      delay(200);
      servoRightHand.write(X);
      delay(200);
    }
  }

void One_Hand_Pointing(int X , const char* action){
    if (strcmp(action, "Left Hand") == 0){
      servoLeftHand.write(X);
      delay(200);
      servoLeftHand.write(X + 10);
      delay(200);
      servoLeftHand.write(X);
      delay(200);

    }
    else if (strcmp(action, "Right Hand") == 0){
      servoRightHand.write(X);
      delay(200);
      servoRightHand.write(X + 10);
      delay(200);
      servoRightHand.write(X);
      delay(200);
    }  
  }

/* =================================== TWO - HAND ================================= */
void Two_Hand_Rising_80(){
  servoLeftHand.write(80);
  servoRightHand.write(80);
}

void Two_Hand_Rising_90(){
  servoLeftHand.write(90);
  servoRightHand.write(90);
}

void Two_Hand_Rising_120(){
  servoLeftHand.write(120);
  servoRightHand.write(120);
}

void Two_Hand_Rising_150(){
  servoLeftHand.write(150);
  servoRightHand.write(150);
}

void Two_Hand_Return(){
  servoLeftHand.write(30);
  servoRightHand.write(30);
}

void Two_Hand_Waving(int X){
    servoLeftHand.write(X);
    servoRightHand.write(X);
    delay(200);
    servoLeftHand.write(X + 30);
    servoRightHand.write(X + 30);
    delay(200);
    servoLeftHand.write(X);
    servoRightHand.write(X);  
    delay(200);
  }

void Two_Hand_Pointing(int X){
  servoLeftHand.write(X);
    servoRightHand.write(X);
    delay(200);
    servoLeftHand.write(X + 10);
    servoRightHand.write(X + 10);
    delay(200);
    servoLeftHand.write(X);
    servoRightHand.write(X);  
    delay(200);
}

/* =================================== PLINTH ================================= */

void Plinth_Turn_Small_Left(){
  servoBody.write(90+30);
}

void Plinth_Turn_Small_Right(){
  servoBody.write(90-30);
}

void Plinth_Turn_Big_Left(){
  servoBody.write(90+80);
}

void Plinth_Turn_Big_Right(){
  servoBody.write(90-80);
}

void Plinth_Return(){
  servoBody.write(90);
}

void Plinth_Shaking(){
    servoBody.write(90 + 15);
    delay(200);
    servoBody.write(90 - 15);
    delay(200);
    servoBody.write(90);
    delay(200);
  }
