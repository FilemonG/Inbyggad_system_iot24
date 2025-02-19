#include "Potentiometer.h"

void Potentiometer::update(void){

    int value = adc1_get_raw(channel);
    if (index > arrSize-1)
    {
        index = 0;
    }
    filterArr[index] = value;
    index++;

summa = 0;
static int latch = 0;  // Statisk latch så att den inte nollställs varje gång

for (int i = 0; i < arrSize; i++) { 
    summa += filterArr[i];
}

// Kontrollera att arrSize inte är 0 för att undvika division med noll
if (arrSize > 0) {
    medel = summa / arrSize;

    if (medel < 1000 && latch == 0) {
        if (getRisingEdge() == false && cb != NULL )
        {
            cb(2,0);
        }
            latch = 1;  
    }
   if (medel >= 1000 && latch == 1) {
    if (getRisingEdge() == true && cb != NULL)
    {
        cb(2,0);
    } 
         latch = 0; 
   }
   
}
}
int Potentiometer::getValue(void){
   return medel; //returnerar tot-summa / storleken på arr för att få medelvärde */
}
void Potentiometer::setOnThreshold(int threshold, bool risingEdge, void (*onThreshold)(int pin, int value), int data)
{
    cb = onThreshold;
    data = data;
    this->risingEdge = risingEdge;
}
void Potentiometer::doCallBack(int pin,int value){
   cb(pin,value);
}
