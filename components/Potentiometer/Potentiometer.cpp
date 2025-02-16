#include <stdio.h>
#include "Potentiometer.h"

void Potentiometer::update(void){
    
    int value = adc1_get_raw(channel);
    if (index > arrSize-1)
    {
        index = 0;
    }
    filterArr[index] = value;
    index++;
    
}
int Potentiometer::getValue(void){
    int summa = 0;
    for (int i = 0; i < arrSize; i++)
    {
        summa += filterArr[i];
        
    }
    
    
    return summa / arrSize;
    
}
void Potentiometer::setOnThreshold(int threshold, bool risingEdge, void (*onThreshold)(int pin, int value), int data)
{
    cb = onThreshold;
    data = data;
}
