#include "ds18B20.h"

ds18B20::ds18B20(const char *fileName) {
    file = fopen(fileName, "r");
    if (file == NULL) {
        throw 0;
    }
}

ds18B20::~ds18B20() {
    fclose(file);
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

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        perror("No path do sensor specified");
        return 0;
    }
    
    try {
        ds18B20 s = ds18B20(argv[1]);
        std::cout << s.getTemperature() << std::endl;
        return 0;
    } catch (std::exception e) {
        perror("File not found");
        return 0;
    }
    
}