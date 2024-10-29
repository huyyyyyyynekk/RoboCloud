#include "Action_Servo.h"

int Head_Pos = 90;
int Plinth_Pos = 90;
int Left_Hand_Pos = 60;
int Right_Hand_Pos = 60;  
int Two_Hand_Pos = 60;
bool Head_First = false;
bool Plinth_First = false;
bool Left_Hand_First = false;
bool Right_Hand_First = false;
unsigned long previousMillis_Shake = 0;  
unsigned long previousMillis_LTR = 0;
unsigned long previousMillis_RTL = 0;
unsigned long previousMillis_OHW = 0;
unsigned long previousMillis_OHP = 0;
unsigned long previousMillis_Happy = 0;
unsigned long previousMillis_Excited = 0;
unsigned long previousMillis_Funny = 0;
unsigned long previousMillis_Confident = 0;
unsigned long previousMillis_THW = 0;
unsigned long previousMillis_THP = 0;
int step_Shake = 0;
int step_LTR = 0;
int step_RTL = 0;
int step_OHW_1 = 0;
int step_OHW_2 = 0;
int step_OHP_1 = 0;
int step_OHP_2 = 0;
int step_Happy = 0;
int step_Excited = 0;
int step_Confident = 0;
int step_Funny = 0;
int step_THW = 0;
int step_THP = 0;

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

/* =================================== HEAD ================================= */
void Head_Shake() {
  unsigned long currentMillis_Shake = millis();
  if (currentMillis_Shake - previousMillis_Shake >= 300) {
    previousMillis_Shake = currentMillis_Shake;  
    switch (step_Shake) {
      case 0:
        Head_Turn_Small_Left();      
        step_Shake = 1;                    
        break;
      case 1:
        Head_Turn_Small_Right();     
        step_Shake = 2;
        break;
      case 2:
        Head_Turn_Small_Left();      
        step_Shake = 3;
        break;
      case 3:
        Head_Turn_Small_Right();     
        step_Shake = 4;
        break;
      case 4:
        servoHead.write(90);                               
        break;
    }
  }
}

void Head_Look_From_Left_To_Right() {
  unsigned long currentMillis_LTR = millis();  
  if (currentMillis_LTR - previousMillis_LTR >= 200) {
    previousMillis_LTR = currentMillis_LTR;    
    switch (step_LTR) {
      case 0:
        if (Head_Pos >= 120) {   
          Head_Pos -= 4;
          servoHead.write(Head_Pos);
          if (Head_Pos <= 60) {
            Head_Pos = 60;       
            step_LTR = 1;
            break;        
          }
        } else if (Head_Pos <= 90) {  
          Head_Pos -= 4;
          servoHead.write(Head_Pos);
          if (Head_Pos <= 60) {
            Head_Pos = 60;
            step_LTR = 1; 
            break;      
          }
        }  
      case 1:
        if (Head_Pos <= 60) {     
          Head_Pos += 5;
          servoHead.write(Head_Pos);
          if (Head_Pos > 90) {
            Head_Pos = 90; 
            break;      
          }
        }
    }
  }
}

void Head_Look_From_Right_To_Left() {
  unsigned long currentMillis_RTL = millis();  
  if (currentMillis_RTL - previousMillis_RTL >= 200) {
    previousMillis_RTL = currentMillis_RTL;    
    switch (step_RTL) {
      case 0:
        if (Head_Pos >= 60) {   
          Head_Pos += 4;
          servoHead.write(Head_Pos);
          if (Head_Pos >= 120) {
            Head_Pos = 120;       
            step_RTL = 1;
            break;        
          }
        } else if (Head_Pos >= 90) {  
          Head_Pos += 4;
          servoHead.write(Head_Pos);
          if (Head_Pos >= 120) {
            Head_Pos = 120;
            step_RTL = 1; 
            break;      
          }
        }  
      case 1:
        if (Head_Pos >= 120) {     
          Head_Pos -= 5;
          servoHead.write(Head_Pos);
          if (Head_Pos > 90) {
            Head_Pos = 90; 
            break;      
          }
        }
    }
  }
}

void Head_Turn_Small_Left(){
  if (Head_Pos < 105){
    Head_Pos += 5;
    servoHead.write(Head_Pos);
  }
}

void Head_Turn_Small_Right(){
  if (Head_Pos > 75){
    Head_Pos -= 5;
    servoHead.write(Head_Pos);
  }
}

void Head_Turn_Big_Left(){
  if (Head_Pos < 120){
    Head_Pos += 5;
    servoHead.write(Head_Pos);
  }
}

void Head_Turn_Big_Right(){
  if (Head_Pos > 60){
    Head_Pos -= 5;
    servoHead.write(Head_Pos);
  }
}

void Head_Balance(){
  if (Head_Pos > 90){
    Head_Pos -= 5;
    servoHead.write(Head_Pos);
  }
  else if (Head_Pos < 90){
    Head_Pos += 5;
    servoHead.write(Head_Pos);
  }
}

/* =================================== ONE - HAND ================================= */
void One_Hand_Rising(const char* action, int X){
  if (strcmp(action, "Left Hand") == 0){
    if (Left_Hand_Pos > X){
     Left_Hand_Pos -= 5;
     servoLeftHand.write(Left_Hand_Pos);  
    }
    else if (Left_Hand_Pos < X){
      Left_Hand_Pos += 5;
      servoLeftHand.write(Left_Hand_Pos);
    }
  }
  else if (strcmp(action, "Right Hand") == 0){
    if (Right_Hand_Pos > X){
     Right_Hand_Pos -= 5;
     servoRightHand.write(Right_Hand_Pos);  
    }
    else if (Right_Hand_Pos < X){
     Right_Hand_Pos += 5;
     servoRightHand.write(Right_Hand_Pos);
    }
  }
}

void One_Hand_Balance(const char* action){
  if (strcmp(action, "Left Hand") == 0){
    if (Left_Hand_Pos > 60){
      Left_Hand_Pos -= 5;
      servoLeftHand.write(Left_Hand_Pos);
    }
    else if (Left_Hand_Pos){
      Left_Hand_Pos += 5;
      servoLeftHand.write(Left_Hand_Pos);
    }
  }
  else if (strcmp(action, "Right Hand") == 0){
    if (Right_Hand_Pos > 60){
      Right_Hand_Pos -= 5;
      servoRightHand.write(Right_Hand_Pos);
    }
    else if (Right_Hand_Pos < 60){
      Right_Hand_Pos += 5;
      servoRightHand.write(Right_Hand_Pos);
    }
  }
}

void One_Hand_Waving(int X, const char* action){
  unsigned long currentMillis_OHW = millis();  
  if (currentMillis_OHW - previousMillis_OHW >= 350) {
    previousMillis_OHW = currentMillis_OHW;
    if (strcmp(action, "Left Hand") == 0){
      switch (step_OHW_1) {
      case 0:
          Left_Hand_Pos = X;
          servoLeftHand.write(Left_Hand_Pos);
          step_OHW_1 = 1;
          break;
      case 1:
          if (Left_Hand_Pos < X + 30){
            Left_Hand_Pos += 5;
            servoLeftHand.write(Left_Hand_Pos);
          }
          if (Left_Hand_Pos == X + 30){
           step_OHW_1 = 2;
            break; 
          }
          break;
      case 2:
          Left_Hand_Pos = X; 
          servoLeftHand.write(Left_Hand_Pos);
          break;   
      }      
    }
    else if (strcmp(action, "Right Hand") == 0){
      switch (step_OHW_2) {
      case 0:
          Right_Hand_Pos = X;
          servoRightHand.write(Right_Hand_Pos);
          step_OHW_2 = 1;
          break;
      case 1:
          if (Right_Hand_Pos < X + 30){
            Right_Hand_Pos += 5;
            servoRightHand.write(Right_Hand_Pos);
          }
          if (Right_Hand_Pos == X + 30){
           step_OHW_1 = 2;
            break; 
          }
          break;
      case 2:
          Right_Hand_Pos = X; 
          servoRightHand.write(Right_Hand_Pos);
          break;   
      }
    }
  }
}

void One_Hand_Pointing(int X , const char* action){
  unsigned long currentMillis_OHP = millis();  
  if (currentMillis_OHP - previousMillis_OHP >= 350) {
    previousMillis_OHP = currentMillis_OHP;
    if (strcmp(action, "Left Hand") == 0){
      switch (step_OHP_1) {
      case 0:
          Left_Hand_Pos = X;
          servoLeftHand.write(Left_Hand_Pos);
          step_OHP_1 = 1;
          break;
      case 1:
          if (Left_Hand_Pos < X + 10){
            Left_Hand_Pos += 5;
            servoLeftHand.write(Left_Hand_Pos);
          }
          if (Left_Hand_Pos == X + 10){
           step_OHW_1 = 2;
            break; 
          }
          break;
      case 2:
          Left_Hand_Pos = X; 
          servoLeftHand.write(Left_Hand_Pos);
          break;   
      }      
    }
    else if (strcmp(action, "Right Hand") == 0){
      switch (step_OHP_2) {
      case 0:
          Right_Hand_Pos = X;
          servoRightHand.write(Right_Hand_Pos);
          step_OHP_2 = 1;
          break;
      case 1:
          if (Right_Hand_Pos < X + 10){
            Right_Hand_Pos += 5;
            servoRightHand.write(Right_Hand_Pos);
          }
          if (Right_Hand_Pos == X + 10){
           step_OHW_1 = 2;
            break; 
          }
          break;
      case 2:
          Right_Hand_Pos = X; 
          servoRightHand.write(Right_Hand_Pos);
          break;   
      }
    }
  }
}

/* =================================== TWO - HAND ================================= */

void Two_Hand_Waving(int X){
unsigned long currentMillis_THW = millis();  
  if (currentMillis_THW - previousMillis_THW >= 300) {
    previousMillis_THW = currentMillis_THW;
      switch (step_THW) {
      case 0:
          Two_Hand_Pos = X;
          servoLeftHand.write(Two_Hand_Pos);
          servoRightHand.write(Two_Hand_Pos);
          step_THW = 1;
          break;
      case 1:
          if (Two_Hand_Pos < X + 30){
            Two_Hand_Pos += 5;
            servoLeftHand.write(Two_Hand_Pos);
            servoRightHand.write(Two_Hand_Pos);
            step_THW = 2;
            break;
          }
          break;
      case 2:
          Two_Hand_Pos = X;
          servoLeftHand.write(Two_Hand_Pos);
          servoRightHand.write(Two_Hand_Pos);
          break;   
      }      
    }
  }

void Two_Hand_Pointing(int X){
  unsigned long currentMillis_THP = millis();  
  if (currentMillis_THP - previousMillis_THP >= 300) {
    previousMillis_THP = currentMillis_THP;
      switch (step_THP) {
      case 0:
          Two_Hand_Pos = X;
          servoLeftHand.write(Two_Hand_Pos);
          servoRightHand.write(Two_Hand_Pos);
          step_THP = 1;
          break;
      case 1:
          if (Two_Hand_Pos < X + 10){
            Two_Hand_Pos += 5;
            servoLeftHand.write(Two_Hand_Pos);
            servoRightHand.write(Two_Hand_Pos);
            step_THW = 2;
            break;
          }
          break;
      case 2:
          Two_Hand_Pos = X;
          servoLeftHand.write(Two_Hand_Pos);
          servoRightHand.write(Two_Hand_Pos);
          break;   
      }      
  }
}


/* =================================== PLINTH ================================= */

void Plinth_Turn_Small_Left(){
  if (Plinth_Pos < 120){
    Plinth_Pos += 5;
    servoBody.write(Plinth_Pos);
  }
}

void Plinth_Turn_Small_Right(){
  if (Plinth_Pos > 60){
    Plinth_Pos -= 5;
    servoBody.write(Plinth_Pos);
  }
}

void Plinth_Turn_Big_Left(){
  if (Plinth_Pos < 150){
    Plinth_Pos += 5;
    servoBody.write(Plinth_Pos);
  }
}

void Plinth_Turn_Big_Right(){
  if (Plinth_Pos > 30){
    Plinth_Pos -= 5;
    servoBody.write(Plinth_Pos);
  }
}

void Plinth_Balance(){
  if (Plinth_Pos > 90){
    Plinth_Pos -= 5;
    servoBody.write(Plinth_Pos);
  }
  else if (Plinth_Pos < 90){
    Plinth_Pos += 5;
    servoBody.write(Plinth_Pos);
  }
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