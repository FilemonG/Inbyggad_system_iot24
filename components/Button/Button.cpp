
#include "Button.h"

void Button::init()
{
    gpio_config_t buttonConf;
        buttonConf.mode = GPIO_MODE_INPUT;
        buttonConf.pull_up_en = GPIO_PULLUP_ENABLE;
        buttonConf.pull_down_en = GPIO_PULLDOWN_DISABLE;
        buttonConf.intr_type = GPIO_INTR_NEGEDGE;
}
void Button::button_uppdate(){
    
}
bool Button::isPressed(){
    return false;
}
void Button::setOnPressed(void(*onPressed)(int pin)){

}
