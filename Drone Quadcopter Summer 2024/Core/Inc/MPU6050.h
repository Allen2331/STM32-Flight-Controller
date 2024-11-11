/*
 * MPU6050.h
 *
 *  Created on: Oct 27, 2024
 *      Author: Allen
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stm32f4xx_hal.h" //Used for I2C
#include <cstdint>

//Accelerometer Register Read Addresses 
#define ACCEL_XOUT_H 0X3B // H = First 8 bits
#define ACCEL_XOUT_L 0x3C // L = Last 8 bits
#define ACCEL_YOUT_H 0x3D 
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40

//Gyroscope Register Read Addresses
#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48

#define MPU6050_PWR_MGMT_1_REG 0x6B

#define MPU6050_WHO_AM_I_REG 0x75 //Can only read

#define MPU6050_I2C_ADDR (0x68 << 1) // AD0 pin connected to GND, left shifted to get 7-bit address

typedef struct {
    int16_t gyroXRaw;
    int16_t gyroYRaw;
    int16_t gyroZRaw;
    int16_t accelXRaw;
    int16_t accelYRaw;
    int16_t accelZRaw;
    int16_t tempRaw;
} MPU6050_Raw_Data;

HAL_StatusTypeDef MPU6050_Init (I2C_HandleTypeDef *I2C);

//Data acquisition functions
HAL_StatusTypeDef MPU6050_Read_Accel (I2C_HandleTypeDef *I2C, MPU6050_Raw_Data *accelData, uint16_t numBytes);
HAL_StatusTypeDef MPU6050_Read_Gyro (I2C_HandleTypeDef *I2C, MPU6050_Raw_Data *gyroData, uint16_t numBytes);

#endif /* INC_MPU6050_H_ */
