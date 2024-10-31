#ifndef TFT_SCREEN_7789
#define TFT_SCREEN_7789

#include <SPI.h>
#include <TFT_eSPI.h>

/*
#define TFT_CS   15  // Chan CS
#define TFT_RST  26  // Chan Reset
#define TFT_DC   25  // Chan Data/Command
#define TFT_SCLK  14  // Chan SCK (HSPI-SCK)
#define TFT_MOSI  13  // Chan MOSI (HSPI-MOSI)    
*/

void LCD_Display(const char* Emote);
void setup_Display();

extern TFT_eSPI tft ;
#endif