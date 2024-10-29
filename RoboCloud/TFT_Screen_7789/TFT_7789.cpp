#include "TFT_7789.h"
#include "TFT_Image_7789.h"

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_SDI, TFT_SCK, TFT_RST);

void setup_Display(){
  tft.init(240, 320);  
  tft.setSPISpeed(40000000); 
  tft.setRotation(3);
  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH);
  tft.fillScreen(ST77XX_WHITE);
}

void LCD_Display(const char* Emote){
  if (strcmp(Emote,"Test") == 0){
    tft.drawRGBBitmap(0,0,Funny1,195,170);
  }
}
