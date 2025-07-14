#pragma once
#include <stdio.h>
#include <iostream>
#include "esp_log.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "esp_timer.h"



class UltraSensor
{
public:
    gpio_num_t trig_pin;
    gpio_num_t echo_pin;
    UltraSensor(gpio_num_t pin1, gpio_num_t pin2) : trig_pin(pin1), echo_pin(pin2) {}
    
    void init(void); 
    int UltraSonic_measure();
};
