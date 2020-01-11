#pragma once
#include <vector>
#include <string>
#include <vector>
#include <iostream>
#define DATAINTERVAL 0.02 //Sensor Interval Always seems to be 2.0


using namespace std;


class Estimate
{
public:
	float EstimateDataValidSystemTime(float dataValidSensor, float dataReceiveSystem); //Function to Estimate Time
	float tempTime = 0;
	float average = 0;
	float systemReceiveTime;
	float sensorValidTime;

private:

	int count = 0, target = 0;
	float estimate = 0, firstTerm = 0;
	vector<float> timeStamp;


};
