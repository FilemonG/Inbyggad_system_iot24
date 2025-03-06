
#include "NVSS.h"

extern "C"
{
    void app_main(void)
    {
        NVSS myNvs;
        myNvs.init();
        myNvs.getDeviceName (); 
        myNvs.getDeviceName();
        myNvs.setDeviceName();
        myNvs.setSerialNumber();
    }
}