#include <stdio.h>
#include <iostream>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "driver/twai.h"


using namespace std;


extern "C"
{
    void app_main(void)
    {
        twai_handle_t node_0;   //rain sensor
        twai_handle_t node_1;   //breaks

        twai_general_config_t general_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_16,GPIO_NUM_17, TWAI_MODE_NORMAL); //TX = 16 RX = 17
        twai_timing_config_t timing_config = TWAI_TIMING_CONFIG_500KBITS();
        twai_filter_config_t filter_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

        general_config.controller_id = 0;
        if(twai_driver_install_v2(&general_config, &timing_config, &filter_config, &node_0) == ESP_OK){
            printf("Driver install successful.\n");
        }
        else{
            printf("Driver not installd\n");
            return;
        }

        //start twai driver
        if (twai_start_v2(node_0) == ESP_OK){
            printf("twai start successful.\n");
        }
        else{
            printf("Driver not started.\n");
            return;
        }
        
        general_config.controller_id = 1;
        general_config.rx_io = GPIO_NUM_1;
        general_config.tx_io = GPIO_NUM_2;

        if (twai_driver_install_v2(&general_config, &timing_config, &filter_config, &node_1) == ESP_OK){
            printf("Driver 2 started succesfu.\n");
        }
        

//message to transmite 
        twai_message_t transmitt_message ={ 
            .extd = 1,
            .rtr = 0,
            .ss = 0,
            .self = 0,
            .dlc_non_comp = 1,
            .reserved = 27,
            .identifier = 0,
            .data_length_code = 0xA,
            .data = {0,1,2,3},
        };

        if (twai_transmit(&transmitt_message, pdMS_TO_TICKS(10000)) == ESP_OK){
        printf("Message ready to transmitt");
        }
    } 
};