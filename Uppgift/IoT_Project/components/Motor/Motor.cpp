#include <stdio.h>
#include "Motor.h"



void Motor::setPWM(){
    ledc_timer_config_t ledcTimer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_8_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 4000,
        .clk_cfg = LEDC_AUTO_CLK
    };
     ledc_timer_config(&ledcTimer);

        ledc_channel_config_t channelConfig = {
            .gpio_num = 12,
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .channel = LEDC_CHANNEL_0,
            .timer_sel = LEDC_TIMER_0,
            .duty = 400,
            .hpoint = 0
        };
        ledc_channel_config (&channelConfig);
}

void Motor::setSpeed(void){
    
}
void Motor::forward(){
    gpio_set_level(pinNum1, 1);
    gpio_set_level(pinNum2, 0);

}
void Motor::backward(void){
    gpio_set_level(pinNum1, 0);
    gpio_set_level(pinNum2, 1);
    
}
void Motor::stop(){
    gpio_set_level(pinNum1, 0);
    gpio_set_level(pinNum2, 0);
    
}
