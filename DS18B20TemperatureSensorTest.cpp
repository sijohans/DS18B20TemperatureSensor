/* Requests DS18B20 filepath, and prints current temperature to terminal.
Requires sijohans' DS18B20 C++ library from here; https://github.com/sijohans/DS18B20TemperatureSensor.git
To compile enter;
g++ -Wall DS18B20TemperatureSensorTest.cpp DS18B20TemperatureSensor.cpp -o DS18B20TemperatureSensorTest
To run; ./DS18B20TemperatureSensorTest
*/

#include <iostream>
#include <string>
#include "DS18B20TemperatureSensor.h"
using namespace std;

int main() {
    double tempNow;
    char w1_fileentry[256];
    
    cout << "Enter the full 1-Wire device filepath: ";
    cin >> w1_fileentry;
    
    cout << "The path you entered was " << w1_fileentry << endl;
    
    DS18B20TemperatureSensor w1device1 (w1_fileentry);
    tempNow = w1device1.getTemperature();
    
    cout << "The current temperature is " << tempNow << " degrees Celsius" <<endl;
    
    return 0;
}
