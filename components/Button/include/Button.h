#pragma once

class Button{
private:
    
public:
    bool Pressed;
    
};
void init(void);
//ska ej vara statisk ska kunna göra flera knappar
//för cpp får konstruktorn används för parametrar
void button_uppdate(void);
//debounce krävs
//10 milisekunder period eller snabbare
bool isPressed(void); //får inte läsa pinnen, måste ta ett redan utläst värde
void setOnPressed(void(*onPressed)(int pin))

