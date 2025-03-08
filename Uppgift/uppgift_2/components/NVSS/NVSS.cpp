#include "NVSS.h"
//#include "nvs_flash/include/nvs_flash.h"



void NVSS::init(){
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
    int32_t counter = 0;
    err = nvs_get_i32(handle, "counter", &counter);
    if (err != ESP_OK)
    {
        counter = 0;
        printf("Didnt find counter \n");
    }
     else
    {
        counter += 1;
    }

    err = nvs_set_i32(handle,"counter", counter);
    if (err != ESP_OK)
    {
        printf("Failed to write counter to nvs");
    }

    err = nvs_commit(handle);

    if (err != ESP_OK)
    {
        printf("Failed to commit to nvs");
    }

    nvs_close(handle);

    printf("Counter: %ld", counter);

}

void NVSS::setDeviceName(const char* devName) {
    err = nvs_set_str(handle, "Radio", devName);
    if (err != ESP_OK) {
        printf("Fel vid skrivning av device name\n");
        return;
    }
    nvs_commit(handle);
}
void NVSS::setSerialNumber (const char* serialNummer){
    err = nvs_set_str(handle, "Radi324E", serialNummer);
    if (err != ESP_OK)
    {
        printf("Fel vid skrivning av device nummer.\n");
    }
    nvs_commit(handle);
}
char* NVSS::getDeviceName (){
    // Example (without error checking) of using nvs_get_str to get a string into dynamic array:
    size_t required_size;
    err = nvs_get_str(handle, "Radio", NULL, &required_size);
    if (err != ESP_OK)
    {
        printf("Fel vi läsning av minnetn.\n");
        return NULL; // för att fri gör minnet??
    }
    

    char* device_name =(char*) malloc(required_size);
    err = nvs_get_str(handle, "Radio", device_name, &required_size);
    if (err != ESP_OK)
    {
        printf("Fel vid läsning sträing av NVS.\n");
        free(device_name);
        return NULL;
    }
    return device_name;
}
char* NVSS::getSerialNumber (){
    return "Fill57";
}