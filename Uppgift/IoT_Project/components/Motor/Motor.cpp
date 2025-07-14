#include "Motor.h"


void Motor::setPWM(){
        ledc_timer_config_t timerConf = {
            .speed_mode = LEDC_LOW_SPEED_MODE, 
            .duty_resolution = LEDC_TIMER_8_BIT,
            .timer_num = LEDC_TIMER_0,
            .freq_hz = 1000,
            .clk_cfg = LEDC_AUTO_CLK,
            .deconfigure = false
        };
        ledc_timer_config(&timerConf);

        ledc_channel_config_t channelConfig = {
            .gpio_num = 0,
            .speed_mode = LEDC_LOW_SPEED_MODE,
            .channel = LEDC_CHANNEL_0,
            .timer_sel = LEDC_TIMER_0,
            .duty = 255,
            .hpoint = 0
        };
        ledc_channel_config (&channelConfig);
}

void Motor::setSpeed(int duty){
    duty1 = duty;
    ledc_set_duty(LEDC_LOW_SPEED_MODE, pwmChannel, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, pwmChannel);
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
