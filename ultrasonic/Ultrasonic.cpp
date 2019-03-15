#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <vector>

#include "DIO.h"
#include "MyRio.h"

#include "Ultrasonic.h"

using namespace std;



Ultrasonic::Ultrasonic(){



}



int Ultrasonic::getDistance(Sensor sensor){

    int duration;
    int distance;

    struct timeval t1;
    struct timeval t2;


        sensorData[sensor].dio_B0 = 0;
        Dio_WriteBit(&(sensorData[sensor].B0), sensorData[sensor].dio_B0);
        usleep(2);
        sensorData[sensor].dio_B0 = 1;
        Dio_WriteBit(&(sensorData[sensor].B0), sensorData[sensor].dio_B0);
        usleep(10);
        sensorData[sensor].dio_B0 = 0;
        Dio_WriteBit(&(sensorData[sensor].B0), sensorData[sensor].dio_B0);


        while(Dio_ReadBit(&(sensorData[sensor].B1)) == 0);
        gettimeofday(&t1, NULL);
        while(Dio_ReadBit(&(sensorData[sensor].B1)) != 0);
        gettimeofday(&t2, NULL);

        duration = t2.tv_usec-t1.tv_usec;
        distance = (duration / 2) * 0.0343;

    return distance;
}