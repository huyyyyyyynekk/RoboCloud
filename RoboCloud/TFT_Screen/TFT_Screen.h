#ifndef TFT_SCREEN_H
#define TFT_SCREEN_H

#include <TFT_22_ILI9225.h>
#include <SPI.h>
//#include "TFT_Image.h"  

#if defined(ESP32)
#include <SPI.h>
extern SPIClass hspi;  
#endif

#define TFT_RST 26
#define TFT_RS  25
#define TFT_CLK 14
#define TFT_SDI 13
#define TFT_CS  15
#define TFT_LED 0
#define TFT_BRIGHTNESS 200

#define COLOR_BLACK 0x0000

extern TFT_22_ILI9225 tft;

void setup_Display();
void Print_Emotion(const char* Emote);

#endif
