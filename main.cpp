
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "DIO.h"
#include "MyRio.h"
#include "Ultrasonic.h"

#include <sys/time.h>


int main(int argc, char **argv)
{
    NiFpga_Status status;

    Ultrasonic ultrasonic;

    status = MyRio_Open();
    if (MyRio_IsNotSuccess(status))
    {
        return status;
    }


    int distance;

    while(1) {

        distance = ultrasonic.getDistance();

        printf("Distance = ");
        if (distance >= 400 || distance <= 2){
            printf("Out of range\n");
        } else {
            printf("%d", distance);
            printf(" cm\n");
        }
        usleep(100000);
    }

    status = MyRio_Close();

    
    return status;
}
