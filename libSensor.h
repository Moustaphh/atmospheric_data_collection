#ifndef DEF_SENSOR
#define DEF_SENSOR
#include<string>
#include <stdint.h>
#include<vector>
class Sensor
{
  public:
    Sensor();
    void initGyro();
    int8_t getGyroX();
    int8_t getGyroY();
    int8_t getGyroZ();
    int8_t getAccelX();
    int8_t getAccelY();
    int8_t getAccelZ();
    
//    int8_t getAccelX_of();
 //   int8_t getAccelY_of();
  //  int8_t getAccelZ_of();

    float getAngleX();
    float getAngleY();
    float getAngleZ();

  private:
    int fd;
    int I2CAddress;

    int8_t x_gyro;
    int8_t y_gyro;
    int8_t z_gyro;

    int8_t x_init_gyro;
    int8_t y_init_gyro;
    int8_t z_init_gyro;

    int8_t x_accel;
    int8_t y_accel;
    int8_t z_accel;
};
std::string get_acc();
std::vector<std::string> format_data(std::string);
//void show_offset();

#endif
