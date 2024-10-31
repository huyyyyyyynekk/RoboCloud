#include "TFT_ST7789.h"
#include "TFT_Image_7789.h"

TFT_eSPI tft = TFT_eSPI();

unsigned long previousMillis_Funny_SCR = 0;
unsigned long previousMillis_Cute_SCR = 0;

int step_Funny_SCR = 0;
int step_Cute_SCR = 0;

void setup_Display(){
  tft.init();  
  tft.setRotation(1);
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);
}

void Funny(){
  unsigned long currentMillis_Funny_SCR = millis();
  if (currentMillis_Funny_SCR - previousMillis_Funny_SCR > 100){
    previousMillis_Funny_SCR = currentMillis_Funny_SCR;
    switch (step_Funny_SCR) {
      case 0 :
        tft.pushImage(0,0,320,240,Funny1);
        step_Funny_SCR = 1;
        break;
      case 1 :
        tft.pushImage(0,0,320,240,Funny3);
        step_Funny_SCR = 2;
        break;
      case 2 :
        tft.pushImage(0,0,320,240,Funny4);
        break;
    }
  }
}

void Cute(){
  unsigned long currentMillis_Cute_SCR = millis();
  if (currentMillis_Cute_SCR - previousMillis_Cute_SCR > 100){
    previousMillis_Cute_SCR = currentMillis_Cute_SCR;
    switch (step_Cute_SCR) {
      case 0 :
        tft.pushImage(0,0,320,240,Cute1);
        step_Cute_SCR = 1;
        break;
      case 1 :
        tft.pushImage(0,0,320,240,Cute5);
        step_Cute_SCR = 2;
        break;   
      case 2 :
        tft.pushImage(0,0,320,240,Cute6);
        break;
    }
  }
}

void LCD_Display(const char* Emote){
  if (strcmp(Emote,"Funny") == 0){
    Funny();
  }
  else if (strcmp(Emote,"Cute") == 0){
    Cute();
  }
}

