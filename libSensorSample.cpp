#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include <cmath>
#include "libSensor.h"
#include<sstream>
#include<string>
using namespace std;


std::string get_acc()
{
    if (wiringPiSetup() == -1){
	printf("\nerror setting up wiringPi\n");
	perror("Init gyro");

	}
       // return -1;

    Sensor gyro;
   // perror("Init gyro");

    int x,y,z;
    x=gyro.getAccelX();
    y=gyro.getAccelY();
    z=gyro.getAccelZ();
    std::ostringstream oss;
    oss<<x<<" "<<y<<" "<<z;
   // std::cout<<"\n   accel X offset = "<< static_cast<int16_t>(gyro.getAccelX_of());
   // std::cout<<"\n   accel Y offset = "<<static_cast<int16_t>(gyro.getAccelY_of());
    //std::cout<<"\n   accel Z offset = "<<static_cast<int16_t>(gyro.getAccelZ_of());
    return oss.str();
    //    printf("x=%d    y=%d    z=%d      ax=%f\n", x, y, z);
}

