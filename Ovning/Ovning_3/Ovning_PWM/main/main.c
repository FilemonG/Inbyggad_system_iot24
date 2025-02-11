#include "driver/gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"

#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"t


void app_main(void)
{
    gpio_config_t ButtKonfig;
    ButtKonfig.mode = GPIO_MODE_INPUT;
    ButtKonfig.pin_bit_mask = 1ULL << GPIO_NUM_18;
    ButtKonfig.pull_down_en = GPIO_PULLDOWN_DISABLE;
    ButtKonfig.pull_up_en = GPIO_PULLUP_ENABLE;
    ButtKonfig.intr_type= GPIO_INTR_DISABLE;
    esp_err_t error = gpio_config(&ButtKonfig);

    ledc_timer_config_t ledcConf;
    ledcConf.clk_cfg = LEDC_AUTO_CLK;
    ledcConf.deconfigure = false;
    ledcConf.duty_resolution = LEDC_TIMER_12_BIT;
    ledcConf.speed_mode = LEDC_LOW_SPEED_MODE;
    ledcConf.freq_hz = (1000);
    ledcConf.timer_num = LEDC_TIMER_0;
    ledc_timer_config(&ledcConf);

    ledc_channel_config_t channelConf;

    int level = gpio_get_level(GPIO_NUM_18);

    TickType_t startTik = xTaskGetTickCount();
    int latch = 0;
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(25));
        level = gpio_get_level(GPIO_NUM_18);
        if (level == 1 && latch == 0)
        {
            TickType_t tikDeff = xTaskGetTickCount() - startTik;
            if (tikDeff >= pdMS_TO_TICKS(30))
            {
                startTik = xTaskGetTickCount();
                latch = 1;
                printf(ANSI_GREEN"On: %d\n",level);
            }
        }
        else if (level == 0 && latch == 1)
        {
             TickType_t tikDeff = xTaskGetTickCount() - startTik;
            if (tikDeff >= pdMS_TO_TICKS(30))
            {
                latch = 0;
                printf(ANSI_RED"Off: %d\n",level);
            }
        }
        
    }
    
}