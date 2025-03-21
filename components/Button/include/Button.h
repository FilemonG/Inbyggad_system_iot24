#pragma once
#include <stdio.h>
#include <iostream>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

typedef enum {
    off,  // buttonstate = 0
    de_off, 
    on,
    de_on
}buttonState;

class Button{
    public:
    void (*onPressedCallback)(int); // = nullptr;
    public:
        gpio_num_t pinNum;
        gpio_mode_t mode;
        uint32_t pin_bit_mask;
        gpio_pullup_t pull_up_en;
        gpio_pulldown_t pull_down_en;
        gpio_int_type_t intr_type;
        TickType_t elapsetime;
        buttonState curr_state;
        buttonState next_state;
        int level = 0;
        
    Button(gpio_num_t pin, gpio_pullup_t pull_up_en, gpio_pulldown_t pull_down_en,
        gpio_int_type_t intr_type, TickType_t elaspetime, buttonState curr_state,buttonState next_state) :

        pinNum(pin),pin_bit_mask(1ULL << pin), pull_up_en(pull_up_en), pull_down_en(pull_down_en),
        intr_type(intr_type), elapsetime(elaspetime),curr_state(curr_state),next_state(next_state){ mode = GPIO_MODE_INPUT;}

    void init();
    void button_uppdate();
    bool isPressed(void);
    void setOnPressed(void(*onPressed)(int pin));
    void pressState(int x){}
};