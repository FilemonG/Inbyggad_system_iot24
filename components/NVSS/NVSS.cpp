#include "NVSS.h"
#include <cstring>

#define DEVICENAME "DeviceName"
#define SERIALNUMMER "SerialNummer"

int NVSS::init() {
    // Initialize NVS flash
    err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);

    // Open NVS namespace
    err = nvs_open("Test_namespace", NVS_READWRITE, &handle);
    if (err != ESP_OK) {
        printf("Failed to open namespace");
        return -1;
    }
    printf("Namespace open\n");

    // Read device name
    size_t required_size;
    err = nvs_get_str(handle, DEVICENAME, NULL, &required_size);
    if (err != ESP_OK || required_size <= 1 || required_size > sizeof(devName)) {
        printf("No device name found or invalid size, using default");
        strncpy(devName, "DefaultDevice", sizeof(devName)-1);
        devName[sizeof(devName)-1] = '\0';
    } else {
        err = nvs_get_str(handle, DEVICENAME, devName, &required_size);
        if (err != ESP_OK) {
            printf("Error reading device name");
            return -1;
        }
    }

    // Read serial number
    err = nvs_get_str(handle, SERIALNUMMER, NULL, &required_size);
    if (err != ESP_OK || required_size <= 1 || required_size > sizeof(serialNummer)) {
        printf("No serial number found");
        strncpy(serialNummer, "000000000000000", sizeof(serialNummer)-1);
        serialNummer[sizeof(serialNummer)-1] = '\0';
    } else {
        err = nvs_get_str(handle, SERIALNUMMER, serialNummer, &required_size);
        if (err != ESP_OK) {
            printf("Error reading serial number");
            return -1;
        }
    }

    return 0;
}

void NVSS::setDeviceName(char* new_devName) {
    if (strlen(new_devName) >= sizeof(devName)) {
        printf("Device name too long");
        return;
    }

    err = nvs_set_str(handle, DEVICENAME, new_devName);
    if (err != ESP_OK) {
        printf("Error writing device name");
        return;
    }

    strncpy(devName, new_devName, sizeof(devName)-1);
    devName[sizeof(devName)-1] = '\0';
    nvs_commit(handle);
    printf("Device name:%s", devName);
}

void NVSS::setSerialNumber(char* new_serialNummer) {
    if (strlen(new_serialNummer) >= sizeof(serialNummer)) {
        printf("Serial number too long");
        return;
    }

    err = nvs_set_str(handle, SERIALNUMMER, new_serialNummer);
    if (err != ESP_OK) {
        printf("Error writing serial number");
        return;
    }

    strncpy(serialNummer, new_serialNummer, sizeof(serialNummer)-1);
    serialNummer[sizeof(serialNummer)-1] = '\0';
    nvs_commit(handle);
    printf("Serial number:%s", serialNummer);
}

char* NVSS::getDeviceName() const {
    return const_cast<char*>(devName);
}

char* NVSS::getSerialNumber() const {
    return const_cast<char*>(serialNummer);
}


