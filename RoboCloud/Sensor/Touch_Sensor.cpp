#include "Touch_Sensor.h"

int Detect_Touch() {
    int stateTouch = digitalRead(Touch_Sensor_Pin); 
    if (stateTouch == 0) {  // Nếu không có chạm
        return 0;
    } else if (stateTouch == 1) {  // Nếu có chạm
        return 1;
    }
    return -1;  
}
