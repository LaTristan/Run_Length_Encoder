#include "stdafx.h"
#include "shannon.h"
#include <vector>
#include "data_pair.h"
#include "algorithm"
#include <iostream>  


using namespace std;

bool Compare_Data_Pair(const data_pair a, data_pair b)
{
	return a.freq > b.freq;
}

bool Compare_Data_Pair_Symbol(const data_pair a, data_pair b)
{
	return (int)a.index > (int)b.index;
}

vector<data_pair> Sort_Raw_Data(vector<unsigned char> raw_data) 
{   
	vector<data_pair> output;
	//transfer the raw data set to symbol-freq "map"//
	for (vector<unsigned char>::iterator it = raw_data.begin(); it != raw_data.end(); it++)
	{
		add_data(output, *it);
	}
	int k = 0;
	/*for (int i = 0; i < output.size(); i++) 
	{
		k += output[i].freq;
	}
	cout << "K: " << k << endl;*/
	sort(output.begin(), output.end(), Compare_Data_Pair);
	return output;
}

vector<data_pair> Sort_Raw_Data_Symbol(vector<unsigned char> raw_data)
{
	vector<data_pair> output;
	//transfer the raw data set to symbol-freq "map"//
	for (vector<unsigned char>::iterator it = raw_data.begin(); it != raw_data.end(); it++)
	{
		add_data(output, *it);
	}
	sort(output.begin(), output.end(), Compare_Data_Pair_Symbol);
	return output;
}







