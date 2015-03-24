#include "ds18B20.h"

ds18B20::ds18B20(const char *fileName) {
    file = fopen(fileName, "rb");
    if (file == NULL) {
        throw std::exception();
    }
}

double ds18B20::getTemperature() {
    return (double) getTemperatureRaw()/1000;
}

int ds18B20::getTemperatureRaw() {

    int size = 75;
    char temp[6];
    
    char string[size];
    fread(string, size, 1, file);
    
    temp[0] = string[69];
    temp[1] = string[70];
    temp[2] = string[71];
    temp[3] = string[72];
    temp[4] = string[73];
    return atoi(temp);
}