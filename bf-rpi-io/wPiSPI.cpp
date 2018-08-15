//
//  WiringPiSPI.cpp
//  ssd1306
//
//  Created by Michael Hill on 8/13/18.
//  Copyright © 2018 Michael Hill. All rights reserved.
//

#include "wPiSPI.h"
#include "wiringPiSPI.h"
#include <stdlib.h>
#include <string.h>

class WiringPiSPIImpl : public WiringPiSPI
{
public:
    WiringPiSPIImpl()
    : _spi(-1)
    , _buffer(NULL)
    , _bufferSize(0)
    {
    }
    
    ~WiringPiSPIImpl()
    {
        if (_buffer)
        {
            free(_buffer);
        }
    }
    
    void write(uint8_t byte)
    {
        wiringPiSPIDataRW(0, &byte, 1);
    }
    
    void write(uint8_t* buffer, int size)
    {
        if (!_buffer)
        {
            _buffer = (uint8_t*)malloc(size);
            _bufferSize = size;
        }
        
        if (_bufferSize < size)
        {
            _buffer = (uint8_t*)realloc((void*)_buffer, size);
        }
        
        memcpy(_buffer, buffer, size);
        int ret = wiringPiSPIDataRW(0, _buffer, size);
        printf("SPI wrote %d\n", ret);
    }
    
    void set_clock_hz(int hz)
    {
        wiringPiSPISetup(0, hz);
    }
    
private:
    int _spi;
    uint8_t* _buffer;
    int _bufferSize;
};

SPI* WiringPiSPI::NewWiringPiSPI()
{
    return new WiringPiSPIImpl();
}
