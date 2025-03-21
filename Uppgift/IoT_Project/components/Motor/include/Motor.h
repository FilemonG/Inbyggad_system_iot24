#include "freertos/FreeRTOS.h"
#include "driver/ledc.h"
#include <iostream>
#include "esp_log.h"

class Motor
{
private:
public:
    
    gpio_num_t pinNum1;
    gpio_num_t pinNum2;
    ledc_channel_t pwmChannel;
    int duty;

    Motor( gpio_num_t pin1, gpio_num_t pin2, ledc_channel_t Channel){
    pinNum1 = pin1;
    pinNum2 = pin2;
    pwmChannel = Channel;
     gpio_config_t pinConf = {
        .pin_bit_mask =  (1ULL << pinNum1) | (1ULL << pinNum2),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&pinConf);
   
    }
        // gpio_set_direction(pinNum1, GPIO_MODE_OUTPUT);
        // gpio_set_direction(pinNum2, GPIO_MODE_OUTPUT);
        
    void setPWM();
    void setSpeed(int duty);
    void forward();
    void backward();
    void stop();
    
};


