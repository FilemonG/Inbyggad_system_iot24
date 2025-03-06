

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "nvs_flash.h"
#include "esp_log.h"

class NVSS {
private:
public:
    char serialNummer[20];
    char* devName[15];
    nvs_handle_t handle;
    esp_err_t err;
    void init();
    void getDeviceName ();
    void getSerialNumber (); 
    void setDeviceName (const char* devName);
    void setSerialNumber (const char* serialNummer);
};