#include "EstimateTime.h"

float Estimate::EstimateDataValidSystemTime(float dataValidSensor, float dataReceiveSystem)
{

	systemReceiveTime = dataReceiveSystem;
	sensorValidTime = dataValidSensor;
	
	float difference = 0;
	//Check previous stored value for data receive
	//If not previous value store value for next check
	if (!dataReceiveSystem) {
		cout << "No Valid Time Received" << endl;
	}

	//If the stored temp time is equal to the current time
	//Save the current time into vector array to improve estimation
	//If only 1 value stored in vector then time estimation should only be standard sensor time inverval
	timeStamp.push_back(systemReceiveTime); //Store the temporary receive time in vector to be used

	if (timeStamp.size() <= 1) {
		
		estimate = systemReceiveTime + DATAINTERVAL; //No Data to base future off of use standard 2.0 interval period;
	}
	else if(timeStamp.size() > 1) {

		//Start with the last value and work backwards adding the differences 
		for (int i = timeStamp.size() - 1; i > 0; i--) {
			
			difference += (timeStamp[i] - timeStamp[i - 1]);

		}
		average = difference / timeStamp.size();
		//If the average becomes greater than constant update
		//Use the constant .02 second interval at which Dataseems to be valid
		//In reviewing the data when using a history of averages this is where the
		//largest discrepancies in timing occured
		if (average > 0.02 || average < -0.02) {
			
			estimate = systemReceiveTime + DATAINTERVAL;
		}
		else {
			estimate = systemReceiveTime + average;
		}		
	}
	printf("Estimated Time %f \n", estimate);
	return estimate;

}
