#include "DS18B20TemperatureSensor.h"

DS18B20TemperatureSensor::DS18B20TemperatureSensor(const char *fileName) {
    file = fopen(fileName, "r");
    if (file == NULL) {
        throw 0;
    } else {
        this->fileName = fileName;
        fclose(file);
    }
}

double DS18B20TemperatureSensor::getTemperature() {
    return (double) getTemperatureRaw()/1000;
}

int DS18B20TemperatureSensor::getTemperatureRaw() {

    char buff[5];
    int temp;

    file = fopen(fileName, "rb");
    if (file == NULL) {
        throw 0;
    }

    /* Move file pointer to where temperature output begins */
    fseek(file, 69, SEEK_SET);
    fread(buff, 5, 1, file);

    sscanf(buff, "%d", &temp);
    fclose(file);

    return temp;

}