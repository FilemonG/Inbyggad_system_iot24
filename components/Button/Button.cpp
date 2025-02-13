
#include "Button.h"

#define PIN_BIT_MASK 1ULL << pinNum;
#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_Yellow "\033[0;33m"

void Button::init()
{
    gpio_config_t buttonConf;
    buttonConf.pin_bit_mask = PIN_BIT_MASK;
    buttonConf.mode = mode;
    buttonConf.pull_up_en = GPIO_PULLUP_DISABLE;
    buttonConf.pull_down_en = GPIO_PULLDOWN_ENABLE;
    buttonConf.intr_type = GPIO_INTR_NEGEDGE;
    //buttonConf.curr_state = off;
    //buttonConf.next_state = off;
    gpio_config(&buttonConf);
    if (mode == pull_up_en)
    {
        gpio_set_pull_mode(pinNum, GPIO_PULLUP_ONLY);
        printf(ANSI_GREEN"lvl: %d\n", level);
    }
    
    if (mode == pull_down_en)
    {
        gpio_set_pull_mode(pinNum, GPIO_PULLDOWN_ONLY);
        printf(ANSI_Yellow"lvl: %d\n", level);
    }
    
}
void Button::button_uppdate(){
   
    TickType_t time = xTaskGetTickCount();
    if (mode == GPIO_PULLDOWN_ENABLE)
    {
       int level = gpio_get_level(pinNum);
    }
    if (mode == GPIO_PULLUP_ENABLE)
    {
       int level = !gpio_get_level(pinNum);
    }
    printf("lvl: %d state: %d\n", level, curr_state);
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
            printf("press");
            next_state = on;
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
            printf("release");
            next_state = off;
        }
        break;
   default:
    printf("error");
    break;

   }
   if (curr_state != next_state){printf("Current state: %d, Next state:%d \n",curr_state,next_state);}
   curr_state = next_state;
}
bool Button::isPressed(){
    return level;
}
void Button::setOnPressed(void(*onPressed)(int pin)){

}
