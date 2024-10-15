#include "IR_Sensor.h"

int Detect_IRR_Object() {
    return digitalRead(IR_Sensor_Pin); 
}

int Detect_IRR_Distance() {
    if (Detect_IRR_Object() == 0) {  // Vật thể được phát hiện
        return 1;
    } else {                    //  Không có vật thể
        return 0;
    }
}
