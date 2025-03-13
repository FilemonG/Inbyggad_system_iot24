#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"
#include <iostream>
#include "esp_log.h"
#include "Motor.h"
#include "Button.h"

#define ANSI_GREEN "\033[0;32m"
#define ANSI_Yellow "\033[0;33m"

#define BUTTON_FORWARD_PIN GPIO_NUM_12
#define BUTTON_BACKWARD_PIN GPIO_NUM_10

Motor myMoto = Motor(GPIO_NUM_12,GPIO_NUM_2, LEDC_CHANNEL_0);
Button buttonForward = Button(BUTTON_FORWARD_PIN, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE, 0,off,off);
Button buttonBackward = Button(BUTTON_BACKWARD_PIN, GPIO_PULLUP_ENABLE ,GPIO_PULLDOWN_DISABLE, GPIO_INTR_NEGEDGE, 0,off,off);

extern "C"
{
    void app_main(void)
    {
       
       myMoto.backward();
    }
}