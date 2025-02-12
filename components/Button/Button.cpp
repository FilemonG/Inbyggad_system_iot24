
#include "Button.h"

#define PIN_BIT_MASK 1ULL << pinNum;
void Button::init()
{
    gpio_config_t buttonConf;
    buttonConf.pin_bit_mask = PIN_BIT_MASK;
    buttonConf.mode = GPIO_MODE_INPUT;
    buttonConf.pull_up_en = GPIO_PULLUP_DISABLE;
    buttonConf.pull_down_en = GPIO_PULLDOWN_ENABLE;
    buttonConf.intr_type = GPIO_INTR_NEGEDGE;
    gpio_config(&buttonConf);

}
void Button::button_uppdate(){
   int level = 0;
   level = gpio_get_level(pinNum);
   printf("%d\n",level);
}
bool Button::isPressed(){
    return true;
}
void Button::setOnPressed(void(*onPressed)(int pin)){

}
