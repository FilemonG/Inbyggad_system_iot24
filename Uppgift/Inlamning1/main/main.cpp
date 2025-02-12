//#include <stdio.h>
//#include "driver/gpio.h"
//#include "driver/ledc.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "Button.h"
#include <iostream>

void pressState(int x){
    
}
extern "C"
{
    void app_main(void)
    {
        Button myButton = Button(3, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE);
        myButton.init();   //funktioner.  deklarera först sen definerar
        myButton.button_uppdate();
        myButton.isPressed();
        myButton.setOnPressed(pressState);

    
    }
}