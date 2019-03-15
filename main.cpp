
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "DIO.h"
#include "MyRio.h"
#include "string"

#include <sys/time.h>

#include "Ultrasonic.h"


void printDistance(char* msg, int distance);


int main(int argc, char **argv)
{
    NiFpga_Status status;

    Ultrasonic ultrasonic;

    status = MyRio_Open();
    if (MyRio_IsNotSuccess(status))
    {
        return status;
    }

    printf("Starting");
    fflush(stdout);

    int distance;

    while(1) {

        distance = ultrasonic.getDistance(Ultrasonic::FRONT_RIGHT);

        printDistance((char *)"Right distance = ", distance);

        distance = ultrasonic.getDistance(Ultrasonic::FRONT_LEFT);

        printDistance((char *)"Left distance = ", distance);

        usleep(100000);
    }

    status = MyRio_Close();

    
    return status;
}

void printDistance(char* msg, int distance){
    printf(msg);
    if (distance >= 400 || distance <= 2){
        printf("Out of range\n");
    } else {
        printf("%d", distance);
        printf(" cm\n");
    }
    fflush(stdout);
}
