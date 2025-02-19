#pragma once
#include <stdio.h>
#include <iostream>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

class BinaryLed
{
private:
    int milliseconds_on;
    int milliseconds_off;

public:
    gpio_num_t pinNum;
    gpio_mode_t mode;
    uint32_t pin_bit_mask;
    gpio_pullup_t pull_up_en;
    gpio_pulldown_t pull_down_en;

    // Corrected constructor
    BinaryLed(gpio_num_t pinNum, gpio_mode_t mode, gpio_pullup_t pull_up_en, gpio_pulldown_t pull_down_en)
        : pinNum(pinNum),
          mode(mode),
          pin_bit_mask(1ULL << pinNum),
          pull_up_en(pull_up_en),
          pull_down_en(pull_down_en),
          milliseconds_on(1000),  // Default values (adjust as needed)
          milliseconds_off(1000) {}

    void init();  // Declaration
    void Led_update();
    void setLed();
    void blink();
    
    int getMillOn() { return milliseconds_on; }
    int getMillOff() { return milliseconds_off; }
};




