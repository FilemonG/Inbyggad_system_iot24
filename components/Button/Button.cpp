
#include "Button.h"


#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_Yellow "\033[0;33m"

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
        }
        break;
    case de_off:
        if(time - elapsetime >= pdMS_TO_TICKS(30)){
            next_state = on;
            elapsetime = time;
            if (onPressedCallback)
            {
                onPressedCallback(pinNum);
            }
        }
        break;
    case on:
        if (level == 0)
        {
            next_state = de_on;
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
  
    printf(ANSI_Yellow"lvl: %d state: %d\n", level, curr_state);
    elapsetime = time;
}
bool Button::isPressed(){
    return gpio_get_level(pinNum);
}
void Button::setOnPressed(void(*onPressed)(int pin)) {
    onPressedCallback = onPressed;
}
