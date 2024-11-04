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
#define GYRO_XOUT_H = 0x43
#define GYRO_XOUT_L = 0x44
#define GYRO_YOUT_H = 0x45
#define GYRO_YOUT_L = 0x46
#define GYRO_ZOUT_H = 0x47
#define GYRO_ZOUT_L = 0x48

#define MPU6050_I2C_ADDR (0x68 << 1) // AD0 pin connected to GND, may NOT need to left shift

#endif /* INC_MPU6050_H_ */
