
#include "ReadCSV.h"
#include <string>
#include <fstream>
#include <vector>
#include <utility> // pair
#include <stdexcept> // runtime_error
#include <sstream> // stringstream

/*****************************Read Data*************************************************
*Description: Read Data stores a .csv file into pairs of values to be used for later.
*Input: Takes the filename in the same directory in .csv format
*Output: Places data from columns and headers and creates a token pair for the values 
****************************************************************************************/

vector<pair<string, vector<float>>> readData(istream & dataFile) {
    // Reads a CSV file into a vector of <string, vector<float>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    vector<pair<string, vector<float>>> result;
 
    // Helper vars
    string line, colname;
    float val;

    // Read the column names
    if (dataFile.good())
    {
        // Extract the first line in the file
        getline(dataFile, line);

        // Create a stringstream from line
        stringstream ss(line);

        // Extract each column name
        while (getline(ss, colname, ',')) {

            // Initialize and add <colname, int vector> pairs to result
            result.push_back({colname, vector<float> {} });
        }
    }

    // Read data, line by line
    while (getline(dataFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each integer
        while (ss >> val) {

            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',') ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }
    return result;
}



/*****************************Write Data*************************************************
*Description: Write Data stores a .csv file into pairs of values to be used for later. Closes
* the file upon completion and is called in main.
*Input: Takes the filename in the same directory in .csv format
*Output: Places data from columns and headers and creates a token pair for the values
****************************************************************************************/
void writeData(string outPutFile,vector<pair<string, vector<float>>>estimateData)
{
    vector<pair<string, vector<float>>>estCopy = estimateData;
    
    fstream outFile;
    outFile.open(outPutFile, std::ios::out | std::ios::app);

    if (!outFile.is_open()) throw runtime_error("Could not open datafile");
    
    int k = 0, m = 0, p = 0;
    while (k < estCopy.size()) {
        
        outFile << estCopy.at(k).first;
        if (k != estCopy.size() - 1) {
            outFile << ",";
        }
        k++;
    }
    outFile << "\n";
    //Send output to stream
    while (m < estCopy.at(0).second.size()) {
        
        while (p < estCopy.size()) {
            
            outFile << estCopy.at(p).second.at(m);
            if (p != estCopy.size() - 1) {
                outFile << ",";
            }
            p++;
        }
        p = 0;
        outFile << "\n";
        m++;
    }
    outFile.close();

}