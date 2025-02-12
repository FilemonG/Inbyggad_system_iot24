#pragma once
#include <stdio.h>
#include <iostream>
#include "driver/gpio.h"

class Button{
    private:
    public:
        int pinNum;
        gpio_mode_t mode;
        gpio_pullup_t pull_up_en;
        gpio_pulldown_t pull_down_en;
        gpio_int_type_t intr_type;

    Button(int pin, gpio_pullup_t pull_up_en, gpio_pulldown_t pull_down_en, gpio_int_type_t intr_type) :
        pinNum(pin), pull_up_en(pull_up_en), pull_down_en(pull_down_en), intr_type(intr_type){ mode = GPIO_MODE_INPUT;}

    void init();
    void button_uppdate(void);
    bool isPressed(void);
    void setOnPressed(void(*onPressed)(int pin));
};
