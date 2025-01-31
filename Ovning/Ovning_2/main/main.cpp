#include <stdio.h>
#include "printer.h"
#include "Helper_Comp.h"
#include "esp_log.h"

extern "C" 
{
    void app_main(void)
    {
        int a = Ovning_2::func();
        ESP_LOGI("MAIN", " returned %d", a);
       inbyggda_IoT24::printNumbers(0, 10);
    }
   
}
//app_main(void);

