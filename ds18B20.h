#ifndef DS18B20_H
#define DS18B20_H

#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
    

class ds18B20 {
    private:
        FILE *file;
        int temp;
    public:
        ds18B20(const char *fileName);
        ~ds18B20();
        double getTemperature(void);
        int getTemperatureRaw(void);
};

#endif