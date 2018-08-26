#include "stdafx.h"
#include "pre_process.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 

using namespace std;

vector<unsigned char> Pre_Process_Image_restrict(vector<unsigned char> input) 
{
	vector<unsigned char> output;
	for (int i = 0; i < 256; i++) 
	{
		if (i % 2 == 0) 
		{
			for (int j = 0; j < 256; j++) 
			{
				output.push_back(input[i * 256 + j]);
			}
		}
		else 
		{
			for (int j = 0; j < 256; j++)
			{
				output.push_back(input[(i + 1) * 256 - j - 1]);
			}
		}
	}
	cout << "preprocess:"<< output.size() << endl;
	return output;
}








