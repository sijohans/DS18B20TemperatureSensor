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

    char buff[5];
    int temp;

    file = fopen(fileName, "rb");
    if (file == NULL) {
        throw 0;
    }

    /* Move file pointer to where temperature output begins */
    fseek(file, 69, SEEK_SET);
    fread(string, 5, 1, file);

    sscanf(string, "%d", &i);
    fclose(file);

    return temp;

}