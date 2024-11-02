#include "Action_Servo.h"

int Head_Pos = 90;
int Plinth_Pos = 90;
int Left_Hand_Pos = 60;
int Right_Hand_Pos = 60;  
int Two_Hand_Pos = 60;

unsigned long previousMillis_Happy_Head = 0;
unsigned long previousMillis_Happy_Hand = 0;
unsigned long previousMillis_Happy_Plinth = 0;

unsigned long previousMillis_Excited_Head = 0;
unsigned long previousMillis_Excited_Hand = 0;
unsigned long previousMillis_Excited_Plinth = 0;

unsigned long previousMillis_Funny_Head = 0;
unsigned long previousMillis_Funny_Hand = 0;
unsigned long previousMillis_Funny_Plinth = 0;

unsigned long previousMillis_Confident_Head = 0;
unsigned long previousMillis_Confident_Hand = 0;
unsigned long previousMillis_Confident_Plinth = 0;

int step_Happy_Hand = 0;
int step_Happy_Plinth = 0;

int step_Excited_Head = 0;
int step_Excited_Hand = 0;
int step_Excited_Plinth = 0;

int step_Confident_Head = 0;
int step_Confident_Hand = 0;
int step_Confident_Plinth = 0;

int step_Funny_Head = 0;
int step_Funny_Hand = 0;

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
void Happy_Head() {
  unsigned long currentMillis_Happy_Head = millis();
  if (currentMillis_Happy_Head - previousMillis_Happy_Head > 110){
    previousMillis_Happy_Head = currentMillis_Happy_Head;
    if (Head_Pos > 90){
       Head_Pos -= 5;
       servoHead.write(Head_Pos);
    }
    else if (Head_Pos < 90){
       Head_Pos += 5;
       servoHead.write(Head_Pos);
    }
  }
}

void Happy_Hand(){
  unsigned long currentMillis_Happy_Hand = millis();
  if (currentMillis_Happy_Hand - previousMillis_Happy_Hand > 120){
    previousMillis_Happy_Hand = currentMillis_Happy_Hand;
    switch (step_Happy_Hand) {
      case 0 :
        if (Left_Hand_Pos < 150){
          Left_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
        }
        if (Left_Hand_Pos == 150){
          step_Happy_Hand = 1;
          break;
        }
        break;
      case 1 :
        if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
          servoRightHand.write(Right_Hand_Pos);
        }
        break;
    }
  }
}

void Happy_Plinth(){
  unsigned long currentMillis_Happy_Plinth = millis();
  if (currentMillis_Happy_Plinth - previousMillis_Happy_Plinth > 130){
    previousMillis_Happy_Plinth = currentMillis_Happy_Plinth;
    switch (step_Happy_Plinth) {
      case 0 :
        if (Plinth_Pos < 120){
          Plinth_Pos += 5;
          servoBody.write(Plinth_Pos);
        }
        if (Plinth_Pos == 120){
          step_Happy_Plinth = 1;
          break;
        }
        break;
      case 1 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
          servoBody.write(Plinth_Pos);
        }
        if (Plinth_Pos == 60){
          step_Happy_Plinth = 2;
          break;
        }
        break;
      case 2 :
        if (Plinth_Pos < 120){
          Plinth_Pos += 5;
          servoBody.write(Plinth_Pos);
        }
        if (Plinth_Pos == 120){
          step_Happy_Plinth = 3;
          break;
        }
        break;
      case 3 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
          servoBody.write(Plinth_Pos);
        }
        break;
    }
  }
}

void Funny_Head (){
  unsigned long currentMillis_Funny_Head = millis();
  if (currentMillis_Funny_Head - previousMillis_Funny_Head > 100){
    previousMillis_Funny_Head = currentMillis_Funny_Head;
    switch (step_Funny_Head) {
      case 0 :
        if (Head_Pos < 120){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 120){
          step_Funny_Head = 1;
          break;
        }
        break;
      case 1 :
        if (Head_Pos > 60){
          Head_Pos -= 5;
          servoHead.write(Head_Pos);
        }
        break;      
    }
  }
}

void Funny_Hand(){
  unsigned long currentMillis_Funny_Hand = millis();
  if (currentMillis_Funny_Hand - previousMillis_Funny_Hand > 85){
    previousMillis_Funny_Hand = currentMillis_Funny_Hand;
    switch (step_Funny_Hand) {
      case 0 :
        if (Two_Hand_Pos < 90){
          Two_Hand_Pos += 5;
          servoLeftHand.write(Two_Hand_Pos);
          servoRightHand.write(Two_Hand_Pos);
          Left_Hand_Pos = 90;
          Right_Hand_Pos = 90;
        }
        if (Two_Hand_Pos == 90){
          step_Funny_Hand = 1;
          break;
        }
        break;
      case 1 :
        if (Two_Hand_Pos > 30){
          Two_Hand_Pos -= 5;
          servoLeftHand.write(Two_Hand_Pos);
          servoRightHand.write(Two_Hand_Pos);
          Left_Hand_Pos = 30;
          Right_Hand_Pos = 30;
        }
        break;
    }
  }
}

void Funny_Plinth(){
  unsigned long currentMillis_Funny_Plinth = millis();
  if (currentMillis_Funny_Plinth - previousMillis_Funny_Plinth > 100){
    previousMillis_Funny_Plinth = currentMillis_Funny_Plinth;
    if (Plinth_Pos > 90){
       Plinth_Pos -= 5;
       servoBody.write(Plinth_Pos);
    }
    else if (Plinth_Pos < 90){
       Plinth_Pos += 5;
       servoBody.write(Plinth_Pos);
    }
  }
}

void Excited_Head(){
  unsigned long currentMillis_Excited_Head = millis();
  if (currentMillis_Excited_Head - previousMillis_Excited_Head > 80){
    previousMillis_Excited_Head = currentMillis_Excited_Head;
    switch (step_Excited_Head) {
      case 0 :
        if (Head_Pos < 105){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 105){
          step_Excited_Head = 1;
          break;
        }
        break;
      case 1 :
        if (Head_Pos > 75){
          Head_Pos -= 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 75){
          step_Excited_Head = 2;
          break;
        }
        break;
      case 2 :
        if (Head_Pos < 105){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 105){
          step_Excited_Head = 3;
          break;
        }
        break;   
      case 3 :
        if (Head_Pos > 75){
          Head_Pos -= 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 75){
          step_Excited_Head = 4;
          break;
        }
        break;
      case 4 :
        if (Head_Pos < 90){
          Head_Pos += 5;
          servoHead.write(Head_Pos);        
        }
        break;
    }
  }
}

void Excited_Hand (){
  unsigned long currentMillis_Excited_Hand = millis();
  if (currentMillis_Excited_Hand - previousMillis_Excited_Hand > 100){
    previousMillis_Excited_Hand = currentMillis_Excited_Hand;
    switch (step_Excited_Hand) {
      case 0 :
        if (Two_Hand_Pos < 150){
          Two_Hand_Pos += 5;
          servoLeftHand.write(Two_Hand_Pos);
          servoRightHand.write(Two_Hand_Pos);
          Left_Hand_Pos = 150;
          Right_Hand_Pos = 150;
        }
        break;        
    }
  }
}

void Excited_Plinth(){
  unsigned long currentMillis_Excited_Plinth = millis();
  if (currentMillis_Excited_Plinth - previousMillis_Excited_Plinth > 100){
    previousMillis_Excited_Plinth = currentMillis_Excited_Plinth;
    switch (step_Excited_Plinth) {
     case 0:
      if (Plinth_Pos < 110){
        Plinth_Pos += 5;
        servoBody.write(Plinth_Pos);
      }
      if (Plinth_Pos == 110){
        step_Excited_Plinth = 1;
        break;
      }
      break;
     case 1 :
      if (Plinth_Pos > 70){
        Plinth_Pos -= 5;
        servoBody.write(Plinth_Pos); 
      }
      break;
    }
  }
}

void Confident_Head(){
  unsigned long currentMillis_Confident_Head = millis();
  if (currentMillis_Confident_Head - previousMillis_Confident_Head > 130){
    previousMillis_Confident_Head = currentMillis_Confident_Head;
    if (Head_Pos > 90){
       Head_Pos -= 5;
       servoHead.write(Head_Pos);
    }
    else if (Head_Pos < 90){
       Head_Pos += 5;
       servoHead.write(Head_Pos);
    }
  }
}

void Confident_Hand(){
  unsigned long currentMillis_Confident_Hand = millis();
  if (currentMillis_Confident_Hand - previousMillis_Confident_Hand > 160){
    previousMillis_Confident_Hand = currentMillis_Confident_Hand;
    switch (step_Confident_Hand) {
     case 0 : 
      if (Right_Hand_Pos < 120){
        Right_Hand_Pos += 5;
        servoRightHand.write(Right_Hand_Pos);
      }
      else if (Right_Hand_Pos > 120){
        Right_Hand_Pos -= 5;
        servoRightHand.write(Right_Hand_Pos);
      }
      if (Right_Hand_Pos == 120){
        step_Confident_Hand = 1;
        break;
      }
      break;
     case 1 :
      if (Right_Hand_Pos > 90){
        Right_Hand_Pos -= 5;
        servoRightHand.write(Right_Hand_Pos);   
      } 
    }
  }
}

void Action_Servo(const char* action){
  if (strcmp(action,"Happy") == 0){
      Happy_Head();
      Happy_Hand();
      Happy_Plinth();  
 }
    
 else if (strcmp(action,"Funny") == 0){
      Funny_Head();
      Funny_Hand();
      Funny_Plinth();
 }
 else if (strcmp(action,"Excited") == 0){
      Excited_Head();
      Excited_Hand();
      Excited_Plinth();
 }
 else if (strcmp(action,"Confident") == 0){
      Confident_Head();
      Confident_Hand();
 }
 
}