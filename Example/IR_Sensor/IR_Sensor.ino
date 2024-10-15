#include <IR_Sensor.h>

void setup() {
    pinMode(IR_Sensor_Pin, INPUT);  
    Serial.begin(9600);  
}

void loop() {
    int distance = Detect_IRR_Distance();
    if (distance == 1) {
        Serial.println("Object detected");
    } else {
        Serial.println("No object detected");
    }
    delay(500);
}
