#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "Button.h"
#include <iostream>

//#define BIT_MASK 1UU << pinNum

void pressState(int x){
}
extern "C"
{
    void app_main(void)
    {
        Button myButton = Button(GPIO_NUM_12, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE, 0,off,off,false);
        myButton.init();   //funktioner.  deklarera först sen definerar
        myButton.button_uppdate();
        myButton.isPressed();
        myButton.setOnPressed(pressState);
        
        while (1)
            {
                myButton.button_uppdate();
                vTaskDelay(pdMS_TO_TICKS(200));
            }
    }
}