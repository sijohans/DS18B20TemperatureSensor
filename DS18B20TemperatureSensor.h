#ifndef DS18B20TemperatureSensor_H
#define DS18B20TemperatureSensor_H

#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
    

class DS18B20TemperatureSensor {
    private:
        FILE *file;
        const char *fileName;
    public:
        DS18B20TemperatureSensor(const char *fileName);
        double getTemperature(void);
        int getTemperatureRaw(void);
};

#endif