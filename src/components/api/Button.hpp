#ifndef __BUTTON__
#define __BUTTON__

class Button
{
private:
    const int pin;

public:
    Button(int pin);
    ~Button();
    int isPressed();
};

#endif