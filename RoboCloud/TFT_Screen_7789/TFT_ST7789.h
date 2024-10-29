#ifndef TFT_SCREEN_7789
#define TFT_SCREEN_7789

#include <Adafruit_GFX.h>    
#include <Adafruit_ST7735.h> 
#include <Adafruit_ST7789.h> 
#include <SPI.h>

#define TFT_CS   15  
#define TFT_RST  26  
#define TFT_DC   25  
#define TFT_SCK  14  
#define TFT_SDI  13  
#define TFT_LED  4  

void LCD_Display(const char* Emote);

extern Adafruit_ST7789 tft;

#endif