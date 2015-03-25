#include "ds18B20.h"

ds18B20::ds18B20(const char *fileName) {
    file = fopen(fileName, "r");
    if (file == NULL) {
        throw 0;
    } else {
        this->fileName = fileName;
        fclose(file);
    }
}

double ds18B20::getTemperature() {
    return (double) getTemperatureRaw()/1000;
}

int ds18B20::getTemperatureRaw() {

    size_t fileSize;
    file = fopen(fileName, "r");
    if (file == NULL) {
        throw 0;
    }
    int size = 6;
    
   fseek(file, 0L, SEEK_END);
   fileSize = ftell(file);
   fseek(file, 0L, SEEK_SET);
   
   fseek(file, -size, SEEK_END);

    

    char buff[size];
    fread(buff, sizeof(char), size, file);
    int temp;
    sscanf(buff, "%d", &temp);
    fclose(file);
    return temp;
}