#include <stdio.h>
#include "UltraSensor.h"

void UltraSensor::init(void)
{
    gpio_config_t trigPin_conf = {
        .pin_bit_mask = (1ULL << trig_pin),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&trigPin_conf);

    gpio_config_t echoPin_conf = {
        .pin_bit_mask = (1ULL << echo_pin),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&echoPin_conf);
}

int UltraSensor::UltraSonic_measure(void){
    gpio_set_level(trig_pin, 0);
    vTaskDelay(pdMS_TO_TICKS(2));
    gpio_set_level(trig_pin, 1);
    vTaskDelay(pdMS_TO_TICKS(2));
    gpio_set_level(trig_pin, 0);
    
    int64_t startTime = 0;
    while (gpio_get_level(echo_pin) == 0)
    {
        startTime = esp_timer_get_time();
        vTaskDelay(pdMS_TO_TICKS(2));
    }
    int64_t stopTime = 0;
    while (gpio_get_level(echo_pin) == 1)
    {
        stopTime = esp_timer_get_time();
        vTaskDelay(pdMS_TO_TICKS(2));
    }

    int64_t pulse = stopTime - startTime;
    float distance_cm = (pulse * 0.0343) /2.0;
    return distance_cm;
}