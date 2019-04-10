#ifndef ULTRASONIC_H
#define ULTRASONIC_H


class Ultrasonic
{
public: 
   typedef enum{
    	FRONT_LEFT,
    	FRONT_RIGHT
    } Sensor;

	static constexpr double MAX_DISTANCE = 400;
	static constexpr double MIN_DISTANCE = 2;

	Ultrasonic();
	float getDistance(Sensor sensor);

private:
    typedef struct {
       	NiFpga_Bool dio_TRIGGER;
	    NiFpga_Bool dio_ECHO;

	    MyRio_Dio TRIGGER;
	    MyRio_Dio ECHO;
    }SensorData;

	SensorData sensorData[2] = {
		{
			0, 0,
			{
				//PORT B PIN 2
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				2
			},
			{
				//PORT B PIN 3
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				3
			}
		},
		{
			0, 0,
			{
				//PORT B PIN 0
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				0
			},
			{
				//PORT B PIN 1
				DIOB_70DIR,
				DIOB_70OUT,
				DIOB_70IN,
				1
			}
		}
	};
    


};

#endif
