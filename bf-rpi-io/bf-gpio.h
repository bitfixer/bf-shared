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

#ifndef __bf_gpio_h__
#define __bf_gpio_h__

class GPIO {
public:
    GPIO() {}
    
    typedef enum dir {
        IN = 0,
        OUT = 1
    } DIR;

    virtual void setup(int pin, DIR direction) = 0;
    virtual void set_low(int pin) = 0;
    virtual void set_high(int pin) = 0;
    virtual int read(int pin) = 0;
};

#endif