/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __bf_spi_h__
#define __bf_spi_h__

#include <stdint.h>
#include "bf-gpio.h"

class SPI {
public:
    SPI() {}
    
    virtual void write(uint8_t byte) = 0;
    virtual void write(uint8_t* buffer, int size) = 0;
    virtual void set_clock_hz(int hz) = 0;
    virtual void set_chipselect(GPIO* gpio, int cs) = 0;
};

#endif