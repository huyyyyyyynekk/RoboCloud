#include "TFT_ST7789.h"
#include "TFT_Image_7789.h"

TFT_eSPI tft = TFT_eSPI();

void setup_Display(){
  tft.init();  
  tft.setRotation(3);
  tft.setSwapBytes(true);
}

void LCD_Display(const char* Emote){
  if (strcmp(Emote,"Test") == 0){
    tft.pushImage(0,0,Cat2,320,240);
  }
}
