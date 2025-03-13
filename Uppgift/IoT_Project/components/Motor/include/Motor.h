#include "driver/ledc.h"
#include <iostream>
#include "esp_log.h"
#include "Button.h"

class Motor
{
private:
public:
    ledc_timer_config_t ledcTimer;
    ledc_channel_config_t ledcChannel;
    gpio_num_t pinNum1;
    gpio_num_t pinNum2;
    int pwmChannel;
    int duty;

    Motor( gpio_num_t pinNum1, gpio_num_t pinNum2, int pwmChannel): 
    pinNum1(pinNum1),pinNum2(pinNum2), pwmChannel(pwmChannel) {
        gpio_set_direction(pinNum1, GPIO_MODE_OUTPUT);
        gpio_set_direction(pinNum2, GPIO_MODE_OUTPUT);
        //setupPWM();
    };

    void setPWM();
    void setSpeed();
    void forward();
    void backward();
    void stop();
    
};


