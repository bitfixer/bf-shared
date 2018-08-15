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

class WiringPiSPI : public SPI
{
public:
    static SPI* NewWiringPiSPI();
};

#endif /* WiringPiSPI_h */
