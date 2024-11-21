/*
 * BMP280.h
 *
 *  Created on: Nov 13, 2024
 *      Author: Allen
 */

#ifndef INC_BMP280_H_
#define INC_BMP280_H_

#include "stm32f4xx_hal.h" //Used for I2C
#include <cstdint>

#define BMP280_I2C_ADDR (0x76 << 1)

//Temperature Registers
#define BMP280_TEMP_XLSB 0xFC
#define BMP280_TEMP_LSB 0xFB
#define BMP280_TEMP_MSB 0xFA

//Pressure Registers 
#define BMP280_PRESS_LSB 0xF8
#define BMP280_PRESS_MSB 0xF7

#define BMP280_CONFIG 0xF5
#define BMP280_STATUS 0xF3
#define BMP280_RST 0xE0

typedef struct {
    int16_t pressureLSB;
    int16_t pressureMSB;
    int16_t pressureXLSB;
} BMP280_PRESSURE_READINGS;

typedef struct {
    int16_t tempLSB;
    int16_t tempMSB;
    int16_t tempXLSB;
} BMP280_TEMP_READINGS;

HAL_StatusTypeDef BMP280_INIT(I2C_HandleTypeDef *I2C); //initialize

HAL_StatusTypeDef BMP280_READ_TEMP(I2C_HandleTypeDef *I2C, float* temp);
HAL_StatusTypeDef BMP280_READ_PRESSURE(I2C_HandleTypeDef *I2C, float* pressure);


#endif /* INC_BMP280_H_ */
