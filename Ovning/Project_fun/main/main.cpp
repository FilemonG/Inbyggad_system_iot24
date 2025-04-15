// ny projeckt
#include <stdio.h>
#include <iostream>
#include "NVSS.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

extern "C"
{
    void app_main(void)
    {
        NVSS myNvss;
        myNvss.init();
        myNvss.setDeviceName ("Esp32c6\n");
        myNvss.setSerialNumber("TESTESP32\n");
        myNvss.getDeviceName ();
        myNvss.getSerialNumber(); 
    }
}