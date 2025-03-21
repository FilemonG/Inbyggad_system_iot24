#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"
#include <iostream>
#include "esp_log.h"
#include "Motor.h"
#include "Button.h"
//#include "Potentiometer.h"
#include "lightSensor.h"

#define ANSI_GREEN "\033[0;32m"
#define ANSI_Yellow "\033[0;33m"

#define BUTTON_FORWARD_PIN GPIO_NUM_4
#define BUTTON_BACKWARD_PIN GPIO_NUM_5

LightSensor myLsensor = LightSensor(GPIO_NUM_1);
Motor myMotor = Motor(GPIO_NUM_4,GPIO_NUM_5, LEDC_CHANNEL_0);
Button buttonForward = Button(GPIO_NUM_10, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE, 0,off,off);
Button buttonBackward = Button(GPIO_NUM_12, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE, 0,off,off);
Button buttonStop = Button(GPIO_NUM_13, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE, 0,off,off);

void setForward(int pin){
    printf("Motor Framåt\n");
    myMotor.forward();
}
void setBackward(int pin){
    printf("Motor Backåt\n");
    myMotor.backward();
}
void motorStop(int pin){
    printf("Motor stop.\n");
    myMotor.stop();
}
extern "C"
{
    void app_main(void)
    { 
        myMotor.setPWM();
        myMotor.setSpeed(250);
        myMotor.forward();
        myMotor.backward();
        myMotor.stop();

        buttonForward.init();   //funktioner.  deklarera först sen definerar
        buttonForward.button_uppdate();
        buttonForward.isPressed();
        buttonForward.setOnPressed(setForward);

        buttonBackward.init();   //funktioner.  deklarera först sen definerar
        buttonBackward.button_uppdate();
        buttonBackward.isPressed();
        buttonBackward.setOnPressed(setBackward);

        buttonStop.init();
        buttonStop.button_uppdate();
        buttonStop.isPressed();
        buttonStop.setOnPressed(motorStop);

        myLsensor.init();

        while (1)
            {
                int lightLevel = myLsensor.readLightLevel();
                printf("Ljusnivå: %d\n", lightLevel);
                vTaskDelay(pdMS_TO_TICKS(150));
                if (lightLevel >= 300)
                {
                    buttonForward.button_uppdate();              
                    vTaskDelay(pdMS_TO_TICKS(50));
                    buttonBackward.button_uppdate();
                    vTaskDelay(pdMS_TO_TICKS(50));
                    buttonStop.button_uppdate();
                    vTaskDelay(pdMS_TO_TICKS(50));
                    
                }
                buttonStop.button_uppdate();
                vTaskDelay(pdMS_TO_TICKS(50));
            }
        
        //buttonBackward.setOnPressed(setBackward);
    }   
}