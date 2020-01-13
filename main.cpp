// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "EstimateTime.h"
#include "ReadCSV.h"
#include "unitTest.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{

	
  float output = 0;
  Estimate systemTime;
  string dataFileName;
  string outFileName = "outPut.csv";
  vector<pair<string, vector<float>>> dataOutput;
  vector<pair<string, vector<float>>> dataInput;

  if (argc == 2) {
	  dataFileName = argv[1];
  }
  

  cout << "Enter Data Time File: " << endl;
  getline(cin, dataFileName);
  
  fstream dataFile;
  dataFile.open(dataFileName, ios::in);
  // Create an input filestream

  if (!dataFile.is_open()) throw runtime_error("Could not open datafile");
  
  //Open Read then Close File
  dataInput = readData(dataFile);
  dataFile.close();

  int n = dataInput.at(0).second.size();

  dataOutput = dataInput;
  dataOutput.push_back({ "Estimated Time",vector<float>{} });

  /*Parse through vector data to generate estimation*/
  for (int i = 0; i < n; i++) {
      
     output = systemTime.EstimateDataValidSystemTime(dataInput[0].second[i], dataInput[1].second[i]);
     dataOutput[2].second.push_back(output);

  }
 
  writeData(outFileName,dataOutput);
  
  //Unit Test of OutputFile
  testFileDataOut(outFileName);



   return 0;
}



