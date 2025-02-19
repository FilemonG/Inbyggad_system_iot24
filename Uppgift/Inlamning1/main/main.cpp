#include "esp_err.h"
//#include "freertos/FreeRTOS.h"
#include "esp_log.h"
//include "Button.h"
#include "Potentiometer.h"
//#include "BinaryLed.h"

#define ANSI_GREEN "\033[0;32m"
#define ANSI_RED "\033[0;31m"
#define ANSI_Yellow "\033[0;33m"

void thresholeState(int pin, int value){printf("HEEfffEEJ.\n");} // ska kallas när getValue == 1000;
//void pressState(int x){ ESP_LOGI("BUTTON", "Button pressed on GPIO %d", x); } // ska kallas när knappen är tryckt


extern "C" 
{
    void app_main(void) 
    {
        Potentiometer myPoten = Potentiometer (2,1000,false, ADC_ATTEN_DB_12,ADC_WIDTH_BIT_12);
        myPoten.setOnThreshold(1000, false, thresholeState, 10);
        myPoten.doCallBack(myPoten.getPin(),myPoten.getData());
        while (1)
        {
            myPoten.update();
            printf("Your Value: %d \n",myPoten.getValue());   
            vTaskDelay(pdMS_TO_TICKS(150));
        
        }
    }   
}


/*_____________________________________Buttom__________________________________________
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

   //_________________________________ Potensiometer_____________________________
   /*
        Potentiometer myPoten = Potentiometer (2,1000,false, ADC_ATTEN_DB_12,ADC_WIDTH_BIT_12);
        myPoten.setOnThreshold(1000, true, thresholeState, 10);
        myPoten.doCallBack(myPoten.getPin(),myPoten.getData());
        while (1)
        {
            myPoten.update();
            printf("Your Value: %d \n",myPoten.getValue());   
            vTaskDelay(pdMS_TO_TICKS(150));
        
        }
    

    _______________________________________Binary Led______________________________________
    // Use GPIO_MODE_OUTPUT instead of GPIO_MODE_INPUT
        BinaryLed myLed = BinaryLed (GPIO_NUM_12, GPIO_MODE_OUTPUT, GPIO_PULLUP_ENABLE, GPIO_PULLDOWN_DISABLE);

        myLed.init();
        myLed.Led_update();
        myLed.setLed();

        while (true) {
            myLed.blink();  // This already has delay
        }
   */