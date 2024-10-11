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

void Print_Emotion(const char* Emote) {
    if (strcmp(Emote, "Smile") == 0) {
      tft.drawBitmap(12,3,Smile_1,195,170);
      delay(50);
      tft.drawBitmap(12,3,Smile_2,195,170);  
      delay(50);
      tft.drawBitmap(12,3,Smile_3,195,170);
      delay(50);
      tft.drawBitmap(12,3,Smile_4,195,170);
      delay(50);
      tft.drawBitmap(12,3,Smile_5,195,170);
      delay(50);
      tft.drawBitmap(12,3,Smile_6,195,170);
      delay(50);
      tft.drawBitmap(12,3,Smile_7,195,170);  
      delay(50);
    }
}
