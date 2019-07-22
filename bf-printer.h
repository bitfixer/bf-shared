#ifndef _bf_printer_h_
#define _bf_printer_h_

class Printer
{
public:
    virtual void print(const char* string) = 0;
    virtual int tick(float seconds) = 0;
};

#endif
