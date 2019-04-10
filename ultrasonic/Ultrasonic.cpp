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


/*
 * Return distance in cm from ultrasonic sensor
 * If measurement is out of range or invalid it return -1
 */
float Ultrasonic::getDistance(Sensor sensor){

    int duration;
    float distance;

    struct timeval t1;
    struct timeval t2;

    //make sure trigger is low
    sensorData[sensor].dio_TRIGGER = 0;
    Dio_WriteBit(&(sensorData[sensor].TRIGGER), sensorData[sensor].dio_TRIGGER);
    usleep(2);

    //send 10 microsecond pulse to trigger
    sensorData[sensor].dio_TRIGGER = 1;
    Dio_WriteBit(&(sensorData[sensor].TRIGGER), sensorData[sensor].dio_TRIGGER);
    usleep(10);
    sensorData[sensor].dio_TRIGGER = 0;
    Dio_WriteBit(&(sensorData[sensor].TRIGGER), sensorData[sensor].dio_TRIGGER);

    //wait for echo pulse to go high
    while(Dio_ReadBit(&(sensorData[sensor].ECHO)) == 0){

        //check for usec overflow
        gettimeofday(&t1, NULL);
        if(t1.tv_usec > 999990){
            printf("Invalid 1");
            fflush(stdout);
            return -1;
        }
    }


    gettimeofday(&t1, NULL);

    //wait for echo pulse to go low
    while(Dio_ReadBit(&(sensorData[sensor].ECHO)) != 0){

        //check for usec overflow
        gettimeofday(&t2, NULL);
        if(t2.tv_usec > 999990){
            printf("Invalid 2");
            fflush(stdout);
            return -1;
        }
    }

    gettimeofday(&t2, NULL);

    duration = t2.tv_usec-t1.tv_usec;
    distance = (duration / 2) * 0.0343;

    if(distance > MAX_DISTANCE || distance < MIN_DISTANCE){
        return -1;
    }

    usleep(500);

    return distance;
}