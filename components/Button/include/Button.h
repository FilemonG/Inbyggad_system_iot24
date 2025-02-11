#pragma once


class Button{
private:
    
public:
    gpio_config_t pin;
    Button(gpio_config_t pin) : pin(pin){}

void init();
//ska ej vara statisk ska kunna göra flera knappar
//för cpp får konstruktorn används för parametrar


void button_uppdate(void);
//debounce krävs
//10 milisekunder period eller snabbare

bool isPressed() //får inte läsa pinnen, måste ta ett redan utläst värde
{
    return gpio_get_level(pin) == 0;
}

void setOnPressed(void(*onPressed)(int pin));

};
