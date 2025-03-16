
#include <driver/adc.h>

class LightSensor {
public:
    LightSensor(adc1_channel_t sensorPin);  // Konstruktor
    void begin();                           // Initiera sensorn
    int readLightLevel();                   // Läs ljusnivån

private:
    adc1_channel_t sensorPin;               // Pin för ljussensorn
};
