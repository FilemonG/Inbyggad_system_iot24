#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
//#include "Button.h"
#include "Potentiometer.h"
#include <iostream>

#define ANSI_GREEN "\033[0;32m"
#define ANSI_RED "\033[0;31m"
#define ANSI_Yellow "\033[0;33m"

void thresholeState(int pin, int value){

}

//void pressState(int x){
   // ESP_LOGI("BUTTON", "Button pressed on GPIO %d", x); }

extern "C"
{
    void app_main(void)
    {
        Potentiometer myPoten = Potentiometer (2,0,false, ADC_ATTEN_DB_12,ADC_WIDTH_BIT_12);
        while (1)
        {
            myPoten.update();
            myPoten.getfunk()(myPoten.getPin(), myPoten.getData());
            if (myPoten.getValue() < 100)
            {
                printf(ANSI_RED"Low value: %d\n",myPoten.getValue());
                vTaskDelay(pdMS_TO_TICKS(80));
            }
            if (myPoten.getValue() >= 1000)
            {
                printf(ANSI_GREEN"Value: %d\n",myPoten.getValue());
                vTaskDelay(pdMS_TO_TICKS(80));
            }
        }
    }
}
/*
 {
        Button myButton = Button(GPIO_NUM_12, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE, 0,off,off);
        myButton.init();   //funktioner.  deklarera först sen definerar
        myButton.button_uppdate();
        myButton.isPressed();
        myButton.setOnPressed(pressState);
        while (1)
            {
                if (myButton.isPressed())
                {
                    printf(ANSI_GREEN"Button is pressed\n");
                }
                if (!myButton.isPressed())
                {
                    printf(ANSI_RED"Button is not pressed\n");
                }
                
                
                myButton.button_uppdate();
                vTaskDelay(pdMS_TO_TICKS(50));
            }
    }*/