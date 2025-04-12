
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
#include "nvs_flash.h"
#include "esp_log.h"

class NVSS {
private:
public:
    char* devName[15];
    char* serialNummer[20];
    nvs_handle_t handle;
    esp_err_t err;
    int nummer;
    int init();
    void setDeviceName (const char* new_devName);
    void setSerialNumber (const char* new_serialNummer);
    char* getDeviceName () const;
    char* getSerialNumber() const; 
    
};