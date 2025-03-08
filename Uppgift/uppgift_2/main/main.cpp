
#include "NVSS.h"

extern "C"
{
    void app_main(void)
    {
        NVSS myNvs;
        myNvs.init();
        
        myNvs.setDeviceName("Radio");
        myNvs.setSerialNumber("Fil573");

        char* deviceName = myNvs.getDeviceName ();
        if (deviceName)
        {
            printf("Device name: %s\n",deviceName);
            free(deviceName);
        }
        else
        {
            printf("No device name found...\n");
        }
        myNvs.getSerialNumber();
    }
}