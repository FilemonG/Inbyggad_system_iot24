#include <stdio.h>
#include <iostream>
#include "Helper_Comp.h"
namespace Inbyggda_IoT24
{
    int func(void)
    {
        return 1;
    }
    int printNumbers (int start, int stop)
    {
        for (int i = start; i <= stop; i++){
            printf("Round: %d\n", i);
        }
        return 0;
    }
    //void takeTimeAndPrintEverySecond (int time);
    void multiply (int a, int b);
    
}