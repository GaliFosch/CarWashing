#include "ComponentsManager.hpp"
#include <Arduino.h>

#define PIR_PIN 2
#define TEMP_ANALOG_PIN A1
#define SONAR_PIN_ECHO 11
#define SONAR_PIN_TRIGGER 12
#define SERVO_PIN 4
#define L1_PIN 7
#define L2_PIN 6
#define L3_PIN 5
#define BUTTON_PIN 3

ComponentsManager::ComponentsManager() : led1(L1_PIN),
                             led2(L2_PIN),
                             led3(L3_PIN),
                             pir(PIR_PIN),
                             sonar(SONAR_PIN_TRIGGER, SONAR_PIN_ECHO, 20),
                             gate(SERVO_PIN),
                             lcd(0x27, 20, 4),
                             startButton(BUTTON_PIN),
                             tempSensor(TEMP_ANALOG_PIN)
{
}

void ComponentsManager::init()
{
    lcd.init();
    gate.init();
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
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(string);
}

void ComponentsManager::turnOnLCD(){
    lcd.backlight();
}

void ComponentsManager::turnOffLCD(){
    lcd.clear();
    lcd.noBacklight();
}

void ComponentsManager::openGate()
{
    gate.open();
}

void ComponentsManager::closeGate()
{
    gate.close();
}
