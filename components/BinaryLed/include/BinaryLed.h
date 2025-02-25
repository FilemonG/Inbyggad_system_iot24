#pragma once
#include <stdio.h>
#include <iostream>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

class BinaryLed
{
private:
public:
    gpio_num_t pinNum;
    gpio_mode_t mode; 
    uint64_t pin_bit_mask;
    gpio_pullup_t pull_up_en;
    gpio_pulldown_t pull_down_en;
    int milliseconds_on;
    int milliseconds_off;
    bool isOn;
    int updateTime;
    int curTime;
    bool state;


    BinaryLed(gpio_num_t pinNum, gpio_mode_t mode, gpio_pullup_t pull_up_en, gpio_pulldown_t pull_down_en)
    : pinNum(pinNum),
      mode(mode),
      pin_bit_mask(1ULL << pinNum),
      pull_up_en(pull_up_en),
      pull_down_en(pull_down_en),
      milliseconds_on(1000),
      milliseconds_off(1000),
      isOn(true)
    {
        gpio_config_t io_conf = {};
        io_conf.pin_bit_mask = pin_bit_mask;
        io_conf.mode = mode;
        io_conf.pull_up_en = pull_up_en;
        io_conf.pull_down_en = pull_down_en;
        io_conf.intr_type = GPIO_INTR_DISABLE;
        gpio_config(&io_conf);

        setLed(true);
        updateTime = xTaskGetTickCount();
    }

    void Led_update();
    void setLed(bool value);
    void blink(int milliseconds_on,int millisecond_off);

};




