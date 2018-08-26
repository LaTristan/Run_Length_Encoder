#include "stdafx.h"
#include "data_pair.h"
#include <vector>

using namespace std;

//********************** return -1 if not found; return pos if found **********************//
int exist(vector<data_pair> source, unsigned char symbol)
{
	int out = -1;
	int index = 0;
	for (vector<data_pair>::iterator it = source.begin(); it != source.end(); it++)
	{
		if (it->index == symbol)
		{
			out = index;
			return out;
		}
		index++;
	}
	return out;
}

void add_data(vector<data_pair> &source, unsigned char new_data)
{
	int pos = exist(source, new_data);
	if (pos != -1)
	{
		source[pos].freq++;
	}
	else
	{
		source.push_back(data_pair(new_data, 1));
	}
}
