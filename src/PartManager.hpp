#ifndef __PART_MANAGER__
#define __PART_MANAGER__

#include <LiquidCrystal_I2C.h>

#include "components/api/Led.hpp"
#include "components/api/PIRSensor.hpp"
#include "components/api/ProximitySensor.hpp"
#include "components/api/Gate.hpp"
#include "components/api/Button.hpp"
#include "components/api/TemperatureSensor.hpp"

class PartManager
{
private:
    static PartManager *instancePtr;
    Led led1;
    Led led2;
    Led led3;
    PIRSensor pir;
    ProximitySensor sonar;
    Gate gate;
    LiquidCrystal_I2C lcd;
    Button startButton;
    TemperatureSensor tempSensor;
    PartManager();

public:
    PartManager(const PartManager &obj) = delete;
    static PartManager *getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new PartManager();
        }
        return instancePtr;
    }

    void init();
    PIRSensor *getPirSensor();
    ProximitySensor *getProximitySensor();
    Button *getButton();
    TemperatureSensor *getTemperatureSensor();

    Led getLed1();
    Led getLed2();
    Led getLed3();

    void print(String string);
    void openGate();
    void closeGate();
};

PartManager* PartManager::instancePtr=NULL;

#endif
