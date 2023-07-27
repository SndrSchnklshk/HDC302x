// (c) 2023 Sander Schinkelshoek based on Josh Wyatt code example of TEXAS INSTRUMENTS INC.
// This code is licensed under MIT license (see LICENSE.txt for details)
//
// Datasheet: https://www.ti.com/product/HDC3020
#ifndef HDC302x_h
#define HDC302x_h

#pragma once

/*
  I2C Addresses  8 bit    7 bit
  HDC302x #1 ==> 0x88 ==> 0x44
  HDC302x #2 ==> 0x8A ==> 0x45
  HDC302x #3 ==> 0x8C ==> 0x46
  HDC302x #4 ==> 0x8E ==> 0x47
*/
#define HDC302X_ADDRESS1 0x44
#define HDC302X_ADDRESS2 0x45
#define HDC302X_ADDRESS3 0x46
#define HDC302X_ADDRESS4 0x47

#define HDC302X_READDELAY_MS 15
#define HDC302X_RETURNDELAY_MS 1

#include <Arduino.h>
#include <Wire.h>
#include "math.h"

struct HDC302xDataResult
{
    /// @brief Temperature in Celcius, ranging from -45 to 130 degrees
    float Temperature = 0.0f;
    /// @brief Relative Humidity in percentage 0%-100%
    float Humidity = 0.0f;
};

class HDC302x
{
private:
    bool isInitialized = false;
    uint8_t address = HDC302X_ADDRESS1;

    uint16_t HDC302x_hum_MSB;
    uint16_t HDC302x_hum_DEC;
    uint16_t HDC302x_temp_MSB;
    uint16_t HDC302x_temp_DEC;
    uint16_t HDC302x_temp;

    HDC302xDataResult readDataResult;

protected:
    TwoWire *wire;
    uint8_t buffer[4] = {0};

public:
    HDC302x(TwoWire *twoWire = &Wire) 
        : wire(twoWire)
    {
    }
    /// @brief Initialize i2c connection with the sensor
    /// @param address I2C address
    bool Initialize(uint8_t address = HDC302X_ADDRESS1);
    
    /// @brief Reads temperature and humidity
    /// @return HDC302xDataResult struct with temperature and humidity
    HDC302xDataResult ReadData();
};

class HDC3020 : public HDC302x
{
};

#endif