//
//  WiringPiSPI.h
//  ssd1306
//
//  Created by Michael Hill on 8/13/18.
//  Copyright © 2018 Michael Hill. All rights reserved.
//

#ifndef WiringPiSPI_h
#define WiringPiSPI_h

#include <stdio.h>
#include "bf-spi.h"
#include "bf-gpio.h"

class WiringPiSPI : public SPI
{
public:
    static SPI* NewWiringPiSPI(int channel);
    static SPI* NewWiringPiSPI(int channel, GPIO* gpio, int cs);
};

#endif /* WiringPiSPI_h */
