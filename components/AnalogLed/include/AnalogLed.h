#pragma once

#include <stdio.h>
#include <math.h>
#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"
#include <iostream>
#include "esp_log.h"

class AnalogLed {
private:
public:
    ledc_timer_config_t ledc_timer;
    ledc_channel_config_t ledc_channel;
    uint32_t duty;
    int sinDuty;
    bool sinusOff;
    int sinPeriod;
    uint32_t updateTime;
    uint32_t curTime;
    //float timeRatio;
    AnalogLed(int gpio_num, uint32_t freq, ledc_timer_bit_t resolution);
    
    void setLedAnalog(int sinDuty);        
    void updateAnalog();        
    void sinAnalog(int sinPeriod);         
};

