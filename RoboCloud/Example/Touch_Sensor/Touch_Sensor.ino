#include <Touch_Sensor.h>

void setup() {
    pinMode(Touch_Sensor_Pin, INPUT);  // Thiết lập chân cảm biến là INPUT
    Serial.begin(9600);  // Khởi tạo Serial để xem kết quả
}

void loop() {
    int touchStatus = Detect_Touch();
    if (touchStatus == 1) {
        Serial.println("Touch detected");
    } else if (touchStatus == 0) {
        Serial.println("No touch detected");
    } else {
        Serial.println("Unknown state");
    }
    delay(500);
}
