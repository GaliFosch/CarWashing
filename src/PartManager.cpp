#include "PartManager.hpp"

const int ledPins[] = {1, 2, 3};
const int pirPin = 4;
const int sonarPins[] = {5, 6};
const int gatePin = 7;
const int buttonPin = 8;
const int tempSensorPin = 9;

PartManager::PartManager(): 
    led1(ledPins[0]),
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

void PartManager::init()
{
    lcd.init();
    lcd.backlight();
}

Led PartManager::getLed1(){
    return led1;
}
Led PartManager::getLed2(){
    return led2;
}
Led PartManager::getLed3(){
    return led3;
}

PIRSensor *PartManager::getPirSensor()
{
    return &pir;
}

ProximitySensor *PartManager::getProximitySensor()
{
    return &sonar;
}

Button *PartManager::getButton()
{
    return &startButton;
}

TemperatureSensor *PartManager::getTemperatureSensor()
{
    return &tempSensor;
}

void PartManager::print(String string)
{
    lcd.setCursor(2, 1);
    lcd.print(string);
}

void PartManager::openGate()
{
    gate.open();
}

void PartManager::closeGate()
{
    gate.close();
}
