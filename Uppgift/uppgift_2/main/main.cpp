#include "NVSS.h"
extern "C" void app_main() {
    NVSS NVSS;
    NVSS.init();
    NVSS.setDeviceName("DevName");
    NVSS.setSerialNumber("Dev152F");

    char* myDevnName = NVSS.getDeviceName();
    if (myDevnName)
    {
        printf("Device name: %s\n",myDevnName);
    }
    char* myDevNum = NVSS.getSerialNumber();
    if (myDevNum)
    {
        printf("Device serial nummer: %s\n",myDevNum);
    }
}
