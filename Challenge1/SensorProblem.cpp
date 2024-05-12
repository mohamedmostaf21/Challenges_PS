//Problem
// PS
// 
//  {23, 45, 12, 56, 34}
// Min & Max
// 
// O(1)
// 
// 
//   
// 
// 
// 
// 
// Embedded
//By compleixty O(1) how to get the min and max value from a set of values
//in sensor to make analysis.
//if we have sensor readings {23, 45, 12, 56, 34}
//the sensor has min value that can senes -40, and max value 150










#include <stdio.h>
//first we create a struct calles sensor redaing has one variable 
typedef struct {
	int value;
}SensorReading;

//make another struct called sensor has sensor info.
typedef struct {
	SensorReading readings;
	int num_readings;
	int max_readings;
	int min_readings;
}Sensor;

//API to init Sesnor
void InitSensor(Sensor* sensor) {
	sensor->num_readings = 0;
	sensor->max_readings = -40;
	sensor->min_readings = 150;
}

//API to update the min&max values
void updateMinMax(Sensor* sensor, int newVaule) {
	if (newVaule > sensor->max_readings) {
		sensor->max_readings = newVaule;
	}
	else if(newVaule < sensor->min_readings) {
		sensor->min_readings = newVaule;
	}
	sensor->num_readings++;
}
//demo
int main() {
	Sensor sensor1;
	//init sensor
	InitSensor(&sensor1);
	//Upate sensor values
	updateMinMax(&sensor1, 23);	
	updateMinMax(&sensor1, 45);
	updateMinMax(&sensor1, 12);
	updateMinMax(&sensor1, 56);
	updateMinMax(&sensor1, 34);


	printf("Min Value = %d\n", sensor1.min_readings);
	printf("Max Value = %d\n", sensor1.max_readings);

	return 0;
}