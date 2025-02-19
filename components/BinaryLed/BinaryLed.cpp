#include "BinaryLed.h"
#include "driver/gpio.h"

// Define the init function
void BinaryLed::init() {
    gpio_config_t io_conf = {};
    io_conf.pin_bit_mask = pin_bit_mask;
    io_conf.mode = mode;
    io_conf.pull_up_en = pull_up_en;
    io_conf.pull_down_en = pull_down_en;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    
    gpio_config(&io_conf);
}

// Define other member functions (if needed)
void BinaryLed::setLed() {
    gpio_set_level(pinNum, 1);  // Turn LED on
}

void BinaryLed::Led_update() {
    gpio_set_level(pinNum, 0);  // Turn LED off
}

void BinaryLed::blink() {
    setLed();
    vTaskDelay(milliseconds_on / portTICK_PERIOD_MS);
    Led_update();
    vTaskDelay(milliseconds_off / portTICK_PERIOD_MS);
}
