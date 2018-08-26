#pragma once
#ifndef RUN_LENGTH_ENCODE_H
#define RUN_LENGTH_ENCODE_H
#include "stdafx.h"
#include "io.h"
#include "data_pair.h"
#include "adaptive_haffman_node.h"
#include "convert_data_brutal.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 


using namespace std;

vector<unsigned char> Run_Length_Encode(vector<unsigned char>data);
vector<unsigned char> Improved_Run_Length_Encode(vector<unsigned char>data);
vector<unsigned char> Run_Length_Decode(vector<unsigned char> compressed_data);
vector<unsigned char> Improved_Run_Length_Decode(vector<unsigned char>data);
void Check(vector<unsigned char> a, vector<unsigned char> b);


#endif 
