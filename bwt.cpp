#include "stdafx.h"
#include "bwt.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 



using namespace std;

double Convert_To_Double(vector<unsigned char> in) 
{
	int N = in.size();
	double out = 0;
	for (int i = 0; i < N; i++)
	{
		out += ((int)in[i])*pow(256, N - 1 - i);
	}
	return out;
}


vector<vector<unsigned char>> Split_Data_To_Block(vector<unsigned char> &input, int size) 
{
	vector<vector<unsigned char>> output;
	if (input.size() % size == 0) //正好
	{
		int N = input.size() / size;
		for (int i = 0; i < N; i++) 
		{
			vector<unsigned char> temp;
			for (int j = i * size; j < i * size + size; j++) 
			{
				temp.push_back(input[j]);
			}
			output.push_back(temp);	
		}
	}
	else 
	{
		int N = input.size() / size;
		int difference = size - (input.size() - N * size);
		for (int i = 0; i < difference; i++) 
		{
		
			input.push_back(0x00);
		}
		N = N + 1;
		for (int i = 0; i < N; i++)
		{
			vector<unsigned char> temp;
			for (int j = i * size; j < i * size + size; j++)
			{
				temp.push_back(input[j]);
			}
			output.push_back(temp);
		}
	}
	cout << "Size of block: " << output[0].size() << endl;
	cout << "Size of data: " << output.size() << endl;
	return output;
}

bool Compare_bwt_cell( const bwt_cell a, const bwt_cell b)
{    
	vector<unsigned char> aa = a.data;
	vector<unsigned char> bb = b.data;
	double a_value = Convert_To_Double(aa);
	double b_value = Convert_To_Double(bb);
	return a_value > b_value;
}


bool Compare_Vector(vector<unsigned char> a, vector<unsigned char> b) 
{
	bool out = true;
	int size = a.size();
	for (int i = 0; i < size; i++) 
	{
		if (a[i] != b[i]) 
		{
			out = false;
			break;
		}
	}
	return out;
}




vector<bwt_cell> Encode_Block(vector<unsigned char> input) 
{
	int size = input.size();
	//create cell
	vector<bwt_cell> cell;
	vector<unsigned char> temp;
	for (int i = 0; i < input.size(); i++) 
	{
		temp.push_back(input[i]);
	}
	cell.push_back(bwt_cell(temp, 0));
	for (int i = 0; i < size - 1; i++) //要移动size - 1次
	{   
		//右移一位
		unsigned char last = temp[size - 1];
		for (int j = 0; j < size - 1; j++) 
		{
			temp[size - 1 - j] = temp[size - 2 - j];
		}
		temp[0] = last;
		//创建cell
		cell.push_back(bwt_cell(temp, i + 1));
	}
	/*for (int i = 0; i < cell.size(); i++)
	{
		cout << cell[i].index << "  " << (int)cell[i].last_word << endl;
	}*/

	//cout << "after:" << endl;

	//排序
	sort(cell.begin(), cell.end(), Compare_bwt_cell);
	//寻找第一个索引
	for (int i = 0; i < size; i++) 
	{
		if (Compare_Vector(input, cell[i].data) == true)
		{
			cell[0].add_index = Zero_255_to_U8(i);
		}
	}
	return cell;
}

bwt_block_out Cell_To_Block_Out(vector<bwt_cell> book) 
{
	bwt_block_out output = bwt_block_out();
	int N = book[0].data.size();
	for (int i = 0; i < N; i++) 
	{
		output.code.push_back(book[i].last_word);
		output.index.push_back(book[i].index);
	}
	output.add_index = book[0].add_index;
	return output;
}


vector<unsigned char> Decode_Single_Block_2(bwt_block_out input) 
{   
	int N = input.code.size();
	vector<unsigned char> output;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) //寻找索引位置
		{
			if (input.index[j] == i)
			{
				output.insert(output.begin(),input.code[j]);
			}
		}
	}
	
	return output;
}







vector<unsigned char> Decode_Single_Block(bwt_block_out input) 
{
	int N = input.code.size();
	//准备base列及其排序
	vector<bwt_cell> S1;
	for (int i = 0; i < N; i++) 
	{
		vector<unsigned char> temp;
		temp.push_back(input.code[i]);
		S1.push_back(bwt_cell(temp,i));
	}
	//准备第一个中间列
	vector<bwt_cell> S_sort;
    for (int i = 0; i < N; i++) 
	{
		S_sort.push_back(S1[i]);
	}
	sort(S_sort.begin(), S_sort.end(), Compare_bwt_cell);

	while (S_sort[0].data.size() != N) 
	{
	    //合并生成新的S_sort
		for (int i = 0; i < N; i++) 
		{
			S_sort[i].data.insert(S_sort[i].data.begin(), S1[i].data[0]); //从vector头部加一个元素
		}
		//重新sort
		sort(S_sort.begin(), S_sort.end(), Compare_bwt_cell);
	} // 到此能生成原始数组

	//用该数组和索引恢复数据
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++) //寻找索引位置
	//	{
	//		if (input.index[j] == i)
	//		{
	//			cout << (int)input.code[j] << "  " << (int)S_sort[j].data[N - 1] << endl;
	//		}
	//	}
	//}

	vector<unsigned char> output;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) //寻找索引位置
		{
			if (input.index[j] == i) 
			{
				output.push_back(S_sort[j].data[N - 1]);
			}	
		}
	}
	return output;

}

















