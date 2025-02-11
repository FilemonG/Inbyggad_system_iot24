#include <stdio.h>
#include <iostream>
#include <string>
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "Button.h"


Button::Button(gpio_config_t pin,bool pressed){
    
}
void Button::init()
{
   
}
void Button::button_uppdate(){
    
}
bool Button::isPressed(){
    printf("Nu kör pressed\n");
    return false;
}
void Button::setOnPressed(void(*onPressed)(int pin)){

}
