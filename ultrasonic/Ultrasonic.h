#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <vector>
#include "DIO.h"
#include "MyRio.h"

class Ultrasonic
{
public: 
   typedef enum{
    	FRONT_LEFT,
    	FRONT_RIGHT
    } Sensor;

	Ultrasonic();
	float getDistance(Sensor sensor);

    typedef struct {
       	NiFpga_Bool dio_B0;
	    NiFpga_Bool dio_B1;

	    MyRio_Dio B0;
	    MyRio_Dio B1;
    }SensorData;

private:

	SensorData sensorData[2] = {
		{
			0, 0,
			{
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				2
			},
			{
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				3
			}
		},
		{
			0, 0,
			{
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				0
			},
			{
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				1
			}
		}
	};
    


};

#endif
