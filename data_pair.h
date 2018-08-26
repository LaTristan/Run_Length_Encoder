#pragma once

#ifndef DATA_PAIR_H
#define DATA_PAIR_H
#include "stdafx.h"
#include <vector>
#include <string>


using namespace std;

struct data_pair
{
	unsigned char index;
	int freq;
	
	data_pair(unsigned char symbol, int f)
	{
		index = symbol;
		freq = f;
	}
};

struct run_length_data 
{
	unsigned char symbol = 0x00;
	bool checked = false;

	run_length_data(unsigned char input)
	{
		symbol = input;
		checked = false;
	}
};



int exist(vector<data_pair> source, unsigned char symbol);
void add_data(vector<data_pair> &source, unsigned char new_data);


#endif 