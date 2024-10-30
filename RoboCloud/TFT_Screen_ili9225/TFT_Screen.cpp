#include "TFT_Screen.h"
#include "TFT_Image.h"

#if defined(ESP32)
SPIClass hspi(HSPI);  
#endif

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);

void setup_Display() {
#if defined(ESP32)
  hspi.begin();
  tft.begin(hspi);
#else
  tft.begin();
#endif
  tft.setOrientation(1);
  tft.setBacklight(true);
  tft.setBackgroundColor(COLOR_BLACK);
}

void LCD_Display(const char* Emote) {
    if (strcmp(Emote, "Funny") == 0) {
      tft.drawBitmap(12,3,Funny1,195,170);
      delay(75);
      tft.drawBitmap(12,3,Funny3,195,170);
      delay(75);
      tft.drawBitmap(12,3,Funny4,195,170);
      delay(75);
      tft.drawBitmap(12,3,Funny5,195,170);
      delay(75);
    }
    else if (strcmp(Emote, "Happy") == 0){
      tft.drawBitmap(12,3,Relax1,195,170);
      delay(75);
      tft.drawBitmap(12,3,Relax4,195,170);
      delay(75);
      tft.drawBitmap(12,3,Relax5,195,170);
      delay(75);
    }
    else if (strcmp(Emote, "Excited") == 0){
      tft.drawBitmap(12,3,Cute1,195,170);
      delay(75);
      tft.drawBitmap(12,3,Cute4,195,170);
      delay(75);
      tft.drawBitmap(12,3,Cute5,195,170);
      delay(75);
    }
    else if (strcmp(Emote, "Confident") == 0){
      tft.drawBitmap(12,3,Im1,195,170);
      delay(75);
      tft.drawBitmap(12,3,Im2,195,170);  
      delay(75);
    }
}
