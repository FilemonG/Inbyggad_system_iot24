#include <stdio.h>
#include <iostream>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "driver/twai.h"
#include "esp_mac.h"

using namespace std;


extern "C"
{
    void app_main(void)
    {
        twai_handle_t node_1;   //rain sensor
        twai_handle_t node_2;   //breaks
        twai_general_config_t general_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_16,GPIO_NUM_17, TWAI_MODE_NORMAL); //TX = 16 RX = 17
        twai_timing_config_t timing_config = TWAI_TIMING_CONFIG_500KBITS();
        twai_filter_config_t filter_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

        if(twai_driver_install(&general_config, &timing_config, &filter_config) == ESP_OK){
            printf("Driver install successful.\n");
        }
        else
            printf("Driver not installd\n");

        //start twai driver
        if (twai_start() == ESP_OK){
            printf("twai start successful.\n");
        }
        else
            printf("Driver not started.\n");
    }
    twai_message_t incomming_message ={
        .extd = 1,
        .rtr = 0,
        .ss = 0,
        .self = 0,
        .identifier = 0,
        .data_length_code = 0xA,
        .data = {0,1,2,3}
    };
};