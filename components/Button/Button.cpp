
#include "Button.h"


void Button::init()
{
    gpio_config_t buttonConf;
    buttonConf.pin_bit_mask = 1ULL << pinNum;
    buttonConf.mode = mode;
    buttonConf.pull_up_en = GPIO_PULLUP_DISABLE;
    buttonConf.pull_down_en = GPIO_PULLDOWN_ENABLE;
    buttonConf.intr_type = GPIO_INTR_NEGEDGE;
   
    gpio_config(&buttonConf);
    
}
void Button::button_uppdate(){
   
    TickType_t time = xTaskGetTickCount();
    int level = gpio_get_level(pinNum);
   
   switch (curr_state)
   {
   case off:
        if (level == 1)
        {
            elapsetime = time;
            next_state = de_off;
            if (onPressedCallback)
            {
                onPressedCallback(pinNum);
            }
        }
        break;
    case de_off:
        if(time - elapsetime >= pdMS_TO_TICKS(30)){
            next_state = on;
            elapsetime = time;
            
        }
        break;
    case on:
        if (level == 0)
        {
            next_state = de_on;
            elapsetime = time;
            
        }
        break;
    case de_on:
        if(time - elapsetime >= pdMS_TO_TICKS(30)){
            next_state = off;
            elapsetime = time;
        }
        break;
   default:
    printf("error\n");
    break;
   }
  
    elapsetime = time;
    curr_state = next_state;
}
bool Button::isPressed(){
   if (curr_state == de_off || curr_state == on )
    {
        return true;
    }
    else 
    {
        return false;
    }
   
}
void Button::setOnPressed(void(*onPressed)(int pin)) {
    onPressedCallback = onPressed;
}
