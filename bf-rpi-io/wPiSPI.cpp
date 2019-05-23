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
    WiringPiSPIImpl(int channel, GPIO* gpio, int cs)
    : _spi(channel)
    , _buffer(NULL)
    , _bufferSize(0)
    , _gpio(gpio)
    , _cs(cs)
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
        spiwrite(&byte, 1);
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
        int ret = spiwrite(_buffer, size);
    }
    
    void set_clock_hz(int hz)
    {
        wiringPiSPISetup(_spi, hz);
        if (_gpio != NULL && _cs >= 0)
        {
            _gpio->setup(_cs, GPIO::OUT);
            _gpio->set_high(_cs);
        }
    }

    void set_chipselect(GPIO* gpio, int cs)
    {
        _gpio = gpio;
        _cs = cs;
        if (_gpio != NULL && _cs >= 0)
        {
            _gpio->setup(_cs, GPIO::OUT);
            _gpio->set_high(_cs);
        }
    }
    
private:
    int _spi;
    uint8_t* _buffer;
    int _bufferSize;
    GPIO* _gpio;
    int _cs;

    int spiwrite(unsigned char* data, int size)
    {
        if (_gpio != NULL && _cs >= 0)
        {
            _gpio->set_low(_cs);
        }
        int ret = wiringPiSPIDataRW(_spi, data, size);
        if (_gpio != NULL && _cs >= 0)
        {
            _gpio->set_high(_cs);
        }
        return ret;
    }
};

SPI* WiringPiSPI::NewWiringPiSPI(int channel)
{
    return new WiringPiSPIImpl(channel, NULL, -1);
}

SPI* WiringPiSPI::NewWiringPiSPI(int channel, GPIO* gpio, int cs)
{
    return new WiringPiSPIImpl(channel, gpio, cs);
}
