# Texas Instruments (TI) HDC3020, HDC3021, HDC3022 Temperature sensors

Quick and easy to use Library for the TI HDC302x tempearture and humidity sensors (HDC3020, HDC3021, HDC3022). 

The following are currently supported by the Library : **HDC3020**, **HDC3021** and **HDC3022** (feel free to extend)

The HDC302x is an integrated capacitive based
relative humidity (RH) and temperature sensor. It
provides high accuracy measurements over a wide
supply range (1.62 V – 5.5 V), along with ultra-low
power consumption in a compact 2.5-mm × 2.5-mm
package. Both the temperature and humidity sensors
are 100% tested and trimmed on a production setup
that is NIST traceable and verified with equipment that
is calibrated to ISO/IEC 17025 standards.

# How to Use

1) Download and Add the source files to your project (Download the files, use the Arduino lib manager or Git Clone):
```git clone https://github.com/SndrSchnklshk/HDC302x```

2) Start using the Lib, include the following:
```#include "HDC302x.h"```

3) Initialize the lib with the pre set I2C address:
```hdc.Initialize(HDC302X_ADDRESS1)```

4) Read the Temperature and Humidity using the 'HDC302xDataResult' Struct.
```HDC302xDataResult result = hdc.ReadData();```

# More information

TI Datasheet for more information: [Download PDF](https://www.ti.com/product/HDC3020)

This lib is heavily based on the data Josh Wyatt (Texas Intruments Inc) has provided. If you buy me a beer, don't forget him as well ;)
