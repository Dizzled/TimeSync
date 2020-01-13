# TimeSync.cpp
A C++ exercise in creating time latency function to estimate data set times.
Input requires .csv file with two columns one for sensor and one for processor time. 
The sample ClockSynchronization.csv files needs the .csv to be included with filename
Also ensure that the file is located in the same directory as the project folder

# SimulatedTimeData.py
A Python file to generate a .csv file to generate estimated test data. Saves to selected
directory. 

Makefile:
make all
*Creates executable File run Timesync
make clean
*Cleanes object files and removes executable
