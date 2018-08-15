//
//  WiringPiGPIO.cpp
//  ssd1306
//
//  Created by Michael Hill on 8/13/18.
//  Copyright © 2018 Michael Hill. All rights reserved.
//

#include "wPiGPIO.h"
#include "wiringPi.h"

class WiringPiGPIOImpl : public WiringPiGPIO
{
public:
    WiringPiGPIOImpl()
    {
        wiringPiSetup();
    }
    
    void setup(int pin, DIR direction)
    {
        if (direction == DIR::IN)
        {
            pinMode(pin, INPUT);
        }
        else
        {
            pinMode(pin, OUTPUT);
        }
    }
    
    void set_low(int pin)
    {
        digitalWrite(pin, LOW);
    }
    
    void set_high(int pin)
    {
        digitalWrite(pin, HIGH);
    }
};

GPIO* WiringPiGPIO::NewWiringPiGPIO()
{
    return new WiringPiGPIOImpl();
}
