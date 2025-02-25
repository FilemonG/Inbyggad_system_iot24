#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

#define LED_GPIO 8  // Inbyggd LED på ESP32-C6 (kan vara GPIO 2 på vissa kort)
#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_FREQ_HZ 5000
#define LEDC_RESOLUTION LEDC_TIMER_8_BIT  // 8-bitars upplösning (0-255)

// Funktion för att uppdatera ljusstyrkan på LED
void set_led_brightness(uint8_t brightness) {
    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, brightness);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}

// Funktion för att simulera regnbågens färgförändringar på en monokrom LED
void rainbow_led_effect() {
    uint8_t brightness = 0;
    int direction = 1;

    while (1) {
        set_led_brightness(brightness);
        vTaskDelay(pdMS_TO_TICKS(20));  // Vänta 20ms för mjuk övergång

        // Öka/minska ljusstyrkan för att simulera färgförändring
        brightness += direction * 5;
        if (brightness == 255 || brightness == 0) {
            direction = -direction;
        }
    }
}

void app_main() {
    // Konfigurera LED PWM (LEDC)
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_RESOLUTION,
        .freq_hz = LEDC_FREQ_HZ,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LED_GPIO,
        .duty = 0,
        .hpoint = 0
    };
    ledc_channel_config(&ledc_channel);

    // Starta regnbågseffekten
    rainbow_led_effect();
}
