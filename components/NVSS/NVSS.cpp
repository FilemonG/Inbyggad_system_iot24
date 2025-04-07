#include "NVSS.h"
#include <cstring>
//#include "nvs_flash/include/nvs_flash.h"

#define DEVICENAME "DeviceName"

int NVSS::init(){
    err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) // om err inte får platts eller nya version känner int igen err
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    err = nvs_open("Test_namespace", NVS_READWRITE, &handle); // "Test_namespace" namnet på minnesutrymmet jag öppar 
    if (err != ESP_OK)
    {
        printf("Failed to open namespace");
        return;
    }
    if (err == ESP_OK)
    {
         printf("Lyckades to open namespace.\n");
    }

    size_t* required_size;
    err = nvs_get_str(handle, DEVICENAME, NULL, &required_size);
    if (err != ESP_OK)
    {
        printf("Fel vi läsning av minnetn.\n");
        return NULL; 
    }
    //finns flera möjliga fel
    if (required_size <= 0 && required_size > 15)
    {
        printf("Fel storlek\n");
        return NULL;
    }
    
    char* device_name =(char*) malloc(sizeof(char)*required_size);
    err = nvs_get_str(handle, DEVICENAME, device_name, &required_size);
    if (err != ESP_OK)
    {
        printf("Fel vid läsning sträing av NVS.\n");
        free(device_name);
        return NULL;
    }
    //devName = device_name;
    strcpy(devName, device_name)
    devName[14] = "\0";

}

void NVSS::setDeviceName(const char* new_devName) {
    err = nvs_set_str(handle, DEVICENAME, new_devName);
    if (err != ESP_OK) {
        printf("Fel vid skrivning av device name\n");
        return;
    }
    nvs_commit(handle);
}


void NVSS::setSerialNumber (const char* new_serialNummer){
    err = nvs_set_str(handle, "SeriealNumber", new_serialNummer);
    if (err != ESP_OK)
    {
        printf("Fel vid skrivning av device nummer.\n");
    }
    nvs_commit(handle);
}
void NVSS::getDeviceName (){
    return devName;
}
char* NVSS::getSerialNumber (){
    return serialNummer;
}