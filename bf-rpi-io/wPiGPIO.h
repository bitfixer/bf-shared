//
//  WiringPiGPIO.hpp
//  ssd1306
//
//  Created by Michael Hill on 8/13/18.
//  Copyright © 2018 Michael Hill. All rights reserved.
//

#ifndef WiringPiGPIO_h
#define WiringPiGPIO_h

#include "bf-gpio.h"

class WiringPiGPIO : public GPIO
{
public:
    static GPIO* NewWiringPiGPIO();
};

#endif /* WiringPiGPIO_h */
