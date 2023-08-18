[![.github/workflows/main.yml](https://github.com/SndrSchnklshk/HDC302x/actions/workflows/main.yml/badge.svg)](https://github.com/SndrSchnklshk/HDC302x/actions/workflows/main.yml)

[!["Buy Me A Coffee"](https://www.buymeacoffee.com/assets/img/custom_images/yellow_img.png)](https://www.buymeacoffee.com/sndrschnklshk)

# Texas Instruments (TI) HDC3020, HDC3021, HDC3022 Temperature sensors

Quick and easy to use Library for the TI HDC302x tempearture and humidity sensors (HDC3020, HDC3021, HDC3022). 

The following are currently supported by the Library : **HDC3020**, **HDC3021** and **HDC3022** (feel free to extend)

*2% RH ultra-low-power digital relative humidity sensor, IP67 filter*

The HDC302x is an integrated capacitive based
relative humidity (RH) and temperature sensor. It
provides high accuracy measurements over a wide
supply range (1.62 V – 5.5 V), along with ultra-low
power consumption in a compact 2.5-mm × 2.5-mm
package. Both the temperature and humidity sensors
are 100% tested and trimmed on a production setup
that is NIST traceable and verified with equipment that
is calibrated to ISO/IEC 17025 standards.

Check the TI User Guide on how to use it: [Download PDF](https://www.ti.com/lit/ug/snau250/snau250.pdf)

# How to Use

1) Download and Add the source files to your project (Download the files, use the Arduino lib manager or Git Clone):
```git clone https://github.com/SndrSchnklshk/HDC302x```

2) Start using the Lib, include the following:
```#include "HDC302x.h"```

3) Initialize the lib with the pre set I2C address:
```hdc.Initialize(HDC302X_ADDRESS1)```

4) Read the Temperature and Humidity using the 'HDC302xDataResult' Struct.
```HDC302xDataResult result = hdc.ReadData();```

## Full example

Example showing C code on how to use the library.

### Arduino
```
// Very Basic Arduino Example to read every 5 seconds and serial outputs the temperature and humidity.
#include "Arduino.h"    // Include the basic stuff
#include "HDC302x.h"    // Include the header

HDC302x hdc = HDC302x();    // Create class

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
```

# Future improvements

1) Add more read options (besides the single read)
2) Configure tempearture alerts
3) Read chip Min and Max readings
4) ... let me know!

# More information

TI Datasheet for more information: [Download PDF](https://www.ti.com/product/HDC3020)

This lib is heavily based on the data Josh Wyatt (Texas Intruments Inc) has provided. If you buy me a beer, don't forget him as well ;)
