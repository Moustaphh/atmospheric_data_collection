
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "libSensor.h"
#include <stdio.h>
#include <cmath>
#include<sstream>
#define MPU6050_GYRO_XOUT_H        0x43   // R
#define MPU6050_GYRO_YOUT_H        0x45   // R
#define MPU6050_GYRO_ZOUT_H        0x47   // R

#define MPU6050_ACCEL_XOUT_H       0x3B   // R
#define MPU6050_ACCEL_YOUT_H       0x3D   // R
#define MPU6050_ACCEL_ZOUT_H       0x3F   // R

#define MPU6050_PWR_MGMT_1         0x6B   // R/W
#define MPU6050_I2C_ADDRESS        0x68   // I2C


/*#define MPU9250_RA_XA_OFFS_H        0x77 //[15:0] XA_OFFS
#define MPU9250_RA_XA_OFFS_L_TC     0x78
#define MPU9250_RA_YA_OFFS_H        0x7A //[15:0] YA_OFFS
#define MPU9250_RA_YA_OFFS_L_TC     0x7B
#define MPU9250_RA_ZA_OFFS_H        0x7D //[15:0] ZA_OFFS
#define MPU9250_RA_ZA_OFFS_L_TC     0x7E
*/




Sensor::Sensor()
{
    fd = wiringPiI2CSetup(MPU6050_I2C_ADDRESS);
    if (fd == -1)
        return;

    wiringPiI2CReadReg8 (fd, MPU6050_PWR_MGMT_1);
    wiringPiI2CWriteReg16(fd, MPU6050_PWR_MGMT_1, 0);
}

int8_t Sensor::getGyroX()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU6050_GYRO_XOUT_H);
}

int8_t Sensor::getGyroY()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU6050_GYRO_YOUT_H);
}

int8_t Sensor::getGyroZ()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU6050_GYRO_ZOUT_H);
}

int8_t Sensor::getAccelX()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU6050_ACCEL_XOUT_H);
}

int8_t Sensor::getAccelY()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU6050_ACCEL_YOUT_H);
}

int8_t Sensor::getAccelZ()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU6050_ACCEL_ZOUT_H);
}

/*int8_t Sensor::getAccelX_of()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU9250_RA_XA_OFFS_H );
}
int8_t Sensor::getAccelY_of()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU9250_RA_YA_OFFS_H );
}
int8_t Sensor::getAccelZ_of()
{
    return (int8_t) wiringPiI2CReadReg8(fd, MPU9250_RA_ZA_OFFS_H );
}

*/



float Sensor::getAngleX()
{
    int x = getAccelX();
    int y = getAccelY();
    int z = getAccelZ();
    float ax = atan(x/(sqrt(y*y+z*z)))* 180/M_PI;
    return ax;
}

float Sensor::getAngleY()
{
    int x = getAccelX();
    int y = getAccelY();
    int z = getAccelZ();
    float ay = atan(y/(sqrt(x*x+z*z)))* 180/M_PI;
    return ay;
}

float Sensor::getAngleZ()
{
    int x = getAccelX();
    int y = getAccelY();
    int z = getAccelZ();
    float az = atan((sqrt(y*y+x*x))/z)* 180/M_PI;
    return az;
}


std::vector<std::string> format_data(std::string str){

 std::vector<std::string> out;

 std::stringstream ss;
 ss<<str;
 
    std::string s;
    while (std::getline(ss, s, ' ')) {
        out.push_back(s);
    }
	return out;
}
