#pragma once
#ifndef SHANNON_H
#define SHANNON_H
#include "stdafx.h"
#include <vector>
#include <string>
#include "data_pair.h"


using namespace std;

vector<data_pair> Sort_Raw_Data(vector<unsigned char> raw_data);
vector<data_pair> Sort_Raw_Data_Symbol(vector<unsigned char> raw_data);

#endif // !IO_H