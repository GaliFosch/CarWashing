#include "ComponentsManager.hpp"

const int ledPins[] = {12, 2, 3};
const int pirPin = 4;
const int sonarPins[] = {5, 6};
const int gatePin = 5;
const int buttonPin = 8;
const int tempSensorPin = 9;

ComponentsManager::ComponentsManager() : led1(ledPins[0]),
                             led2(ledPins[1]),
                             led3(ledPins[2]),
                             pir(pirPin),
                             sonar(sonarPins[0], sonarPins[1], 20),
                             gate(gatePin),
                             lcd(0x27, 20, 4),
                             startButton(buttonPin),
                             tempSensor(tempSensorPin)
{
}

void ComponentsManager::init()
{
    lcd.init();
    lcd.backlight();
}

Led *ComponentsManager::getLed1()
{
    return &led1;
}
Led *ComponentsManager::getLed2()
{
    return &led2;
}
Led *ComponentsManager::getLed3()
{
    return &led3;
}

PIRSensor *ComponentsManager::getPirSensor()
{
    return &pir;
}

ProximitySensor *ComponentsManager::getProximitySensor()
{
    return &sonar;
}

Button *ComponentsManager::getButton()
{
    return &startButton;
}

TemperatureSensor *ComponentsManager::getTemperatureSensor()
{
    return &tempSensor;
}

void ComponentsManager::print(String string)
{
    lcd.setCursor(2, 1);
    lcd.print(string);
}

void ComponentsManager::openGate()
{
    gate.open();
}

void ComponentsManager::closeGate()
{
    gate.close();
}
