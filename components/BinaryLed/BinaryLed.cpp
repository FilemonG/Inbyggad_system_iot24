#include "BinaryLed.h"


void BinaryLed::setLed(bool value) {
    state = true;
    gpio_set_level(pinNum, value);
}

void BinaryLed::Led_update() {
    printf("%d\n",state);
    curTime = xTaskGetTickCount();
    if (state == true)
    {
        return;
    }
    
    if(isOn){
        if (curTime - updateTime >= pdMS_TO_TICKS(milliseconds_on))
        {
            updateTime = xTaskGetTickCount();
            gpio_set_level(pinNum, 0);
            isOn = false;
        }
    }
    else
        if (curTime - updateTime >= pdMS_TO_TICKS(milliseconds_off)){
            gpio_set_level(pinNum, 1);
            updateTime = xTaskGetTickCount();
            isOn = true;
        }
   
}

void BinaryLed::blink(int milliseconds_on, int milliseconds_off) {
    state = false;
    this->milliseconds_on = milliseconds_on;
    this->milliseconds_off = milliseconds_off;
}
