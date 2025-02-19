#pragma once
#include <stdio.h>
#include <iostream>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "driver/adc.h"
#define arrSize 10

typedef void (*Callback)(int, int);

class Potentiometer{
private:
    int pin; //kan användas som min channel om den är mellan 0 och 6
    adc1_channel_t channel;
    int thresHold;
    bool risingEdge;
    int filterArr[arrSize];
    int index;
    int data;
    int summa = 0;
    int medel;
    Callback cb;

public:
    Potentiometer(int pin, int thersHold,bool risingEdge, adc_atten_t atten, adc_bits_width_t width_bit) :
    pin(pin), thresHold(thersHold), risingEdge(risingEdge) 
    {
        channel = (adc1_channel_t)pin;
        if(0 <= pin && pin <= 6)
        adc1_config_channel_atten(channel, atten);
        adc1_config_width(width_bit);
        index = 0;
    }
    void update(void);
    int getValue(void);
    void setOnThreshold(int threshold, bool risingEdge, void (*onThreshold)(int pin, int value), int data);
    int getData() {return data;}
    int getPin() {return pin;}
    Callback getfunk() {return cb;}
    void doCallBack(int pin, int value);
    void thresholeState(int pin, int value);
    int getRisingEdge(){return risingEdge;}
    
};


