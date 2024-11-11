#include <MPU6050.h>

I2C_HandleTypeDef hi2c1;

HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *I2C){
    uint8_t check, data;
    if (HAL_I2C_Mem_Read(I2C, MPU6050_I2C_ADDR, MPU6050_WHO_AM_I_REG, I2C_MEMADD_SIZE_8BIT, &check, 1, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }
    if (check != 0x68) {
        return HAL_ERROR;
    }
}

HAL_StatusTypeDef MPU6050_Read_Accel (I2C_HandleTypeDef *I2C, MPU6050_Raw_Data *accelData, uint16_t numBytes) {
    uint8_t rawData[6];
    accelData->accelXRaw = (int16_t)(rawData[0] << 8 | rawData[1]);
    accelData->accelYRaw = (int16_t)(rawData[2] << 8 | rawData[3]);
    accelData->accelZRaw = (int16_t)(rawData[4] << 8 | rawData[5]);

    
}

HAL_StatusTypeDef MPU6050_Read_Gyro (I2C_HandleTypeDef *I2C, MPU6050_Raw_Data *gyroData, uint16_t numBytes) {
    uint8_t rawData[6];
    gyroData->gyroXRaw = (int16_t)(rawData[0] << 8 | rawData[1]);
    gyroData->gyroYRaw = (int16_t)(rawData[2] << 8 | rawData[3]);
    gyroData->gyroZRaw = (int16_t)(rawData[4] << 8 | rawData[5]);
}
