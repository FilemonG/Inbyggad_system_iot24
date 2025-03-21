#include "AnalogLed.h"

AnalogLed::AnalogLed(int gpio_num, uint32_t freq, ledc_timer_bit_t resolution) {
    
        ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .duty_resolution  = resolution,
        .timer_num        = LEDC_TIMER_0,
        .freq_hz          = freq,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);
    ledc_channel = {
        .gpio_num       = gpio_num,
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel        = LEDC_CHANNEL_0,
        .intr_type      = LEDC_INTR_DISABLE,
        .timer_sel      = LEDC_TIMER_0,
        .duty           = 0,
       
    };
    ledc_channel_config(&ledc_channel);
    sinusOff = true;
    sinPeriod = 1000; 
    updateTime = 0;
}


void AnalogLed::setLedAnalog(int newDuty) {
    sinusOff = true;
    sinDuty = newDuty;
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, (int)sinDuty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
}

void AnalogLed::updateAnalog() {
    curTime = xTaskGetTickCount();
    
    if (!sinusOff) { 
        if (curTime - updateTime >= pdMS_TO_TICKS(10)) { 
            float timeRatio = fmod((float)curTime / pdMS_TO_TICKS(sinPeriod), 1.0f); 
            sinDuty = (sin(2 * M_PI * timeRatio) + 1) * 127.5f;

            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, (int)sinDuty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

            printf("Duty: %d timeRatio: %f\n", (int)sinDuty, timeRatio);

            updateTime = curTime;
           }
        }
}
void AnalogLed::sinAnalog(int period){
    sinusOff = false;
    sinPeriod = period;
}
