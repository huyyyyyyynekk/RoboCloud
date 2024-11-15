#include "Action_Servo.h"

int Head_Pos = 90;
int Plinth_Pos = 90;
int Right_Hand_Pos = 60;
int Left_Hand_Pos = 120;  

unsigned long previousMillis_Balance_Head = 0;
unsigned long previousMillis_Balance_Hand = 0;
unsigned long previousMillis_Balance_Plinth = 0;

unsigned long previousMillis_Funny_HT_Head = 0;
unsigned long previousMillis_Funny_HT_Hand = 0;
unsigned long delayAt30Start = 0; // Funny_HT_Hand

unsigned long previousMillis_Happy_HT_Hand = 0;
unsigned long previousMillis_Happy_HT_Plinth = 0;
unsigned long delayAt150Start = 0;

unsigned long previousMillis_Cute_HT_LeftHand = 0;
unsigned long previousMillis_Cute_HT_RightHand = 0;
unsigned long previousMillis_Cute_HT_Plinth = 0;

unsigned long previousMillis_Shy_HT_Head = 0;
unsigned long previousMillis_Shy_HT_Hand = 0;
unsigned long delayAt150Start_Shy = 0;

unsigned long previousMillis_Guilty_HT_Hand = 0;
unsigned long delayAt90Start_Guilty = 0;

unsigned long previousMillis_Considering_HT_Hand = 0;
unsigned long delay_Considering = 0;

unsigned long previousMillis_Presenting_HT_Hand = 0;
unsigned long previousMillis_Presenting_HT_Plinth = 0;
unsigned long delay_Presenting = 0;

unsigned long previousMillis_Demonstrate_HT_Hand = 0;
unsigned long previousMillis_Demonstrate_HT_Plinth = 0;
unsigned long delay_Demonstrate_Hand = 0;

unsigned long previousMillis_Thinking_HT_LeftHand = 0;
unsigned long previousMillis_Thinking_HT_RightHand = 0;
unsigned long previousMillis_Thinking_HT_Plinth = 0;
unsigned long delay_Thinking_LeftHand = 0;
unsigned long delay_Thinking_RightHand = 0;

unsigned long previousMillis_Woo_HT_Head = 0;
unsigned long previousMillis_Woo_HT_Hand = 0;
unsigned long previousMillis_Woo_HT_Plinth = 0;
unsigned long delay_Woo = 0;

unsigned long previousMillis_Flattering_HT_Hand = 0;

bool waitingAt90 = false; //Confident_Hand
bool waitingAt30 = false; //Funny_HT_Hand
bool waitingAt150 = false; //Happy_HT_Hand
bool waitingAt150_Shy = false;
bool waitingAt90_Guilty = false;
bool waiting_Considering = false;
bool waiting_Presenting = false;
bool waiting_Demonstrate_Hand = false;
bool waiting_Thinking_LeftHand = false;
bool waiting_Thinking_RightHand = false;
bool waiting_Woo = false;

int step_Funny_HT_Head = 0;
int step_Funny_HT_Hand = 0;

int step_Happy_HT_Hand = 0;
int step_Happy_HT_Plinth = 0;

int step_Cute_HT_LeftHand = 0;
int step_Cute_HT_RightHand = 0;
int step_Cute_HT_Plinth = 0;

int step_Shy_HT_Head = 0;
int step_Shy_HT_Hand = 0;

int step_Guilty_HT_Hand = 0;

int step_Considering_HT_Hand = 0;

int step_Presenting_HT_Plinth = 0;

int step_Demonstrate_HT_Plinth = 0;

int step_Thinking_HT_Plinth = 0;

int step_Woo_HT_Head = 0;
int step_Woo_HT_Hand = 0;
int step_Woo_HT_Plinth = 0;

int step_Flattering_HT_Hand = 0; 

int Funny_Head_Millis = 0;
int Funny_Hand_Millis = 0;

int Happy_Hand_Millis = 0;
int Happy_Plinth_Millis = 0;

int Cute_LeftHand_Millis = 0;
int Cute_RightHand_Millis = 0;
int Cute_Plinth_Millis = 0;

int Shy_Head_Millis = 0;
int Shy_Hand_Millis = 0;

int Guilty_Hand_Millis = 0;

int Considering_Hand_Millis = 0;

int Presenting_Hand_Millis = 0;
int Presenting_Plinth_Millis = 0;

int Demonstrate_Hand_Millis = 0;
int Demonstrate_Plinth_Millis = 0;

int Thinking_LeftHand_Millis = 0;
int Thinking_RightHand_Millis = 0;
int Thinking_Plinth_Millis = 0;

int Woo_Head_Millis = 0;
int Woo_Hand_Millis = 0;
int Woo_Plinth_Millis = 0;

int Flattering_Hand_Millis = 0;

int Pos_Funny_HT_Head;
int maxDistance_Funny_HT_Hand;

int Pos_Happy_HT_Head;
int maxDistance_Happy_HT_Hand;
int Pos_Happy_HT_Plinth;

int Pos_Cute_HT_RightHand;
int Pos_Cute_HT_LeftHand;
int Pos_Cute_HT_Plinth;

int Pos_Shy_HT_Head;
int maxDistance_Shy_HT_Hand;

int maxDistance_Guilty_HT_Hand;

int Pos_Considering_HT_Hand;

int maxDistance_Presenting_HT_Hand;
int Pos_Presenting_HT_Plinth;

int Pos_Demonstrate_HT_Hand,Pos_Demonstrate_HT_Plinth;

int Pos_Thinking_HT_LeftHand,Pos_Thinking_HT_RightHand,Pos_Thinking_HT_Plinth;

int maxDistance_Woo_HT_Hand,Pos_Woo_HT_Head,Pos_Woo_HT_Plinth;

int maxDistance_Flattering_HT_Hand;

bool Funny_Head_step_check = false;
bool Funny_Hand_step_check = false;

bool Happy_Hand_step_check = false;
bool Happy_Plinth_step_check = false;

bool Cute_RightHand_step_check = false;
bool Cute_LeftHand_step_check = false;
bool Cute_Plinth_step_check = false;

bool Shy_Head_step_check = false;
bool Shy_Hand_step_check = false; 

bool Guilty_Hand_step_check = false;

bool Considering_Hand_step_check = false;

bool Presenting_Hand_step_check = false;
bool Presenting_Plinth_step_check = false;

bool Demonstrate_Hand_step_check = false;
bool Demonstrate_Plinth_step_check = false;

bool Thinking_LeftHand_step_check = false;
bool Thinking_RightHand_step_check = false;
bool Thinking_Plinth_step_check = false;

bool Woo_Head_step_check = false;
bool Woo_Hand_step_check = false;
bool Woo_Plinth_step_check = false;

bool Flattering_Hand_step_check = false;

Servo servoHead;
Servo servoLeftHand;
Servo servoRightHand;
Servo servoBody;

unsigned long previousMillis = 0;
int Pos;
int Millis;
bool check_1 = false;

void Attach_Servos() {
  servoHead.attach(Servo_Head);
  servoRightHand.attach(Servo_Right_Hand);
  servoLeftHand.attach(Servo_Left_Hand);
  servoBody.attach(Servo_Body);  
}               

void Head_Plinth_Return(int Target, int &Body_pos, int time, Servo &servo) {
  if (check_1 == false){
    Pos = abs(Target - Body_pos) / 5;
    Millis = (Pos != 0) ? (time / Pos) : 0;
    check_1 = true;
  }
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= Millis){
    previousMillis = currentMillis;
    if (Body_pos > Target){
      Body_pos -= 5;
    }
    else if (Body_pos < Target){
      Body_pos += 5;
    }
    servo.write(Body_pos);
    if (Body_pos == Target){
      check_1 = false;
    }
  }
}
void Funny_HT_Head(){
  if (Funny_Head_step_check == false) {
    if (step_Funny_HT_Head == 0) {
      Pos_Funny_HT_Head = abs(120 - Head_Pos) / 5;
      Funny_Head_Millis = (Pos_Funny_HT_Head != 0) ? (500 / Pos_Funny_HT_Head) : 0;
    } else if (step_Funny_HT_Head == 1) {
      Pos_Funny_HT_Head = abs(60 - Head_Pos) / 5;
      Funny_Head_Millis = (Pos_Funny_HT_Head != 0) ? (500 / Pos_Funny_HT_Head) : 0;
    } else if (step_Funny_HT_Head == 2) {
      Pos_Funny_HT_Head = abs(90 - Head_Pos) / 5;
      Funny_Head_Millis = (Pos_Funny_HT_Head != 0) ? (500 / Pos_Funny_HT_Head) : 0;
    }
    Funny_Head_step_check = true; 
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
          Funny_Head_step_check = false;
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
          Funny_Head_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Head_Pos < 90){
          Head_Pos += 5;
          servoHead.write(Head_Pos);
        }
        if (Head_Pos == 90){
          Funny_Head_step_check = false;
        }
        break;    
    }
  }
}
void Funny_HT_Hand(){
  if (Funny_Hand_step_check == false){
    if (step_Funny_HT_Hand == 0){
      maxDistance_Funny_HT_Hand = max(abs(90 - Left_Hand_Pos), abs(90 - Right_Hand_Pos));
      Funny_Hand_Millis = (maxDistance_Funny_HT_Hand > 0) ? 500 / (maxDistance_Funny_HT_Hand / 5) : 0;
    }
    else if (step_Funny_HT_Hand == 1){
      maxDistance_Funny_HT_Hand = max(abs(30 - Left_Hand_Pos), abs(30 - Right_Hand_Pos));
      Funny_Hand_Millis = (maxDistance_Funny_HT_Hand > 0) ? 500 / (maxDistance_Funny_HT_Hand / 5) : 0;
    }
    else if (step_Funny_HT_Hand == 2){
      maxDistance_Funny_HT_Hand = max(abs(60 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
      Funny_Hand_Millis = (maxDistance_Funny_HT_Hand > 0) ? 500 / (maxDistance_Funny_HT_Hand / 5) : 0;
    }
    Funny_Hand_step_check = true;
  }
  unsigned long currentMillis_Funny_HT_Hand = millis();
  if (currentMillis_Funny_HT_Hand - previousMillis_Funny_HT_Hand >= Funny_Hand_Millis){
    previousMillis_Funny_HT_Hand = currentMillis_Funny_HT_Hand;
    switch (step_Funny_HT_Hand) {
      case 0 :
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 90 && Right_Hand_Pos == 90){
          step_Funny_HT_Hand = 1;
          Funny_Hand_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Right_Hand_Pos > 30 && Left_Hand_Pos < 150){
          Right_Hand_Pos -= 5;
          Left_Hand_Pos += 5;
          servoRightHand.write(Right_Hand_Pos);
          servoLeftHand.write(Left_Hand_Pos);
        }
        if (Right_Hand_Pos == 30 && Left_Hand_Pos == 150){
          if (!waitingAt30) {
            delayAt30Start = currentMillis_Funny_HT_Hand;
            waitingAt30 = true;
          }
          if (currentMillis_Funny_HT_Hand - delayAt30Start >= 500) {
            step_Funny_HT_Hand = 2;
            waitingAt30 = false;
            Funny_Hand_step_check = false;
            break; 
          }
        }
        break;
      case 2 :
        if (Right_Hand_Pos < 60 && Left_Hand_Pos > 120){
          Right_Hand_Pos += 5;
          Left_Hand_Pos -= 5;
          servoRightHand.write(Right_Hand_Pos);
          servoLeftHand.write(Left_Hand_Pos);
        }
        if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
          Funny_Hand_step_check = false;
        }  
        break;
    }
  }
}
void Happy_HT_Hand(){
  if (Happy_Hand_step_check == false){
    if (step_Happy_HT_Hand == 0){
      maxDistance_Happy_HT_Hand = max(abs(150 - Left_Hand_Pos), abs(150 - Right_Hand_Pos));
      Happy_Hand_Millis = (maxDistance_Happy_HT_Hand > 0) ? 500 / (maxDistance_Happy_HT_Hand / 5) : 0;
    }
    else if (step_Happy_HT_Hand == 1){
      maxDistance_Happy_HT_Hand = max(abs(60 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
      Happy_Hand_Millis = (maxDistance_Happy_HT_Hand > 0) ? 500 / (maxDistance_Happy_HT_Hand / 5) : 0;
    }
    Happy_Hand_step_check = true;
  }
  unsigned long currentMillis_Happy_HT_Hand = millis();
  if (currentMillis_Happy_HT_Hand - previousMillis_Happy_HT_Hand >= Happy_Hand_Millis){
    previousMillis_Happy_HT_Hand = currentMillis_Happy_HT_Hand;
    switch (step_Happy_HT_Hand){
      case 0 :
        if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        else if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 150 && Left_Hand_Pos == 30){
          if (!waitingAt150) {
            delayAt150Start = currentMillis_Happy_HT_Hand;
            waitingAt150 = true;
          }
          if (currentMillis_Happy_HT_Hand - delayAt150Start >= 1000) {
            step_Happy_HT_Hand = 1;
            Happy_Hand_step_check = false;
            waitingAt150 = false;
            break; 
          }
        }
        break;
      case 1 : 
        if (Right_Hand_Pos > 60 && Left_Hand_Pos < 120){
          Right_Hand_Pos -= 5;
          Left_Hand_Pos += 5;
          servoRightHand.write(Right_Hand_Pos);
          servoLeftHand.write(Left_Hand_Pos);
        }
        if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
          Happy_Hand_step_check = false;
        }
        break;  
    }
  }
}
void Happy_HT_Plinth(){
  if (Happy_Plinth_step_check == false){
    if (step_Happy_HT_Plinth == 0){
      Pos_Happy_HT_Plinth = abs(120 - Plinth_Pos) / 5;
      Happy_Plinth_Millis = (Pos_Happy_HT_Plinth != 0) ? (500 / Pos_Happy_HT_Plinth) : 0;
    }
    else if (step_Happy_HT_Plinth == 1){
      Pos_Happy_HT_Plinth = abs(90 - Plinth_Pos) / 5;
      Happy_Plinth_Millis = (Pos_Happy_HT_Plinth != 0) ? (500 / Pos_Happy_HT_Plinth) : 0;
    } 
    else if (step_Happy_HT_Plinth == 2){
      Pos_Happy_HT_Plinth = abs(60 - Plinth_Pos) / 5;
      Happy_Plinth_Millis = (Pos_Happy_HT_Plinth != 0) ? (500 / Pos_Happy_HT_Plinth) : 0;
    }
    Happy_Plinth_step_check = true;
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
          Happy_Plinth_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Plinth_Pos > 90){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 90){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 90){
          step_Happy_HT_Plinth = 2;
          Happy_Plinth_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
          servoBody.write(Plinth_Pos);
        }
        if (Plinth_Pos == 60){
          Happy_Plinth_step_check = false;
        }
        break;    
    }
  }
}
void Cute_HT_LeftHand() {
  if (Cute_LeftHand_step_check == false){
    if (step_Cute_HT_LeftHand == 0 || step_Cute_HT_LeftHand == 2 || step_Cute_HT_LeftHand == 4 || step_Cute_HT_LeftHand == 6){
      Pos_Cute_HT_LeftHand = abs(30 - Left_Hand_Pos) / 5;
      Cute_LeftHand_Millis = (Pos_Cute_HT_LeftHand != 0) ? (500 / Pos_Cute_HT_LeftHand) : 0;
    }
    else if (step_Cute_HT_LeftHand == 1 || step_Cute_HT_LeftHand == 3 || step_Cute_HT_LeftHand == 5 || step_Cute_HT_LeftHand == 7){
      Pos_Cute_HT_LeftHand = abs(90 - Left_Hand_Pos) / 5;
      Cute_LeftHand_Millis = (Pos_Cute_HT_LeftHand != 0) ? (500 / Pos_Cute_HT_LeftHand) : 0;
    }
    Cute_LeftHand_step_check = true;
  }
  unsigned long currentMillis_Cute_HT_LeftHand = millis();
  if (currentMillis_Cute_HT_LeftHand - previousMillis_Cute_HT_LeftHand >= Cute_LeftHand_Millis){
    previousMillis_Cute_HT_LeftHand = currentMillis_Cute_HT_LeftHand;
    switch (step_Cute_HT_LeftHand) {
      case 0 :
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 30){
          step_Cute_HT_LeftHand = 1;
          Cute_LeftHand_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 90){
          step_Cute_HT_LeftHand = 2;
          Cute_LeftHand_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 30){
          step_Cute_HT_LeftHand = 3;
          Cute_LeftHand_step_check = false;
          break;
        }
        break;
      case 3 :
        if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 90){
          step_Cute_HT_LeftHand = 4;
          Cute_LeftHand_step_check = false;
          break;
        }
        break;
      case 4 :
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 30){
          step_Cute_HT_LeftHand = 5;
          Cute_LeftHand_step_check = false;
          break;
        }
        break;
      case 5 :
        if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 90){
          step_Cute_HT_LeftHand = 6;
          Cute_LeftHand_step_check = false;
          break;
        }
        break;
      case 6 :
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 30){
          step_Cute_HT_LeftHand = 7;
          Cute_LeftHand_step_check = false;
          break;
        }
        break;   
      case 7 :
        if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        if (Left_Hand_Pos == 90){
          Cute_LeftHand_step_check = false;
        }
        break;  
    }
  }
}
void Cute_HT_RightHand() {
  if (Cute_RightHand_step_check == false){
    if (step_Cute_HT_RightHand == 0 || step_Cute_HT_RightHand == 2 || step_Cute_HT_RightHand == 4 || step_Cute_HT_RightHand == 6){
      Pos_Cute_HT_RightHand = abs(90 - Right_Hand_Pos) / 5;
      Cute_RightHand_Millis = (Pos_Cute_HT_RightHand != 0) ? (500 / Pos_Cute_HT_RightHand) : 0;
    }
    else if (step_Cute_HT_RightHand == 1 || step_Cute_HT_RightHand == 3 || step_Cute_HT_RightHand == 5 || step_Cute_HT_RightHand == 7){
      Pos_Cute_HT_RightHand = abs(150 - Right_Hand_Pos) / 5;
      Cute_RightHand_Millis = (Pos_Cute_HT_RightHand != 0) ? (500 / Pos_Cute_HT_RightHand) : 0;
    }
    Cute_RightHand_step_check = true;
  }
  unsigned long currentMillis_Cute_HT_RightHand = millis();
  if (currentMillis_Cute_HT_RightHand - previousMillis_Cute_HT_RightHand >= Cute_RightHand_Millis){
    previousMillis_Cute_HT_RightHand = currentMillis_Cute_HT_RightHand;
    switch (step_Cute_HT_RightHand) {
      case 0 :
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 90){
          step_Cute_HT_RightHand = 1;
          Cute_RightHand_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150){
          step_Cute_HT_RightHand = 2;
          Cute_RightHand_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 90){
          step_Cute_HT_RightHand = 3;
          Cute_RightHand_step_check = false;
          break;
        }
        break;
      case 3 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150){
          step_Cute_HT_RightHand = 4;
          Cute_RightHand_step_check = false;
          break;
        }
        break;
      case 4 :
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 90){
          step_Cute_HT_RightHand = 5;
          Cute_RightHand_step_check = false;
          break;
        }
        break;
      case 5 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150){
          step_Cute_HT_RightHand = 6;
          Cute_RightHand_step_check = false;
          break;
        }
        break;
      case 6 :
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 90){
          step_Cute_HT_RightHand = 7;
          Cute_RightHand_step_check = false;
          break;
        }
        break;   
      case 7 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150){
          Cute_RightHand_step_check = false;
        }
        break;  
    }
  }
} 
void Cute_HT_Plinth() {
  if (Cute_Plinth_step_check == false){
    if (step_Cute_HT_Plinth == 0 || step_Cute_HT_Plinth == 3){
      int Pos_Cute_HT_Plinth = abs(60 - Plinth_Pos) / 5;
      Cute_Plinth_Millis = (Pos_Cute_HT_Plinth != 0) ? (500 / Pos_Cute_HT_Plinth) : 0;
    }
    else if (step_Cute_HT_Plinth == 1 || step_Cute_HT_Plinth == 4){
      int Pos_Cute_HT_Plinth = abs(120 - Plinth_Pos) / 5;
      Cute_Plinth_Millis = (Pos_Cute_HT_Plinth != 0) ? (1000 / Pos_Cute_HT_Plinth) : 0;
    }
    else if (step_Cute_HT_Plinth == 2 || step_Cute_HT_Plinth == 5){
      int Pos_Cute_HT_Plinth = abs(90 - Plinth_Pos) / 5;
      Cute_Plinth_Millis = (Pos_Cute_HT_Plinth != 0) ? (500 / Pos_Cute_HT_Plinth) : 0;
    }
    Cute_Plinth_step_check = true;
  }
  unsigned long currentMillis_Cute_HT_Plinth = millis();
  if (currentMillis_Cute_HT_Plinth - previousMillis_Cute_HT_Plinth >= Cute_Plinth_Millis){
    previousMillis_Cute_HT_Plinth = currentMillis_Cute_HT_Plinth;
    switch (step_Cute_HT_Plinth) {
      case 0 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 60){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 60){
          step_Cute_HT_Plinth = 1;
          Cute_Plinth_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Plinth_Pos < 120){
          Plinth_Pos += 5;
        }
        else if (Plinth_Pos > 120){
          Plinth_Pos -= 5;
        }  
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 120) {
          step_Cute_HT_Plinth = 2;
          Cute_Plinth_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Plinth_Pos > 90){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 90){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 90) {
          step_Cute_HT_Plinth = 3;
          Cute_Plinth_step_check = false;
          break;
        }
        break;
      case 3 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 60){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 60){
          step_Cute_HT_Plinth = 4;
          Cute_Plinth_step_check = false;
          break;
        }
        break;
      case 4 :
        if (Plinth_Pos < 120){
          Plinth_Pos += 5;
        }
        else if (Plinth_Pos > 120){
          Plinth_Pos -= 5;
        }  
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 120) {
          step_Cute_HT_Plinth = 5;
          Cute_Plinth_step_check = false;
          break;
        }
        break;
      case 5 :
        if (Plinth_Pos > 90){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 90){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 90){
          Cute_Plinth_step_check = false;
        }
        break;
    }
  }
} 
void Shy_HT_Head() {
  if (Shy_Head_step_check == false){
    if (step_Shy_HT_Head == 0 || step_Shy_HT_Head == 2){
      Pos_Shy_HT_Head = abs(115 - Head_Pos) / 5;
      Shy_Head_Millis = (Pos_Shy_HT_Head != 0) ? (300 / Pos_Shy_HT_Head) : 0;
    }
    else if (step_Shy_HT_Head == 1 || step_Shy_HT_Head == 3){
      Pos_Shy_HT_Head = abs(75 - Head_Pos) / 5;
      Shy_Head_Millis = (Pos_Shy_HT_Head != 0) ? (300 / Pos_Shy_HT_Head) : 0;
    }
    Shy_Head_step_check = true;
  }
  unsigned long currentMillis_Shy_HT_Head = millis();
  if (currentMillis_Shy_HT_Head - previousMillis_Shy_HT_Head >= Shy_Head_Millis){
    previousMillis_Shy_HT_Head = currentMillis_Shy_HT_Head;
    switch (step_Shy_HT_Head) {
      case 0 :
        if (Head_Pos > 115){
          Head_Pos -= 5;
        }
        else if (Head_Pos < 115){
          Head_Pos += 5;
        }
        servoHead.write(Head_Pos);
        if (Head_Pos == 115){
          step_Shy_HT_Head = 1;
          Shy_Head_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Head_Pos > 75){
          Head_Pos -= 5;
        }  
        else if (Head_Pos < 75){
          Head_Pos += 5;
        }
        servoHead.write(Head_Pos);
        if (Head_Pos == 75){
          step_Shy_HT_Head = 2;
          Shy_Head_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Head_Pos > 115){
          Head_Pos -= 5;
        }
        else if (Head_Pos < 115){
          Head_Pos += 5;
        }
        servoHead.write(Head_Pos);
        if (Head_Pos == 115){
          step_Shy_HT_Head = 3;
          Shy_Head_step_check = false;
          break;
        }
        break;
      case 3 :
        if (Head_Pos > 75){
          Head_Pos -= 5;
        }  
        else if (Head_Pos < 75){
          Head_Pos += 5;
        }
        servoHead.write(Head_Pos);
        if (Head_Pos == 75){
          Shy_Head_step_check = false;
        }
        break;  
    }
  }
}
void Shy_HT_Hand() {
  if (Shy_Hand_step_check == false){
    if (step_Shy_HT_Hand == 0){
      maxDistance_Shy_HT_Hand = max(abs(30 - Left_Hand_Pos), abs(150 - Right_Hand_Pos));
      Shy_Hand_Millis = (maxDistance_Shy_HT_Hand > 0) ? 500 / (maxDistance_Shy_HT_Hand / 5) : 0;
    }
    else if (step_Shy_HT_Hand == 1){
      maxDistance_Shy_HT_Hand = max(abs(120 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
      Shy_Hand_Millis = (maxDistance_Shy_HT_Hand > 0) ? 500 / (maxDistance_Shy_HT_Hand / 5) : 0;
    }
    Shy_Hand_step_check = true;
  }
  unsigned long currentMillis_Shy_HT_Hand = millis();
  if (currentMillis_Shy_HT_Hand - previousMillis_Shy_HT_Hand >= Shy_Hand_Millis){
    previousMillis_Shy_HT_Hand = currentMillis_Shy_HT_Hand;
    switch(step_Shy_HT_Hand) {
      case 0 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 150 && Left_Hand_Pos == 30){
          if (!waitingAt150_Shy) {
            delayAt150Start_Shy = currentMillis_Shy_HT_Hand;
            waitingAt150_Shy = true;
          }
          if (currentMillis_Shy_HT_Hand - delayAt150Start_Shy >= 2000) {
            step_Shy_HT_Hand = 1;
            waitingAt150 = false;
            Shy_Hand_step_check = false;
            break; 
          }
        }
        break;
      case 1 :
        if (Right_Hand_Pos > 60){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 60){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 120){
          Left_Hand_Pos -= 5;
        } 
        else if (Left_Hand_Pos < 120){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos); 
        if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
          Shy_Hand_step_check = false;
        }
        break;
    }
  }
}
void Guilty_HT_Hand() {
  if (Guilty_Hand_step_check == false){
    if (step_Guilty_HT_Hand == 0){
      maxDistance_Guilty_HT_Hand = max(abs(90 - Left_Hand_Pos), abs(90 - Right_Hand_Pos));
      Guilty_Hand_Millis = (maxDistance_Guilty_HT_Hand > 0) ? 500 / (maxDistance_Guilty_HT_Hand / 5) : 0;
    }
    else if (step_Guilty_HT_Hand == 1){
      maxDistance_Guilty_HT_Hand = max(abs(120 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
      Guilty_Hand_Millis = (maxDistance_Guilty_HT_Hand > 0) ? 1000 / (maxDistance_Guilty_HT_Hand / 5) : 0;
    }
    Guilty_Hand_step_check = true;
  }
  unsigned long currentMillis_Guilty_HT_Hand = millis();
  if (currentMillis_Guilty_HT_Hand - previousMillis_Guilty_HT_Hand >= Guilty_Hand_Millis){
    previousMillis_Guilty_HT_Hand = currentMillis_Guilty_HT_Hand;
    switch (step_Guilty_HT_Hand) {
      case 0 :
        if (Right_Hand_Pos > 90){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 90){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 90){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 90){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 90 && Left_Hand_Pos == 90){
          if (!waitingAt90_Guilty) {
            delayAt90Start_Guilty = currentMillis_Guilty_HT_Hand;
            waitingAt90_Guilty = true;
          }
          if (currentMillis_Guilty_HT_Hand - delayAt90Start_Guilty >= 1000) {
            step_Guilty_HT_Hand = 1;
            waitingAt90_Guilty = false;
            Guilty_Hand_step_check = false;
            break; 
          }
        }
        break;
      case 1 :
        if (Right_Hand_Pos > 60){
          Right_Hand_Pos -= 5;
        }  
        else if (Right_Hand_Pos < 60){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 120){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 120){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
          Guilty_Hand_step_check = false;
        }
        break;
    }
  }
}
void Considering_HT_Hand() {
  if (Considering_Hand_step_check == false){
    if (step_Considering_HT_Hand == 0){
      Pos_Considering_HT_Hand = abs(150 - Right_Hand_Pos) / 5;
      Considering_Hand_Millis = (Pos_Considering_HT_Hand != 0) ? (500 / Pos_Considering_HT_Hand) : 0;
    }
    else if (step_Considering_HT_Hand == 1 || step_Considering_HT_Hand == 3){
      Pos_Considering_HT_Hand = abs(120 - Right_Hand_Pos) / 5;
      Considering_Hand_Millis = (Pos_Considering_HT_Hand != 0) ? (300 / Pos_Considering_HT_Hand) : 0;
    }
    else if (step_Considering_HT_Hand == 2 || step_Considering_HT_Hand == 4){
      Pos_Considering_HT_Hand = abs(150 - Right_Hand_Pos) / 5;
      Considering_Hand_Millis = (Pos_Considering_HT_Hand != 0) ? (200 / Pos_Considering_HT_Hand) : 0;
    }
    Considering_Hand_step_check = true;
  }
  unsigned long currentMillis_Considering_HT_Hand = millis();
  if (currentMillis_Considering_HT_Hand - previousMillis_Considering_HT_Hand >= Considering_Hand_Millis){
    previousMillis_Considering_HT_Hand = currentMillis_Considering_HT_Hand;
    switch (step_Considering_HT_Hand) {
      case 0 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150){
          if (!waiting_Considering) {
            delay_Considering = currentMillis_Considering_HT_Hand;
            waiting_Considering = true;
          }
          if (currentMillis_Considering_HT_Hand - delay_Considering >= 500) {
            step_Considering_HT_Hand = 1;
            waiting_Considering = false;
            Considering_Hand_step_check = false;
            break; 
          }
        }
        break;
      case 1 :
        if (Right_Hand_Pos > 120){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 120){
          Right_Hand_Pos += 5;
        }  
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 120){
          step_Considering_HT_Hand = 2;
          Considering_Hand_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150){
          if (!waiting_Considering) {
            delay_Considering = currentMillis_Considering_HT_Hand;
            waiting_Considering = true;
          }
          if (currentMillis_Considering_HT_Hand - delay_Considering >= 500) {
            step_Considering_HT_Hand = 3;
            waiting_Considering = false;
            Considering_Hand_step_check = false;
            break; 
          }
        }
        break;
      case 3 :
        if (Right_Hand_Pos > 120){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 120){
          Right_Hand_Pos += 5;
        }  
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 120){
          step_Considering_HT_Hand = 4;
          Considering_Hand_step_check = false;
          break;
        }
        break;
      case 4 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150){
          Considering_Hand_step_check = false;
        }
        break;
    }
  }
}
void Flattering_HT_Hand() {
  if (Flattering_Hand_step_check == false){
    if (step_Flattering_HT_Hand == 0 || step_Flattering_HT_Hand == 2){
      maxDistance_Flattering_HT_Hand = max(abs(30 - Left_Hand_Pos), abs(150 - Right_Hand_Pos));
      Flattering_Hand_Millis = (maxDistance_Flattering_HT_Hand > 0) ? 1000 / (maxDistance_Flattering_HT_Hand / 5) : 0;
    }
    else if (step_Flattering_HT_Hand == 1 || step_Flattering_HT_Hand == 3){
      maxDistance_Flattering_HT_Hand = max(abs(120 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
      Flattering_Hand_Millis = (maxDistance_Flattering_HT_Hand > 0) ? 1000 / (maxDistance_Flattering_HT_Hand / 5) : 0;
    }
    Flattering_Hand_step_check = true;
  }
  unsigned long currentMillis_Flattering_HT_Hand = millis();
  if (currentMillis_Flattering_HT_Hand - previousMillis_Flattering_HT_Hand >= Flattering_Hand_Millis){
    previousMillis_Flattering_HT_Hand = currentMillis_Flattering_HT_Hand;
    switch (step_Flattering_HT_Hand) {
      case 0 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 150 && Left_Hand_Pos == 30){
          step_Flattering_HT_Hand = 1;
          Flattering_Hand_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Right_Hand_Pos > 60){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 60){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 120){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 120){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
          step_Flattering_HT_Hand = 2;
          Flattering_Hand_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 150 && Left_Hand_Pos == 30){
          step_Flattering_HT_Hand = 3;
          Flattering_Hand_step_check = false;
          break;
        }
        break;    
      case 3 :
        if (Right_Hand_Pos > 60){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 60){
          Right_Hand_Pos += 5;
        }
        if (Left_Hand_Pos > 120){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 120){
          Left_Hand_Pos += 5;
        }
        servoRightHand.write(Right_Hand_Pos);
        servoLeftHand.write(Left_Hand_Pos);
        if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
          Flattering_Hand_step_check = false;
          break;
        }
        break;    
    }
  }
}
void Presenting_HT_Hand() {
  if (Presenting_Hand_step_check){
    maxDistance_Presenting_HT_Hand = max(abs(120 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
    Presenting_Hand_Millis = (maxDistance_Presenting_HT_Hand > 0) ? 500 / (maxDistance_Presenting_HT_Hand / 5) : 0;
    Presenting_Hand_step_check = true;
  }
  unsigned long currentMillis_Presenting_HT_Hand = millis();
  if (currentMillis_Presenting_HT_Hand - previousMillis_Presenting_HT_Hand >= Presenting_Hand_Millis){
    previousMillis_Presenting_HT_Hand = currentMillis_Presenting_HT_Hand;
    if (Right_Hand_Pos > 60){
      Right_Hand_Pos -= 5;
    }
    else if (Right_Hand_Pos < 60){
      Right_Hand_Pos += 5;
    }
    if (Left_Hand_Pos > 120){
      Left_Hand_Pos -= 5;
    }
    else if (Left_Hand_Pos < 120){
      Left_Hand_Pos += 5;
    }
    servoRightHand.write(Right_Hand_Pos);
    servoLeftHand.write(Left_Hand_Pos);
    if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
      Presenting_Hand_step_check = false;
    }
  }
}
void Presenting_HT_Plinth() {
  if (Presenting_Plinth_step_check == false){
    if (step_Presenting_HT_Plinth == 0){
      Pos_Presenting_HT_Plinth = abs(120 - Plinth_Pos) / 5;
      Presenting_Plinth_Millis = (Pos_Presenting_HT_Plinth != 0) ? (1000 / Pos_Presenting_HT_Plinth) : 0;
    }
    else if (step_Presenting_HT_Plinth == 1){
      Pos_Presenting_HT_Plinth = abs(60 - Plinth_Pos) / 5;
      Presenting_Plinth_Millis = (Pos_Presenting_HT_Plinth != 0) ? (1000 / Pos_Presenting_HT_Plinth) : 0;
    }
    else if (step_Presenting_HT_Plinth == 2){
      Pos_Presenting_HT_Plinth = abs(90 - Plinth_Pos) / 5;
      Presenting_Plinth_Millis = (Pos_Presenting_HT_Plinth != 0) ? (500 / Pos_Presenting_HT_Plinth) : 0;
    }
    Presenting_Plinth_step_check = true;
  }
  unsigned long currentMillis_Presenting_HT_Plinth = millis();
  if (currentMillis_Presenting_HT_Plinth- previousMillis_Presenting_HT_Plinth >= Presenting_Plinth_Millis){
    previousMillis_Presenting_HT_Plinth = currentMillis_Presenting_HT_Plinth;
    switch (step_Presenting_HT_Plinth) {
      case 0 :
        if (Plinth_Pos > 120){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 120){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 120){
          if (!waiting_Presenting) {
            delay_Presenting = currentMillis_Presenting_HT_Plinth;
            waiting_Presenting = true;
          }
          if (currentMillis_Presenting_HT_Plinth - delay_Presenting >= 500) {
            step_Presenting_HT_Plinth = 1;
            waiting_Presenting = false;
            Presenting_Plinth_step_check = false;
            break; 
          }
        }
        break;
      case 1 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
        } 
        else if (Plinth_Pos < 60){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 60){
          step_Presenting_HT_Plinth = 2;
          Presenting_Plinth_step_check = false;
          break;
        } 
        break;
      case 2 :
        if (Plinth_Pos > 90){
          Plinth_Pos -= 5;
        } 
        else if (Plinth_Pos < 90){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 90){
          Presenting_Plinth_step_check = false;
          break;
        } 
        break;
    }
  }
}
void Demonstrate_HT_Hand() {
  if (Demonstrate_Hand_step_check == false){
    Pos_Demonstrate_HT_Hand = abs(150 - Right_Hand_Pos) / 5;
    Demonstrate_Hand_Millis = (Pos_Demonstrate_HT_Hand != 0) ? (500 / Pos_Demonstrate_HT_Hand) : 0;
    Demonstrate_Hand_step_check = true;
  }
  unsigned long currentMillis_Demonstrate_HT_Hand = millis();
  if (currentMillis_Demonstrate_HT_Hand - previousMillis_Demonstrate_HT_Hand >= Demonstrate_Hand_Millis){
    previousMillis_Demonstrate_HT_Hand = currentMillis_Demonstrate_HT_Hand;
    if (Right_Hand_Pos > 150){
      Right_Hand_Pos -= 5;
    }
    else if (Right_Hand_Pos < 150){
      Right_Hand_Pos += 5;
    }
    servoRightHand.write(Right_Hand_Pos);
    if (Right_Hand_Pos == 150){
      if (!waiting_Demonstrate_Hand) {
        delay_Demonstrate_Hand = currentMillis_Demonstrate_HT_Hand;
        waiting_Demonstrate_Hand = true;
      }
      if (currentMillis_Demonstrate_HT_Hand - delay_Demonstrate_Hand >= 1000) {
        waiting_Demonstrate_Hand = false;
        Demonstrate_Hand_step_check = false;
      }
    }
  }
}
void Demonstrate_HT_Plinth() {
  if (Demonstrate_Plinth_step_check == false){
    if (step_Demonstrate_HT_Plinth == 0){
      Demonstrate_Plinth_Millis = 500;
    }
    else if (step_Demonstrate_HT_Plinth == 1){
      Pos_Demonstrate_HT_Plinth = abs(120 - Plinth_Pos) / 5;
      Demonstrate_Plinth_Millis = (Pos_Demonstrate_HT_Plinth != 0) ? (200 / Pos_Demonstrate_HT_Plinth) : 0;
    }
    else if (step_Demonstrate_HT_Plinth == 2){
      Pos_Demonstrate_HT_Plinth = abs(90 - Plinth_Pos) / 5;
      Demonstrate_Plinth_Millis = (Pos_Demonstrate_HT_Plinth != 0) ? (300 / Pos_Demonstrate_HT_Plinth) : 0;
    }
    Demonstrate_Plinth_step_check = true;
  }
  unsigned long currentMillis_Demonstrate_HT_Plinth = millis();
  if (currentMillis_Demonstrate_HT_Plinth - previousMillis_Demonstrate_HT_Plinth >= Demonstrate_Plinth_Millis){
    previousMillis_Demonstrate_HT_Plinth = currentMillis_Demonstrate_HT_Plinth;
    switch (step_Demonstrate_HT_Plinth) {
      case 0 :
        step_Demonstrate_HT_Plinth = 1;
        Demonstrate_Plinth_step_check = false;
        break;
      case 1 :
        if (Plinth_Pos > 120){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 120){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 120){
          step_Demonstrate_HT_Plinth = 2;
          Demonstrate_Plinth_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Plinth_Pos > 90){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 90){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 90){
          Demonstrate_Plinth_step_check = false;
          break;
        }
        break;
    }
  } 
}
void Thinking_HT_LeftHand() {
  if (Thinking_LeftHand_step_check == false){
    Pos_Thinking_HT_LeftHand = abs(90 - Left_Hand_Pos) / 5;
    Thinking_LeftHand_Millis = (Pos_Thinking_HT_LeftHand != 0) ? (1000 / Pos_Thinking_HT_LeftHand) : 0;
    Thinking_LeftHand_step_check = true;
  }
  unsigned long currentMillis_Thinking_HT_LeftHand = millis();
  if (currentMillis_Thinking_HT_LeftHand - previousMillis_Thinking_HT_LeftHand >= Thinking_LeftHand_Millis){
    previousMillis_Thinking_HT_LeftHand = currentMillis_Thinking_HT_LeftHand;
    if (Left_Hand_Pos > 90){
      Left_Hand_Pos -= 5;
    }
    else if (Left_Hand_Pos < 90){
      Left_Hand_Pos += 5;
    }
    servoLeftHand.write(Left_Hand_Pos);
    if (Left_Hand_Pos == 90){
      if (!waiting_Thinking_LeftHand) {
        delay_Thinking_LeftHand = currentMillis_Thinking_HT_LeftHand;
        waiting_Thinking_LeftHand = true;
      }
      if (currentMillis_Thinking_HT_LeftHand - delay_Thinking_LeftHand >= 1000) {
        waiting_Thinking_LeftHand = false;
        Thinking_LeftHand_step_check = false;
      }
    }
  }
}
void Thinking_HT_RightHand() {
  if (Thinking_RightHand_step_check == false){
    Pos_Thinking_HT_RightHand = abs(150 - Right_Hand_Pos) / 5;
    Thinking_RightHand_Millis = (Pos_Thinking_HT_RightHand != 0) ? (1000 / Pos_Thinking_HT_RightHand) : 0;
    Thinking_RightHand_step_check = true;
  }
  unsigned long currentMillis_Thinking_HT_RightHand = millis();
  if (currentMillis_Thinking_HT_RightHand - previousMillis_Thinking_HT_RightHand >= Thinking_RightHand_Millis){
    previousMillis_Thinking_HT_RightHand = currentMillis_Thinking_HT_RightHand;
    if (Right_Hand_Pos > 150){
      Right_Hand_Pos -= 5;
    }
    else if (Right_Hand_Pos < 150){
      Right_Hand_Pos += 5;
    }
    servoRightHand.write(Right_Hand_Pos);
    if (Right_Hand_Pos == 150){
      if (!waiting_Thinking_RightHand) {
        delay_Thinking_RightHand = currentMillis_Thinking_HT_RightHand;
        waiting_Thinking_RightHand = true;
      }
      if (currentMillis_Thinking_HT_RightHand - delay_Thinking_RightHand >= 1000) {
        waiting_Thinking_RightHand = false;
        Thinking_RightHand_step_check = false;
      }
    }
  }
}
void Thinking_HT_Plinth() {
  if (Thinking_Plinth_step_check == false){
    if (step_Thinking_HT_Plinth == 0){
      Pos_Thinking_HT_Plinth = abs(60 - Plinth_Pos) / 5;
      Thinking_Plinth_Millis = (Pos_Thinking_HT_Plinth != 0) ? (500 / Pos_Thinking_HT_Plinth) : 0;
    }
    else if (step_Thinking_HT_Plinth == 1){
      Pos_Thinking_HT_Plinth = abs(120 - Plinth_Pos) / 5;
      Thinking_Plinth_Millis = (Pos_Thinking_HT_Plinth != 0) ? (1000 / Pos_Thinking_HT_Plinth) : 0;
    }
    else if (step_Thinking_HT_Plinth == 2){
      Pos_Thinking_HT_Plinth = abs(90 - Plinth_Pos) / 5;
      Thinking_Plinth_Millis = (Pos_Thinking_HT_Plinth != 0) ? (500 / Pos_Thinking_HT_Plinth) : 0;
    }
    Thinking_Plinth_step_check = true;
  }
  unsigned long currentMillis_Thinking_HT_Plinth = millis();
  if (currentMillis_Thinking_HT_Plinth - previousMillis_Thinking_HT_Plinth >= Thinking_Plinth_Millis){
    previousMillis_Thinking_HT_Plinth = currentMillis_Thinking_HT_Plinth;
    switch (step_Thinking_HT_Plinth) {
      case 0 :   
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 60){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 60){
          step_Thinking_HT_Plinth = 1;
          Thinking_Plinth_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Plinth_Pos > 120){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 120){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 120){
          step_Thinking_HT_Plinth = 2;
          Thinking_Plinth_step_check = false;
          break;
        }
        break;
      case 2 :
        if (Plinth_Pos > 90){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 90){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 90){
          Thinking_Plinth_step_check = false;
          break;
        }
        break;  
    }
  }
}
void Woo_HT_Head() {
  if (Woo_Head_step_check == false){
    if (step_Woo_HT_Head == 0){
      Pos_Woo_HT_Head = abs(150 - Head_Pos) / 5;
      Woo_Head_Millis = (Pos_Woo_HT_Head != 0) ? (1000 / Pos_Woo_HT_Head) : 0;
    }
    else if (step_Woo_HT_Head == 1){
      Pos_Woo_HT_Head = abs(60 - Plinth_Pos) / 5;
      Woo_Head_Millis = (Pos_Woo_HT_Head != 0) ? (1500 / Pos_Woo_HT_Head) : 0;
    }
    Woo_Head_step_check = true;
  }
  unsigned long currentMillis_Woo_HT_Head = millis();
  if (currentMillis_Woo_HT_Head - previousMillis_Woo_HT_Head >= Woo_Head_Millis){
    previousMillis_Woo_HT_Head = currentMillis_Woo_HT_Head;
    switch (step_Woo_HT_Head) {
      case 0 :
        if (Head_Pos > 150){
          Head_Pos -= 5;
        }
        else if (Head_Pos < 150){
          Head_Pos += 5;
        }
        servoHead.write(Head_Pos);
        if (Head_Pos == 150){
          step_Woo_HT_Head = 1;
          Woo_Head_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Head_Pos > 60){
          Head_Pos -= 5;
        }
        else if (Head_Pos < 60){
          Head_Pos += 5;
        }
        servoHead.write(Head_Pos);
        if (Head_Pos == 60){
          Woo_Head_step_check = false;
          break;
        }
        break;  
    }
  }
}
void Woo_HT_Hand() {
   if (Woo_Hand_step_check == false){
    if (step_Woo_HT_Hand == 0){
      maxDistance_Woo_HT_Hand = max(abs(30 - Left_Hand_Pos), abs(150 - Right_Hand_Pos));
      Woo_Hand_Millis = (maxDistance_Woo_HT_Hand > 0) ? 500 / (maxDistance_Woo_HT_Hand / 5) : 0;
    }
    else if (step_Woo_HT_Hand == 1){
      maxDistance_Woo_HT_Hand = max(abs(120 - Left_Hand_Pos), abs(60 - Right_Hand_Pos));
      Woo_Hand_Millis = (maxDistance_Woo_HT_Hand > 0) ? 500 / (maxDistance_Woo_HT_Hand / 5) : 0;
    }
    Woo_Hand_step_check = true;
  }
  unsigned long currentMillis_Woo_HT_Hand = millis();
  if (currentMillis_Woo_HT_Hand - previousMillis_Woo_HT_Hand >= Woo_Hand_Millis){
    previousMillis_Woo_HT_Hand = currentMillis_Woo_HT_Hand;
    switch (step_Woo_HT_Hand) {
      case 0 :
        if (Left_Hand_Pos > 30){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 30){
          Left_Hand_Pos += 5;
        }
        if (Right_Hand_Pos > 150){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 150){
          Right_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 150 && Left_Hand_Pos == 30){
          if (!waiting_Woo) {
            delay_Woo = currentMillis_Woo_HT_Hand;
            waiting_Woo = true;
          }
          if (currentMillis_Woo_HT_Hand - delay_Woo >= 1000) {
            waiting_Woo = false;
            step_Woo_HT_Hand = 1; 
            Woo_Hand_step_check = false;
            break;
          }
        }
        break;
      case 1 :
        if (Left_Hand_Pos > 120){
          Left_Hand_Pos -= 5;
        }
        else if (Left_Hand_Pos < 120){
          Left_Hand_Pos += 5;
        }
        if (Right_Hand_Pos > 60){
          Right_Hand_Pos -= 5;
        }
        else if (Right_Hand_Pos < 60){
          Right_Hand_Pos += 5;
        }
        servoLeftHand.write(Left_Hand_Pos);
        servoRightHand.write(Right_Hand_Pos);
        if (Right_Hand_Pos == 60 && Left_Hand_Pos == 120){
          Woo_Hand_step_check = false;
          break;
        }
        break;  
    }
  }
}
void Woo_HT_Plinth() {
  if (Woo_Plinth_step_check == false){
    if (step_Woo_HT_Plinth == 0){
      Pos_Woo_HT_Plinth = abs(150 - Plinth_Pos) / 5;
      Woo_Plinth_Millis = (Pos_Woo_HT_Plinth != 0) ? (1000 / Pos_Woo_HT_Plinth) : 0;
    }
    else if (step_Woo_HT_Plinth == 1){
      Pos_Woo_HT_Plinth = abs(60 - Plinth_Pos) / 5;
      Woo_Plinth_Millis = (Pos_Woo_HT_Plinth != 0) ? (1500 / Pos_Woo_HT_Plinth) : 0;
    }
    Woo_Plinth_step_check = true;
  }
  unsigned long currentMillis_Woo_HT_Plinth = millis();
  if (currentMillis_Woo_HT_Plinth - previousMillis_Woo_HT_Plinth >= Woo_Plinth_Millis){
    previousMillis_Woo_HT_Plinth = currentMillis_Woo_HT_Plinth;
    switch (step_Woo_HT_Plinth) {
      case 0 :
        if (Plinth_Pos > 60){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 60){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 60){
          step_Woo_HT_Plinth = 1;
          Woo_Plinth_step_check = false;
          break;
        }
        break;
      case 1 :
        if (Plinth_Pos > 150){
          Plinth_Pos -= 5;
        }
        else if (Plinth_Pos < 150){
          Plinth_Pos += 5;
        }
        servoBody.write(Plinth_Pos);
        if (Plinth_Pos == 150){
          Woo_Plinth_step_check = false;
          break;
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
    if (Right_Hand_Pos > 60){
      Right_Hand_Pos -= 5;
    }
    else if (Right_Hand_Pos < 60){
      Right_Hand_Pos += 5;
    }
    if (Left_Hand_Pos > 120){
      Left_Hand_Pos -= 5;
    }
    else if (Left_Hand_Pos < 120){
      Left_Hand_Pos += 5;
    }
    servoRightHand.write(Right_Hand_Pos);
    servoLeftHand.write(Left_Hand_Pos);
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
void Action_Servo(const char* action){
  if (strcmp(action,"Funny")== 0){
      Funny_HT_Head();
      Funny_HT_Hand();
      Head_Plinth_Return(90,Plinth_Pos,1000,servoBody);
  }
  else if (strcmp(action,"Happy")== 0){
      Head_Plinth_Return(60,Head_Pos,500,servoHead);
      Happy_HT_Hand();
      Happy_HT_Plinth();
  } 
  else if (strcmp(action,"Cute") == 0){
      Head_Plinth_Return(120,Head_Pos,500,servoHead);
      Cute_HT_LeftHand();
      Cute_HT_RightHand();
      Cute_HT_Plinth();
  }
  else if (strcmp(action,"Shy") == 0){
      Shy_HT_Head();
      Shy_HT_Hand();
      Head_Plinth_Return(90,Plinth_Pos,500,servoBody);
  }
  else if (strcmp(action,"Guilty") == 0){
      Head_Plinth_Return(90,Head_Pos,500,servoHead);
      Guilty_HT_Hand();
      Head_Plinth_Return(90,Plinth_Pos,1000,servoBody);
  }
  else if (strcmp(action,"Considering") == 0){
      Head_Plinth_Return(90,Head_Pos,500,servoHead);
      Considering_HT_Hand();
      Head_Plinth_Return(90,Plinth_Pos,500,servoBody);
  }
  else if (strcmp(action,"Presenting") == 0){
      Head_Plinth_Return(90,Head_Pos,500,servoHead);
      Presenting_HT_Hand();
      Presenting_HT_Plinth();
  }
  else if (strcmp(action,"Flattering") == 0){
      Head_Plinth_Return(90,Head_Pos,500,servoHead);
      Flattering_HT_Hand();
      Head_Plinth_Return(90,Plinth_Pos,500,servoBody);
  }
  else if (strcmp(action,"Demonstrate") == 0){
      Head_Plinth_Return(90,Head_Pos,500,servoHead);
      Demonstrate_HT_Hand();
      Demonstrate_HT_Plinth();
  }
  else if (strcmp(action,"Thinking") == 0){
      Head_Plinth_Return(90,Head_Pos,500,servoHead);
      Thinking_HT_RightHand();
      Thinking_HT_LeftHand();
      Thinking_HT_Plinth();
  }
  else if (strcmp(action,"Woo") == 0){
      Woo_HT_Head();
      Woo_HT_Hand();
      Woo_HT_Plinth();
  }
  else if (strcmp(action,"Balance") == 0){
      Balance_Head();
      Balance_Hand();
      Balance_Plinth();
      step_Funny_HT_Head = 0;
      step_Funny_HT_Hand = 0;
      step_Happy_HT_Hand = 0;
      step_Happy_HT_Plinth = 0;
      step_Cute_HT_LeftHand = 0;
      step_Cute_HT_RightHand = 0;
      step_Cute_HT_Plinth = 0;
      step_Shy_HT_Head = 0;
      step_Shy_HT_Hand = 0;
      step_Guilty_HT_Hand = 0;
      step_Considering_HT_Hand = 0;
      step_Presenting_HT_Plinth = 0;
      step_Demonstrate_HT_Plinth = 0;
      step_Thinking_HT_Plinth = 0;
      step_Woo_HT_Head = 0;
      step_Woo_HT_Hand = 0;
      step_Woo_HT_Plinth = 0;
      step_Flattering_HT_Hand = 0;
  }
}

