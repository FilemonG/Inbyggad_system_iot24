#include <stdio.h>
#include "esp_log.h"
const static char *TAG = "MAIN";
void app_main(void)
{
    ESP_LOGI(TAG, "Hello world for my %d time!",100);
}