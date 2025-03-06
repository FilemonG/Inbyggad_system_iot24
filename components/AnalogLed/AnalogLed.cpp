#include "AnalogLed.h"

AnalogLed::AnalogLed(int gpio_num, uint32_t freq, ledc_timer_bit_t resolution) {
    
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .duty_resolution  = resolution,
        .timer_num        = LEDC_TIMER_0,
        .freq_hz          = freq,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    
    ledc_channel_config_t ledc_channel = {
        .gpio_num       = gpio_num,
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel        = LEDC_CHANNEL_0,
        .intr_type      = LEDC_INTR_DISABLE,
        .timer_sel      = LEDC_TIMER_0,
        .duty           = 0,
       
    };
    ledc_channel_config(&ledc_channel);
}


void AnalogLed::setLedAnalog() {
    sinusOff = true;
}

void AnalogLed::updateAnalog() {
    if (sinusOff) {
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, sinDuty);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
    } else {
        for (int i = 0; i < sinPeriod; i++) {
            sinDuty = ((sin(i * (2*M_PI) / sinPeriod) + 1) / 2 ) * 256;
            ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, sinDuty);
            ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
            vTaskDelay(pdMS_TO_TICKS(80));
            printf("Duty: %d\n",sinDuty);
        }
    }
}

void AnalogLed::sinAnalog(int period) {
    sinusOff = false;
    sinPeriod = period;
}
