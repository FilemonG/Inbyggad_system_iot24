#include <stdio.h>
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "Button.h"
#include <iostream>
#include <string>
void pressState(int x){
    
}
extern "C"
{
    void app_main(void)
    {
        Button buttom_1;
        gpio_config_t pin;
        bool pressed;
        buttom_1.init();
        buttom_1.button_uppdate();
        buttom_1.isPressed();
        buttom_1.setOnPressed(pressState);
    }
}