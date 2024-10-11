#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#include "RoboCloud.h"
#include <HardwareSerial.h>
#include <WiFi.h>

bool run_servo = false;
bool run_TFT = false;
bool stop_servo = false;
bool stop_TFT = false;
bool data_send = false;
bool isconnected = false;
int TFT_count = 0;
int Servo_count = 0;
String ssid = "";
String password = "";
String Emotion = "";
String Link_Audio = "";

void Task_Servo (void *pvParameters);
void Task_TFT (void *pvParameters);
//void Task_USART (void *pvParameters);
/*
void Data_Receive(){
  int Hyphen_Pos_1 = -1;
  int Dot_Pos_1 = -1;
  int Hyphen_Pos_2 = -1;
  int Dot_Pos_2 = -1;
  int count_1 = 0;
  int count_2 = 0;
  int count_3 = 0;
  int count_4 = 0;
  
   if (SerialPort.available() && isconnected == false) {
    String receive_data_1 = SerialPort.readStringUntil('\n');
    receive_data_1.trim();
    Serial.println(receive_data_1);
    Serial.println(receive_data_1.length());
    //delay(1000);
    
    String receive_data_2 = SerialPort.readStringUntil('\n');
    receive_data_2.trim();
    Serial.println(receive_data_2);
    Serial.println(receive_data_2.length());
    //delay(1000);
    
    for (int i = 0; i < receive_data_1.length() - 1; i++) { 
      char c = receive_data_1.charAt(i);
      char d = receive_data_1.charAt(i + 1);

      if (c == '1' && d == '.' && count_1 == 0) {
        count_1++; 
        Dot_Pos_1 = i + 1;  
        Serial.println("Vị trí dấu chấm: " + String(Dot_Pos_1));  
      }
      else if (d == '-' && count_2 == 0){
        count_2++;
        Hyphen_Pos_1 = i + 1;
        Serial.println("Vị trí dấu gach ngang: " + String(Hyphen_Pos_1));
      }
    }

    for (int i = 0; i < receive_data_2.length() - 1; i++) { 
      char a = receive_data_2.charAt(i);
      char b = receive_data_2.charAt(i + 1);

      if (a == '2' && b == '.' && count_3 == 0) {
        count_3++; 
        Dot_Pos_2 = i + 1;  
        Serial.println("Vị trí dấu chấm: " + String(Dot_Pos_2));  
      }
      else if (b == '-' && count_4 == 0){
        count_4++;
        Hyphen_Pos_2 = i + 1;
        Serial.println("Vị trí dấu gach ngang: " + String(Hyphen_Pos_2));
      }
    }
    
    if (Hyphen_Pos_1 != -1 && Dot_Pos_1 != -1) {
     
      ssid = receive_data_1.substring(Dot_Pos_1 + 1, Hyphen_Pos_1);
      password = receive_data_1.substring(Hyphen_Pos_1 + 1);

      Serial.println("SSID nhận được: " + ssid);
      Serial.println("Mật khẩu nhận được: " + password);

      WiFi.begin(ssid.c_str(), password.c_str());
      
      unsigned long startAttemptTime = millis();
      while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 30000) { // Timeout sau 30 giây
        delay(1000);
        Serial.println("Đang kết nối...");
      }

      if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Kết nối thành công!");
        isconnected = true;
      } else {
        Serial.println("Không thể kết nối sau 30 giây");
      }
    } else {
      Serial.println("Không tìm thấy SSID hoặc mật khẩu hợp lệ");
    }
    
    if (Hyphen_Pos_2 != -1 && Dot_Pos_2 != -1){
      Emotion = receive_data_2.substring(Dot_Pos_2 + 1,Hyphen_Pos_2);
      Link_Audio = receive_data_2.substring(Hyphen_Pos_2 + 1);
      Serial.println("Biểu cảm là:" + Emotion);
      Serial.println("Link là:" +Link_Audio);
    }
  }
}
*/

void setup() {
  Serial.begin(115200);
  //SerialPort.begin(9600, SERIAL_8N1, 16, 17);
  Attach_Servos();
  setup_Display();
  
  xTaskCreatePinnedToCore(
    Task_Servo,
    "Task_Servo",
    2048,
    NULL,
    1,
    NULL,
    ARDUINO_RUNNING_CORE
  );

  xTaskCreatePinnedToCore(
    Task_TFT,
    "Task_TFT",
    2048,
    NULL,
    1,
    NULL,
    ARDUINO_RUNNING_CORE
  );
  /*
  xTaskCreatePinnedToCore(
    Task_USART,
    "Task_USART",
    2048,
    NULL,
    2,
    NULL,
    ARDUINO_RUNNING_CORE
  );
  */
}

void loop() {
  
}

void Task_Servo(void *pvParameters) {
  (void) pvParameters;
  while(1) {
    if (run_servo == false && Servo_count < 3) {
      Action_Servo("Smile");
      Servo_count++;
      //run_servo = false;
    }
    vTaskDelay(3);  
  }
}

void Task_TFT(void *pvParameters) {
  (void) pvParameters;
  while(1) {
    if (run_TFT == false && TFT_count < 4) {
      TFT_count++;
      Print_Emotion("Smile");
      //run_TFT = false; 
    }
    vTaskDelay(1);  
  }
}
/*
void Task_USART(void* pvParameters) {
  (void) pvParameters;
  while (1) {
    Data_Receive();
    if (isconnected == true){
    String back = "Success-1";
    SerialPort.println(back);
    Serial.println("Kết nối thành công!");
    Serial.print("Địa chỉ IP: ");
    Serial.println(WiFi.localIP());
    isconnected = false;
    //data_send = true;
    }
    if (Emotion == "Smile" && data_send == false){
      run_TFT = true;
      run_servo = true;
      SerialPort.println("Success-2");
      data_send = true;
    }
    if (Link_Audio == "https://huyhahahaahahah.com" && data_send == false){
      //data_send = true;
    }
    vTaskDelay(3);  
  }
}
*/
