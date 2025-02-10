#include <stdlib.h>
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "esp_task_wdt.h"

#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define IDEL_CORE_0_BIT 0b01
#define IDLE_CORE_1_BIT 0b10
#define WATCHDOG_TIMEOUT 3000
#define BUTT_PIN GPIO_NUM_20
#define WATCHDOG_TRIGER_PANIC true

void app_main(void)
{
    //bool pressed = false;
    gpio_config_t pinKonfig = {
    .mode = GPIO_MODE_INPUT,
    .pin_bit_mask = 1ULL << BUTT_PIN,
    .pull_down_en = GPIO_PULLDOWN_DISABLE,
    .pull_up_en = GPIO_PULLUP_ENABLE,
    .intr_type= GPIO_INTR_NEGEDGE,
    
    };
    esp_err_t error = gpio_config(&pinKonfig);
    
    esp_task_wdt_config_t watchDog = {
        .idle_core_mask = IDEL_CORE_0_BIT | IDLE_CORE_1_BIT,
        .timeout_ms = WATCHDOG_TIMEOUT,
        .trigger_panic = WATCHDOG_TRIGER_PANIC,
    };
    
    esp_task_wdt_add(NULL);

    while (1)
    {
       
       int level = gpio_get_level(BUTT_PIN);
       if (level == 1)
       {
        printf(ANSI_GREEN"ON: %d\n",level);
        esp_task_wdt_reset();
       }
       vTaskDelay(pdMS_TO_TICKS(10));
    }
    esp_task_wdt_delete(NULL);
}