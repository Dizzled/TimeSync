#pragma once

#include <vector>
#include <string>

using namespace std;

vector<pair<string, vector<float>>> readData(istream&);
void writeData(string,vector<pair<string, vector<float>>>);