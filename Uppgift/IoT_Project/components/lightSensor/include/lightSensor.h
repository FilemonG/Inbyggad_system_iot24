
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"
#include <iostream>

class LightSensor {
private:
public:
    gpio_num_t sensorPin;
    LightSensor(gpio_num_t Pin):
    sensorPin(Pin){}
    void init();                           
    int readLightLevel();               
};
