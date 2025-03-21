#include <stdio.h>
#include "lightSensor.h"
#include "driver/adc.h"


void LightSensor::init(){
    adc1_config_width(ADC_WIDTH_BIT_12);  // 12-bitars upplösning
    adc1_config_channel_atten((adc1_channel_t)sensorPin, ADC_ATTEN_DB_11);
}                        
int LightSensor::readLightLevel(){
    return adc1_get_raw((adc1_channel_t) sensorPin);
}