#include "stdafx.h"
#include "run_length_encode.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 

using namespace std;


bool Is_All_Scaned(vector<run_length_data> in) 
{   
	
	bool out = true;
	int i = 0;
	for (vector<run_length_data>::iterator it = in.begin(); it != in.end(); it++)
	{   
		if (it->checked == false) 
		{
			out = false;
			break;
		}
		i++;
	}
	cout << i << endl;
	return out;
}



vector<unsigned char> Run_Length_Encode(vector<unsigned char>data) 
{
	cout << "Run_Length_Encode..." << endl;
//准备一个输出
	vector<unsigned char> output;
//开始遍历
        bool first = true;
		int how_many = 0;
		unsigned char current_symbol = 0x00;
		for (int i = 0; i < data.size(); i++)
		{
			if (i == 0)
			{
				current_symbol = data[0];
				output.push_back(current_symbol);
			}
			else
			{
				if (data[i] == current_symbol && how_many < 254)
				{   
					if (i != data.size() - 1) 
					{
						how_many++;
					}
					else 
					{
						how_many++;
						output.push_back(Zero_255_to_U8(how_many + 1));
					}
				}
				else
				{
					if (i != data.size() - 1) 
					{
						output.push_back(Zero_255_to_U8(how_many + 1));
						current_symbol = data[i];
						output.push_back(current_symbol);
						how_many = 0;
					}
					else 
					{
						output.push_back(Zero_255_to_U8(how_many + 1));
						current_symbol = data[i];
						output.push_back(current_symbol);;
						output.push_back(0x01);
					}
					
				}
				
			}
		}
		cout << output.size() << endl;
	return output;
}

vector<unsigned char>Run_Length_Decode(vector<unsigned char> compressed_data) 
{   
	cout << "Run_Length_Decode..." << endl;
	cout << compressed_data.size() << endl;
	vector<unsigned char> out;
	int index = 0;
	unsigned char current = 0x00;
	for (vector<unsigned char>::iterator it = compressed_data.begin(); it != compressed_data.end(); it++)
	{   
		if (index % 2 == 0) //是symbol
		{
			current = *it;
		}
		else 
		{   
			
			int how_many = U8_to_0_255(*it);
			for (int i = 0; i < how_many; i++) 
			{
				out.push_back(current);
			}
		}
		index++;
	}
	return out;
}

void Check(vector<unsigned char> a, vector<unsigned char> b) 
{   
	cout << "Checking..." << endl;
	bool pass = true;
	if (a.size() != b.size()) 
	{
		cout << "Error: Different Size." << endl;
		cout << a.size() << " " << b.size() << endl;
		pass = false;
	}
	else 
	{
		for (int i = 0; i < a.size(); i++) 
		{
			if (a[i] != b[i]) 
			{
				cout << "Error: Does not match." << endl;
				pass = false;
			}
		}
	}
	if (pass == true) 
	{
	
		cout << "Pass." << endl;
	}
}


unsigned char Find_New_Symbol(vector<run_length_data> &input) 
{   
	unsigned char out = 0x00;
	for (vector<run_length_data>::iterator it = input.begin(); it != input.end(); it++)
	{
		if (it->checked == false) 
		{   
			out = it->symbol;
			it->checked = true;
			break;
		}	
	}
	return out;
}


vector<unsigned char> Improved_Run_Length_Encode(vector<unsigned char>data) 
{   
	cout << "Improve_Run_Length_Encode..." << endl;
	//把数据分割成一个个块
	vector<vector<unsigned char>> restructed_data;
	vector<unsigned char> temp;
	unsigned char current_symbol = data[0];
	temp.push_back(current_symbol);

	for (int i = 1; i < data.size(); i++) 
	{
		if (data[i] != current_symbol) 
		{
			if (i != data.size() - 1) 
			{
				restructed_data.push_back(temp);
				temp.clear();
				current_symbol = data[i];
				temp.push_back(current_symbol);
			}
			else 
			{
				restructed_data.push_back(temp);
				temp.clear();
				current_symbol = data[i];
				temp.push_back(current_symbol);
				restructed_data.push_back(temp);
			}
		}
		else 
		{
			if (temp.size() != 127) 
			{
				if (i != data.size() - 1) 
				{
					temp.push_back(data[i]);
				}
				else 
				{
					temp.push_back(data[i]);
					restructed_data.push_back(temp);
				}
				
			}
			else 
			{ 
				if (i != data.size() - 1) 
				{
					restructed_data.push_back(temp);
					temp.clear();
					temp.push_back(data[i]);
				}
				else 
				{
					restructed_data.push_back(temp);
					temp.clear();
					temp.push_back(data[i]);
					restructed_data.push_back(temp);			
				}
			}
		}
	}
	//利用分割的数据去重建data
	vector<unsigned char> output;
	for (int i = 0; i < restructed_data.size(); i++) 
	{
		if (restructed_data[i].size() == 1) 
		{
			if (restructed_data[i][0] < 128) 
			{
				output.push_back(restructed_data[i][0]);
			}
			else 
			{
				output.push_back(0x81);
				output.push_back(restructed_data[i][0]);
			}	
		}
		else 
		{   
			int number = 128 + restructed_data[i].size();
			output.push_back(Zero_255_to_U8(number));
			output.push_back(restructed_data[i][0]);
		}
	}
	cout << output.size() << endl;
	return output;
}


vector<unsigned char> Improved_Run_Length_Decode(vector<unsigned char>data) 
{   
	vector<unsigned char> output;
	for (int i = 0; i < data.size(); i++) 
	{
		if (data[i] < 0x80) 
		{
			output.push_back(data[i]);
		}
		else 
		{
			int number = U8_to_0_255(data[i] - 0x80);
			unsigned char temp = data[i + 1];
			for (int i = 0; i < number; i++) 
			{
				output.push_back(temp);
			}
			i++;
		}
	}
	return output;
}



