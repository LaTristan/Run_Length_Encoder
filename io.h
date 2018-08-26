#pragma once
#ifndef IO_H
#define IO_H
#include "stdafx.h"
#include "convert_data_brutal.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 

using namespace std;

vector<unsigned char> ReadBinaryFile(string File_path);
void Write_String_To_Dat(string input, string path);

#endif // !IO_H