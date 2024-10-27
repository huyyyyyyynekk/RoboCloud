#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include "Image.h"
#include "Image_2.h"
#include "Image_3.h"
#include "Image_4.h"
#include "Image_5.h"

#ifdef ARDUINO_ARCH_STM32F1
#define TFT_RST PA1
#define TFT_RS  PA2
#define TFT_CS  PA0 // SS
#define TFT_SDI PA7 // MOSI
#define TFT_CLK PA5 // SCK
#define TFT_LED 0   // 0 if wired to +5V directly
#elif defined(ESP8266)
#define TFT_RST 4   // D2
#define TFT_RS  5   // D1
#define TFT_CLK 14  // D5 SCK
//#define TFT_SDO 12  // D6 MISO
#define TFT_SDI 13  // D7 MOSI
#define TFT_CS  15  // D8 SS
#define TFT_LED 2   // D4     set 0 if wired to +5V directly -> D3=0 is not possible !!
#elif defined(ESP32)
#define TFT_RST 26  // IO 26
#define TFT_RS  25  // IO 25
#define TFT_CLK 14  // HSPI-SCK
//#define TFT_SDO 12  // HSPI-MISO
#define TFT_SDI 13  // HSPI-MOSI
#define TFT_CS  15  // HSPI-SS0
#define TFT_LED 0   // 0 if wired to +5V directly
SPIClass hspi(HSPI);
#else
#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  // SS
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
#define TFT_LED 3   // 0 if wired to +5V directly
#endif

#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

// Use hardware SPI (faster - on Uno: 13-SCK, 12-MISO, 11-MOSI)
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);
// Use software SPI (slower)
//TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED, TFT_BRIGHTNESS);

#define SCREEN_WIDTH 180  // Chiều rộng màn hình
#define SCREEN_HEIGHT 220  // Chiều cao màn hình
#define COLOR_FACE 0xFFE0  // Màu vàng nhạt cho khuôn mặt
#define COLOR_BLACK 0x0000  // Màu đen cho mắt, miệng
#define COLOR_WHITE 0xFFFF  // Màu trắng cho nền mắt
#define COLOR_RED 0xF800    // Màu đỏ cho lưỡi khi cười
#define COLOR_SKY_BLUE 0x87CEEB

void setup() {
#if defined(ESP32)
  hspi.begin();
  tft.begin(hspi);
#else
  tft.begin();
#endif
  Serial.begin(9600);
  tft.setOrientation(1);  // Đặt hướng màn hình ngang
  tft.setBacklight(true);  // Bật đèn nền
  tft.setBackgroundColor(COLOR_BLACK);
  
  tft.drawBitmap(12,3,Test1,195,170);
  delay(300);
  tft.drawBitmap(96,125,Mouth_2,20,8);
  delay(300);
  tft.drawBitmap(96,125,Mouth_3,20,8);
  delay(300);
  tft.drawBitmap(96,125,Mouth_4,20,8);
  delay(300);
  tft.drawBitmap(97,125,Mouth_5,20,8);
  delay(300);
  tft.drawBitmap(96,125,Mouth_6,20,8);
}

void loop(){
  
}
