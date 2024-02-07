// Arduino Example for basic usage of the HDC302x Lib
#include "Arduino.h"
#include "HDC302x.h" // Include the header

HDC302x hdc = HDC302x();    //Preselected I2C Address

void setup()
{
    Serial.begin(115200);                       // Init the serial device
    Serial.println("Ola! Feeling chill?");      // Welcome message

    if (!hdc.Initialize(HDC302X_ADDRESS1))      // Did the initialization fail?
    {
        Serial.println("Sorry, cannot find sensor with the selected address"); 
    } 
}

void loop()
{
    HDC302xDataResult result = hdc.ReadData();  // Calculate the temperature

    Serial.print("Temperature is ");            // Begin printing output
    Serial.print(result.Temperature);           // Print the Temperature
    Serial.print("°C, Humidity is ");           // Print the degrees plus a newline
    Serial.println(result.Humidity);            // Print the Temperature

    delay(5000);                                // Wait 5 seconds
}