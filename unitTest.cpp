#include "unitTest.h"


//Unit Test 1 Check Output File has the correct Column Structures

void testFileDataOut(string fileNameOut) {
    // Read the column names
    float val;
    bool flag = false;
    string line, column;
    fstream checkFile;
    checkFile.open(fileNameOut, ios::in);

    if (checkFile.good())
    {
        // Extract the first line in the file
        getline(checkFile, line);

        // Create a stringstream from line
        stringstream ss(line);

        while (getline(checkFile, line))
        {
            // Create a stringstream of the current line
            stringstream ss(line);

            // Keep track of the current column index
            int colIdx = 0;

            // Extract each integer
            while (ss >> val) {

                // If the next token is a comma, ignore it and move on
                if (ss.peek() == ',') ss.ignore();

                // Increment the column index
                colIdx++;
            }
            if (colIdx == 3) {
                flag = true;
                break;
            }
        }
        assert(flag == true);
        cout << "Exectuted File Written Correctly" << endl;
       
    }

    checkFile.close();
}