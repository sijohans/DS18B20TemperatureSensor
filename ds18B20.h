#ifndef DS18B20_H
#define DS18B20_H

#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
    

class ds18B20 {
    private:
        FILE *file;
        const char *fileName;
    public:
        ds18B20(const char *fileName);
        double getTemperature(void);
        int getTemperatureRaw(void);
};

#endif