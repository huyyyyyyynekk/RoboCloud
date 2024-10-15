#include <Servo_Control.h>

void setup() {
    Attach_Servos();  
}

void loop() {
    Action_Servo("Smile");  
    delay(2000);
}
