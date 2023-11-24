#ifndef __PART_MANAGER__
#define __PART_MANAGER__

#include <LiquidCrystal_I2C.h>

#include "components/api/Led.hpp"
#include "components/api/PIRSensor.hpp"
#include "components/api/ProximitySensor.hpp"
#include "components/api/Gate.hpp"
#include "components/api/Button.hpp"
#include "components/api/TemperatureSensor.hpp"

#define NUM_LEDS 3

class PartManager
{
private:
    Led* leds[NUM_LEDS];
    PIRSensor* pir;
    ProximitySensor* sonar;
    Gate* gate;
    LiquidCrystal_I2C* lcd;
    Button* startButton;
    TemperatureSensor* tempSensor;
public:
    PartManager();
    ~PartManager();
    void init();
    Led* getLed(int index);
    PIRSensor* getPirSensor();
    ProximitySensor* getProximitySensor();
    Button* getButton();
    TemperatureSensor* getTemperatureSensor();

    void print(String string);
    void openGate();
    void closeGate();
};

#endif 
