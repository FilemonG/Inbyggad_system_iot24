#include <stdio.h>
#include "freertos/FreeRTOS.h"
//#include "driver/ledc.h"
#include <iostream>
#include "esp_log.h"

class UltraSonic
{
private:
    int distans;
    int pinNr;
public:
    // UltraSonic(int pin):{}
    // gpio_config_t pinConf;
    void update(void);
};
