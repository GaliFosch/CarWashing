#include "PartManager.hpp"

const int ledPins[] = {1, 2, 3};
const int pirPin = 4;
const int sonarPins[] = {5,6};
const int gatePin = 7;
const int buttonPin = 8;
const int tempSensorPin = 9;

PartManager::PartManager()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = &Led(ledPins[i]);
    }
    pir = &PIRSensor(pirPin);
    sonar = &ProximitySensor(sonarPins[0], sonarPins[1], 20);
    gate = &Gate(gatePin);
    lcd = &LiquidCrystal_I2C(0x27,20,4);
    startButton = &Button(buttonPin);
    tempSensor = &TemperatureSensor(tempSensorPin);
}

PartManager::~PartManager()
{
}

void PartManager::init()
{
    lcd->init();
    lcd->backlight();
}

Led *PartManager::getLed(int index)
{
    return leds[index];
}

PIRSensor *PartManager::getPirSensor()
{
    return pir;
}

ProximitySensor *PartManager::getProximitySensor()
{
    return sonar;
}

Button *PartManager::getButton()
{
    return startButton;
}

TemperatureSensor *PartManager::getTemperatureSensor()
{
    return tempSensor;
}

void PartManager::print(String string)
{
    lcd->setCursor(2, 1);
    lcd->print(string);
}

void PartManager::openGate()
{
    gate->open();
}

void PartManager::closeGate()
{
    gate->close();
}
