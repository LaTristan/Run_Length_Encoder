#include "stdafx.h"
#include "io.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 


using namespace std;

// data must smaller than 10MB
vector<unsigned char> ReadBinaryFile(string File_path) 
{   
	vector<unsigned char> output;
	unsigned char buffer[9999999];
	//find the length of the file.
	ifstream in;           //ifstream读文件（ofstream写文件）  
	int length;
	in.open(File_path, ios_base::binary);      // open input file  
	in.seekg(0, std::ios::end);    // go to the end  
	length = in.tellg();           // report location (this is the length)  
	in.seekg(0, std::ios::beg);    // go back to the beginning  
	in.close();
	//read the data to vector
	FILE *fp_read = fopen(File_path.c_str(), "rb");
	if (fp_read == NULL)
	{
		printf("\nFail to find the file.");
	}
	fread(buffer, sizeof(unsigned char), length, fp_read);
	fclose(fp_read);
	for (int i = 0; i < length; i++) 
	{   
		//cout << (int)buffer[i] << endl;
		output.push_back(buffer[i]);
	}
	cout << "File size (Byte) is: " << length << endl;
	return output;
}


int String_To_Integer_0_1(string zero_or_one) 
{
	if (zero_or_one == "0") 
	{
		return 0;
	}
	else  
	{
		return 1;
	}
}



void Write_String_To_Dat(string input,string path) 
{   
	unsigned char buffer[99999999];
	int index = 0;
	int dat_length = input.size() / 8;
	if (dat_length * 8 != input.size()) 
	{
		int c = (dat_length + 1) * 8 - input.size();
		for (int i = 0; i < c; i++) 
		{
			input += "0";
		}
		dat_length++;
	}
	for (int i = 0; i < dat_length; i++) 
	{   
		int dice[8];
		for (int j = 0 + 8 * i; j < 8 + 8 * i; j++) 
		{
			dice[j - 8 * i] = String_To_Integer_0_1(input.substr(j,1));
		}
		int temp = 128 * dice[0] + 64 * dice[1] + 32 * dice[2] + 16 * dice[3] + 8 * dice[4] + 4 * dice[5] + 2 * dice[6] + dice[7];
		buffer[index] = Zero_255_to_U8(temp);
		index++;
	}
	FILE *fp_write = fopen(path.c_str(), "wb");
	if (fp_write == NULL)
	{
		printf("\nFail to create the file.");
	}
	else
	{
		printf("\nScuess to create the file.");
	}
	fwrite(buffer, sizeof(unsigned char), dat_length, fp_write);
	fclose(fp_write);
	cout << "done: " << path << endl;
}








