#include "Action_Servo.h"

int Head_Pos = 90;
int Plinth_Pos = 90;
int Left_Hand_Pos = 60;
int Right_Hand_Pos = 120;  

unsigned long previousMillis_Balance_Head = 0;
unsigned long previousMillis_Balance_Hand = 0;
unsigned long previousMillis_Balance_Plinth = 0;

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
unsigned long delayAt90Start = 0; //Confident_Hand

unsigned long previousMillis_Funny_HT_Head = 0;
unsigned long previousMillis_Funny_HT_Hand = 0;
unsigned long previousMillis_Funny_HT_Plinth = 0;
unsigned long delayAt30Start = 0; // Funny_HT_Hand

unsigned long previousMillis_Happy_HT_Head = 0;
unsigned long previousMillis_Happy_HT_Hand = 0;
unsigned long previousMillis_Happy_HT_Plinth = 0;
unsigned long delayAt150Start = 0;

bool waitingAt90 = false; //Confident_Hand
bool waitingAt30 = false; //Funny_HT_Hand
bool waitingAt150 = false; //Happy_HT_Hand

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

int step_Funny_HT_Head = 0;
int step_Funny_HT_Hand = 0;

int step_Happy_HT_Hand = 0;
int step_Happy_HT_Plinth = 0;

int Funny_Head_Millis = 0;
int Funny_Hand_Millis = 0;
int Funny_Plinth_Millis = 0;

int Happy_Head_Millis = 0;
int Happy_Hand_Millis = 0;
int Happy_Plinth_Millis = 0;

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

void Funny_HT_Head(){
  if (step_Funny_HT_Head == 0){
    int Pos_Funny_HT_Head = abs(120 - Head_Pos) / 5;
    Funny_Head_Millis = (Pos_Funny_HT_Head != 0) ? (500 / Pos_Funny_HT_Head) : 0;
  }
  else if (step_Funny_HT_Head == 1){
    int Pos_Funny_HT_Head = abs(60 - Head_Pos) / 5;
    Funny_Head_Millis = (Pos_Funny_HT_Head != 0) ? (500 / Pos_Funny_HT_Head) : 0;
  }
  else if (step_Funny_HT_Head == 2){
    int Pos_Funny_HT_Head = abs(90 - Head_Pos) / 5;
    Funny_Head_Millis = (Pos_Funny_HT_Head != 0) ? (500 / Pos_Funny_HT_Head) : 0;
  }
  unsigned long currentMillis_Funny_HT_Head = millis();
  if (currentMillis_Funny_HT_Head - previousMillis_Funny_HT_Head >= Funny_Head_Millis){
    previousMillis_Funny_HT_Head = currentMillis_Funny_HT_Head;
    switch (step_Funny_HT_Head){
      case 0 :
        if (Head_Pos > 120){
          Head_Pos -= 5;
          servoHead.write(Head_Pos);
        }
        else if (Head_Pos < 120){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 120){
          step_Funny_HT_Head = 1;
          break;
        }
        break;
      case 1 :
        if (Head_Pos > 60){
          Head_Pos -= 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 60){
          step_Funny_HT_Head = 2;
          break;
        }
        break;
      case 2 :
        if (Head_Pos < 90){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        break;    
    }
  }
}

void Funny_HT_Hand(){
  if (step_Funny_HT_Hand == 0){
    int maxDistance_Funny_HT_Hand = max(abs(90 - Left_Hand_Pos), abs(90 - Right_Hand_Pos));
    Funny_Hand_Millis = (maxDistance_Funny_HT_Hand > 0) ? 500 / (maxDistance_Funny_HT_Hand / 5) : 0;
  }
  else if (step_Funny_HT_Hand == 1){
    int maxDistance_Funny_HT_Hand = max(abs(30 - Left_Hand_Pos), abs(30 - Right_Hand_Pos));
    Funny_Hand_Millis = (maxDistance_Funny_HT_Hand > 0) ? 500 / (maxDistance_Funny_HT_Hand / 5) : 0;
  }
  else if (step_Funny_HT_Hand == 2){
    int maxDistance_Funny_HT_Hand = max(abs(60 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
    Funny_Hand_Millis = (maxDistance_Funny_HT_Hand > 0) ? 500 / (maxDistance_Funny_HT_Hand / 5) : 0;
  }
  unsigned long currentMillis_Funny_HT_Hand = millis();
  if (currentMillis_Funny_HT_Hand - previousMillis_Funny_HT_Hand >= Funny_Hand_Millis){
    previousMillis_Funny_HT_Hand = currentMillis_Funny_HT_Hand;
    switch (step_Funny_HT_Hand) {
      case 0 :
        if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        servoRightHand.write(Right_Hand_Pos);
        if (Left_Hand_Pos == 90 && Right_Hand_Pos == 90){
          step_Funny_HT_Hand = 1;
          break;
        }
        break;
      case 1 :
        if (Left_Hand_Pos > 30 && Right_Hand_Pos < 150){
          Left_Hand_Pos -= 5;
          Right_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        if (Left_Hand_Pos == 30 && Right_Hand_Pos == 150){
          if (!waitingAt30) {
            delayAt30Start = currentMillis_Funny_HT_Hand;
            waitingAt30 = true;
          }
          if (currentMillis_Funny_HT_Hand - delayAt30Start >= 500) {
            step_Funny_HT_Hand = 2;
            waitingAt30 = false;
            break; 
          }
        }
        break;
      case 2 :
        if (Left_Hand_Pos < 60 && Right_Hand_Pos > 120){
          Left_Hand_Pos += 5;
          Right_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }  
        break;
    }
  }
}

void Funny_HT_Plinth(){
  int Pos_Funny_HT_Plinth = abs(90 - Plinth_Pos) / 5 ;
  Funny_Plinth_Millis = (Pos_Funny_HT_Plinth != 0) ? (500 / Pos_Funny_HT_Plinth) : 0;
  unsigned long currentMillis_Funny_HT_Plinth = millis();
  if (currentMillis_Funny_HT_Plinth - previousMillis_Funny_HT_Plinth >= Funny_Plinth_Millis){
    previousMillis_Funny_HT_Plinth = currentMillis_Funny_HT_Plinth;
    if (Plinth_Pos > 90){
      Plinth_Pos -= 5;
    }
    else if (Plinth_Pos < 90){
      Plinth_Pos += 5;
    }
    servoBody.write(Plinth_Pos);
  }
}

void Happy_HT_Head(){
  int Pos_Happy_HT_Head = abs(60 - Head_Pos) / 5;
  Happy_Head_Millis = (Pos_Happy_HT_Head != 0) ? (500 / Pos_Happy_HT_Head) : 0;
  unsigned long currentMillis_Happy_HT_Head = millis();
  if (currentMillis_Happy_HT_Head - previousMillis_Happy_HT_Head >= Happy_Head_Millis){
    previousMillis_Happy_HT_Head = currentMillis_Happy_HT_Head;
    if (Head_Pos > 60){
      Head_Pos -= 5;
    }
    else if (Head_Pos < 60){
      Head_Pos += 5;
    }
    servoHead.write(Head_Pos);
  }
}

void Happy_HT_Hand(){
  if (step_Happy_HT_Hand == 0){
    int maxDistance_Happy_HT_Hand = max(abs(150 - Left_Hand_Pos), abs(150 - Right_Hand_Pos));
    Happy_Hand_Millis = (maxDistance_Happy_HT_Hand > 0) ? 500 / (maxDistance_Happy_HT_Hand / 5) : 0;
  }
  else if (step_Happy_HT_Hand == 1){
    int maxDistance_Happy_HT_Hand = max(abs(60 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
    Happy_Hand_Millis = (maxDistance_Happy_HT_Hand > 0) ? 500 / (maxDistance_Happy_HT_Hand / 5) : 0;
  }
  unsigned long currentMillis_Happy_HT_Hand = millis();
  if (currentMillis_Happy_HT_Hand - previousMillis_Happy_HT_Hand >= Happy_Hand_Millis){
    previousMillis_Happy_HT_Hand = currentMillis_Happy_HT_Hand;
    switch (step_Happy_HT_Hand){
      case 0 :
        if (Left_Hand_Pos < 150){
          Left_Hand_Pos += 5;
        }
        else if (Left_Hand_Pos > 150){
          Left_Hand_Pos -= 5;
        }
        if (Right_Hand_Pos > 30){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 30){
          Right_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        servoRightHand.write(Right_Hand_Pos);
        if (Left_Hand_Pos == 150 && Right_Hand_Pos == 30){
          if (!waitingAt150) {
            delayAt150Start = currentMillis_Happy_HT_Hand;
            waitingAt150 = true;
          }
          if (currentMillis_Happy_HT_Hand - delayAt150Start >= 1000) {
            step_Happy_HT_Hand = 1;
            waitingAt150 = false;
            break; 
          }
        }
        break;
      case 1 : 
        if (Left_Hand_Pos > 60 && Right_Hand_Pos < 120){
          Left_Hand_Pos -= 5;
          Right_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        break;  
    }
  }
}

void Happy_HT_Plinth(){
  if (step_Happy_HT_Plinth == 0){
    int Pos_Happy_HT_Plinth = abs(120 - Head_Pos) / 5;
    Happy_Plinth_Millis = (Pos_Happy_HT_Plinth != 0) ? (500 / Pos_Happy_HT_Plinth) : 0;
  }
  else if (step_Happy_HT_Plinth == 1){
    int Pos_Happy_HT_Plinth = abs(90 - Head_Pos) / 5;
    Happy_Plinth_Millis = (Pos_Happy_HT_Plinth != 0) ? (500 / Pos_Happy_HT_Plinth) : 0;
  }
  else if (step_Happy_HT_Plinth == 2){
    int Pos_Happy_HT_Plinth = abs(60 - Head_Pos) / 5;
    Happy_Plinth_Millis = (Pos_Happy_HT_Plinth != 0) ? (500 / Pos_Happy_HT_Plinth) : 0;
  }
  unsigned long currentMillis_Happy_HT_Plinth = millis();
  if (currentMillis_Happy_HT_Plinth - previousMillis_Happy_HT_Plinth >= Happy_Plinth_Millis){
    previousMillis_Happy_HT_Plinth = currentMillis_Happy_HT_Plinth;
    switch (step_Happy_HT_Plinth){
      case 0 :
        if (Plinth_Pos < 120){
          Plinth_Pos += 5;
        }
        else if (Plinth_Pos > 120){
          Plinth_Pos -= 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 120){
          step_Happy_HT_Plinth = 1;
          break;
        }
        break;
      case 1 :
        if (Plinth_Pos > 90){
          Plinth_Pos -= 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 90){
          step_Happy_HT_Plinth = 2;
          break;
        }
        break;
      case 2 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
          servoBody.write(Plinth_Pos);
        }
        break;    
    }
  }
}

void Balance_Head(){
  unsigned long currentMillis_Balance_Head = millis();
  if (currentMillis_Balance_Head - previousMillis_Balance_Head > 80){
    previousMillis_Balance_Head = currentMillis_Balance_Head;
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

void Balance_Hand(){
  unsigned long currentMillis_Balance_Hand = millis();
  if (currentMillis_Balance_Hand - previousMillis_Balance_Hand > 80){
    previousMillis_Balance_Hand = currentMillis_Balance_Hand;
    if (Left_Hand_Pos > 60){
      Left_Hand_Pos -= 5;
    }
    else if (Left_Hand_Pos < 60){
      Left_Hand_Pos += 5;
    }
    if (Right_Hand_Pos > 120){
      Right_Hand_Pos -= 5;
    }
    else if (Right_Hand_Pos < 120){
      Right_Hand_Pos += 5;
    }
    servoLeftHand.write(Left_Hand_Pos);
    servoRightHand.write(Right_Hand_Pos);
  }
}

void Balance_Plinth(){
  unsigned long currentMillis_Balance_Plinth = millis();
  if (currentMillis_Balance_Plinth - previousMillis_Balance_Plinth > 80){
    previousMillis_Balance_Plinth = currentMillis_Balance_Plinth;
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

void Happy_Head() {
  unsigned long currentMillis_Happy_Head = millis();
  if (currentMillis_Happy_Head - previousMillis_Happy_Head > 90){
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
  if (currentMillis_Happy_Hand - previousMillis_Happy_Hand > 70){
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
        if (Right_Hand_Pos > 30){
          Right_Hand_Pos -= 5;
          servoRightHand.write(Right_Hand_Pos);
        }
        if (Right_Hand_Pos == 30){
          step_Happy_Hand = 2;
          break;
        }
        break;
      case 2 :
        if (Left_Hand_Pos > 60){
          Left_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
        }
        if (Left_Hand_Pos == 60){
          step_Happy_Hand = 3;
          break;
        }
        break;
      case 3 :
        if (Right_Hand_Pos < 120){
          Right_Hand_Pos += 5;
          servoRightHand.write(Right_Hand_Pos);
        }
        break;
    }
  }
}

void Happy_Plinth(){
  unsigned long currentMillis_Happy_Plinth = millis();
  if (currentMillis_Happy_Plinth - previousMillis_Happy_Plinth > 100){
    previousMillis_Happy_Plinth = currentMillis_Happy_Plinth;
    switch (step_Happy_Plinth) {
      case 0 :
        if (Plinth_Pos < 120){
          Plinth_Pos += 5;
          servoBody.write(Plinth_Pos);
        }
        else if (Plinth_Pos > 120){
          Plinth_Pos -= 5;
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
        if (Plinth_Pos == 60){
          step_Happy_Plinth = 4;
          break;
        }
        break;
      case 4 :
        if (Plinth_Pos < 90){
          Plinth_Pos += 5;
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
        else if (Head_Pos > 120){
          Head_Pos -= 5;
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
        if (Head_Pos == 60){
          step_Funny_Head = 2;
          break;
        }
        break;
      case 2 :
        if (Head_Pos < 90){
          Head_Pos += 5;
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
        if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        else if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        servoRightHand.write(Right_Hand_Pos);
        if (Left_Hand_Pos == 90 && Right_Hand_Pos == 90){
          step_Funny_Hand = 1;
          break;
        }
        break;
      case 1 :
        if (Left_Hand_Pos > 30 && Right_Hand_Pos < 150){
          Left_Hand_Pos -= 5;
          Right_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        if (Left_Hand_Pos == 30 && Right_Hand_Pos == 150){
          step_Funny_Hand = 2;
          break;
        }
        break;
      case 2 :
        if (Left_Hand_Pos < 60 && Right_Hand_Pos > 120){
          Left_Hand_Pos += 5;
          Right_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
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
  if (currentMillis_Excited_Head - previousMillis_Excited_Head > 95){
    previousMillis_Excited_Head = currentMillis_Excited_Head;
    switch (step_Excited_Head) {
      case 0 :
        if (Head_Pos < 105){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        else if (Head_Pos > 105){
          Head_Pos -= 5;
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
        if (Head_Pos < 105){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 105){
          step_Excited_Head = 5;
          break;
        }
        break;   
      case 5 :
        if (Head_Pos > 75){
          Head_Pos -= 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 75){
          step_Excited_Head = 6;
          break;
        }
        break;  
      case 6 :
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
  if (currentMillis_Excited_Hand - previousMillis_Excited_Hand > 58){
    previousMillis_Excited_Hand = currentMillis_Excited_Hand;
    switch (step_Excited_Hand) {
      case 0 :
        if (Left_Hand_Pos < 150){
          Left_Hand_Pos += 5;
        }
        else if (Left_Hand_Pos > 150){
          Left_Hand_Pos -= 5;
        }
        if (Right_Hand_Pos > 30){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 30){
          Right_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        servoRightHand.write(Right_Hand_Pos);
        if (Left_Hand_Pos == 150 && Right_Hand_Pos == 30){
          step_Excited_Hand = 1;
          break;
        }
        break;
      case 1 :
        if (Left_Hand_Pos > 60 && Right_Hand_Pos < 120){
          Left_Hand_Pos -= 5;
          Right_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        if (Left_Hand_Pos == 60 && Right_Hand_Pos == 120){
          step_Excited_Hand = 2;
          break;
        }
        break;
      case 2:
        if (Left_Hand_Pos <= 150 && Right_Hand_Pos > 30){
          Left_Hand_Pos += 5;
          Right_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        else if (Left_Hand_Pos <= 150 && Right_Hand_Pos < 30){
          Left_Hand_Pos += 5;
          Right_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        else if (Left_Hand_Pos >= 150 && Right_Hand_Pos < 30){
          Left_Hand_Pos -= 5;
          Right_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        else if (Left_Hand_Pos >= 150 && Right_Hand_Pos > 30){
          Left_Hand_Pos += 5;
          Right_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
        }
        if (Left_Hand_Pos == 150 && Right_Hand_Pos == 30){
          step_Excited_Hand = 3;
          break;
        }
        break;
      case 3:
        if (Left_Hand_Pos > 60 && Right_Hand_Pos < 120){
          Left_Hand_Pos -= 5;
          Right_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
          servoRightHand.write(Right_Hand_Pos);
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
      else if (Plinth_Pos > 110){
        Plinth_Pos -= 5;
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
      if (Plinth_Pos == 70){
        step_Excited_Plinth = 2;
        break;
      }
      break;
     case 2 :
      if (Plinth_Pos < 90){
        Plinth_Pos += 5;
        servoBody.write(Plinth_Pos);
      }
      break;  
    }
  }
}

void Confident_Head(){
  unsigned long currentMillis_Confident_Head = millis();
  if (currentMillis_Confident_Head - previousMillis_Confident_Head > 100){
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
 
void Confident_Hand() {
  unsigned long currentMillis_Confident_Hand = millis();
  if (currentMillis_Confident_Hand - previousMillis_Confident_Hand > 110) {
    previousMillis_Confident_Hand = currentMillis_Confident_Hand;
    switch (step_Confident_Hand) {
      case 0:
        if (Right_Hand_Pos > 120){
          Right_Hand_Pos -= 5;
          servoRightHand.write(Right_Hand_Pos);
        }
        else if (Right_Hand_Pos < 120){
          Right_Hand_Pos += 5;
          servoRightHand.write(Right_Hand_Pos);
        }
        if (Right_Hand_Pos == 120){
          step_Confident_Hand = 1;
          break;
        }
        break;
      case 1:
        if (Left_Hand_Pos < 120) {
          Left_Hand_Pos += 5;
          servoLeftHand.write(Left_Hand_Pos);
        } else if (Left_Hand_Pos > 120) {
          Left_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
        }
        if (Left_Hand_Pos == 120) {
          step_Confident_Hand = 2;
        }
        break;
      case 2:
        if (Left_Hand_Pos > 90) {
          Left_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
        }
        if (Left_Hand_Pos == 90) {
          if (!waitingAt90) {
            delayAt90Start = currentMillis_Confident_Hand;
            waitingAt90 = true;
          }
          if (currentMillis_Confident_Hand - delayAt90Start >= 1500) {
            step_Confident_Hand = 3;
            waitingAt90 = false;
            break; 
          }
        }
        break;
      case 3:
        if (Left_Hand_Pos > 60) {
          Left_Hand_Pos -= 5;
          servoLeftHand.write(Left_Hand_Pos);
        }
        break;
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
 else if (strcmp(action,"FunnyHT")== 0){
      Funny_HT_Head();
      Funny_HT_Hand();
      Funny_HT_Plinth();
 }
 else if (strcmp(action,"HappyHT")== 0){
      Happy_HT_Head();
      Happy_HT_Hand();
      Happy_HT_Plinth();
 } 
 else if (strcmp(action,"Balance") == 0){
      Balance_Head();
      Balance_Hand();
      Balance_Plinth();
      step_Happy_Hand = 0;
      step_Happy_Plinth = 0;
      step_Excited_Head = 0;
      step_Excited_Hand = 0;
      step_Excited_Plinth = 0;
      step_Confident_Head = 0;
      step_Confident_Hand = 0;
      step_Confident_Plinth = 0;
      step_Funny_Head = 0;
      step_Funny_Hand = 0;
  }
}