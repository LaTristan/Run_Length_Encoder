#pragma once
#ifndef BWT_H
#define BWT_H
#include "stdafx.h"
#include "io.h"
#include "algorithm"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 


using namespace std;

struct bwt_cell 
{
	vector<unsigned char> data;
	int index;
	unsigned char last_word;
	unsigned char add_index;

	bwt_cell(vector<unsigned char>input, int index_in) 
	{
		for (int i = 0; i < input.size(); i++) 
		{
			data.push_back(input[i]);
		}
		index = index_in;
		last_word = data[data.size() - 1];
		add_index = 0x00;
	}
};

struct bwt_block_out 
{
	vector<unsigned char> code;
	vector<int> index;
	unsigned char add_index = 0x00;
	bwt_block_out() 
	{
		code.clear();
		index.clear();
	}

};








vector<vector<unsigned char>> Split_Data_To_Block(vector<unsigned char> &input, int size);
vector<bwt_cell> Encode_Block(vector<unsigned char> input);
bwt_block_out Cell_To_Block_Out(vector<bwt_cell> book);
vector<unsigned char> Decode_Single_Block(bwt_block_out input);
vector<unsigned char> Decode_Single_Block_2(bwt_block_out input);




#endif 
