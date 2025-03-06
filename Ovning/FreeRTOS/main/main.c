#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"

const char *TAG = "MAIN";
TaskHandle_t task_1_handle;

void task_1_funk(void *arg);
void app_main(void)
{  
    
    int arg = 0;
   if (xTaskCreate(task_1_funk,"task1",3000, &arg, 1, &task_1_handle) != pdPASS){

   }
}
void task_1_funk(void *arg){
    vTaskDelete(NULL);
    
}