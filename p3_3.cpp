#include "stdafx.h"
#include "p3_3.h"
#include <vector>
#include <string>
#include <iostream>  
#include <fstream> 


using namespace std;


double compute_theoretical_bound(vector<data_pair> input,int length) 
{
	double out = 0.0;
	vector<double> set;
	for (int i = 0; i < input.size(); i++) 
	{
		set.push_back((double)input[i].freq / (double)length);
	}
	for (int i = 0; i < input.size(); i++) 
	{
		out += log2(set[i]) * (-1) * (double)input[i].freq;
	}
	out = out / 8;
	return out;
}


void Find_how_many_symbols() 
{
	string file_audio = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\audio.dat";
	string file_binary = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\binary.dat";
	string file_image = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\image.dat";
	string file_text = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\text.dat";
	vector<unsigned char> audio = ReadBinaryFile(file_audio);
	vector<unsigned char> binary = ReadBinaryFile(file_binary);
	vector<unsigned char> image = ReadBinaryFile(file_image);
	vector<unsigned char> text = ReadBinaryFile(file_text);

	//-----------------step#2 transfer four .dat files to pdf-----------------//
	cout << "start sorting..." << endl;
	vector<data_pair> audio_pdf = Sort_Raw_Data(audio);
	cout << "4 left" << endl;
	vector<data_pair> binary_pdf = Sort_Raw_Data(binary);
	cout << "3 left" << endl;
	vector<data_pair> image_pdf = Sort_Raw_Data(image);
	cout << "2 left" << endl;
	vector<data_pair> text_pdf = Sort_Raw_Data(text);
	cout << "1 left" << endl;
	//-----------------audio-----------------//
	cout << "#audio: " << audio_pdf.size() << endl;
	cout << "#binary: " << binary_pdf.size() << endl;
	cout << "#image: " << image_pdf.size() << endl;
	cout << "#text: " << text_pdf.size() << endl;

}


void Find_theoretical_bound() 
{
	string file_audio = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\audio.dat";
	string file_binary = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\binary.dat";
	string file_image = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\image.dat";
	string file_text = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\text.dat";
	vector<unsigned char> audio = ReadBinaryFile(file_audio);
	vector<unsigned char> binary = ReadBinaryFile(file_binary);
	vector<unsigned char> image = ReadBinaryFile(file_image);
	vector<unsigned char> text = ReadBinaryFile(file_text);

	//-----------------step#2 transfer four .dat files to pdf-----------------//
	cout << "start sorting..." << endl;
	vector<data_pair> audio_pdf = Sort_Raw_Data(audio);
	cout << "4 left" << endl;
	vector<data_pair> binary_pdf = Sort_Raw_Data(binary);
	cout << "3 left" << endl;
	vector<data_pair> image_pdf = Sort_Raw_Data(image);
	cout << "2 left" << endl;
	vector<data_pair> text_pdf = Sort_Raw_Data(text);
	cout << "1 left" << endl;
	//-----------------audio-----------------//
	cout << "theoretical_bound_audio: " << compute_theoretical_bound(audio_pdf, audio.size()) << endl;
	cout << "theoretical_bound_binary: " << compute_theoretical_bound(binary_pdf, binary.size()) << endl;
	cout << "theoretical_bound_image: " << compute_theoretical_bound(image_pdf, image.size()) << endl;
	cout << "theoretical_bound_text: " << compute_theoretical_bound(text_pdf, text.size()) << endl;






}

void Find_Optimal_length() 
{
	string file_audio = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\audio.dat";
	string file_binary = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\binary.dat";
	string file_image = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\image.dat";
	string file_text = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\text.dat";
	vector<unsigned char> audio = ReadBinaryFile(file_audio);
	vector<unsigned char> binary = ReadBinaryFile(file_binary);
	vector<unsigned char> image = ReadBinaryFile(file_image);
	vector<unsigned char> text = ReadBinaryFile(file_text);
	
	//-----------------step#2 transfer four .dat files to pdf-----------------//
	cout << "start sorting..." << endl;
	vector<data_pair> audio_pdf = Sort_Raw_Data(audio);
	cout << "4 left" << endl;
	vector<data_pair> binary_pdf = Sort_Raw_Data(binary);
	cout << "3 left" << endl;
	vector<data_pair> image_pdf = Sort_Raw_Data(image);
	cout << "2 left" << endl;
	vector<data_pair> text_pdf = Sort_Raw_Data(text);
	cout << "1 left" << endl;
	
	//-----------------audio-----------------//
	int length_audio = 0;
	for (int i = 0; i < audio_pdf.size(); i++) 
	{
		if (audio_pdf[i].freq <= 255) 
		{
			length_audio +=2;
		}
		else 
		{
			if (audio_pdf[i].freq % 255 == 0) 
			{
				length_audio += (audio_pdf[i].freq / 255) * 2;
			}
			else 
			{
				length_audio += (audio_pdf[i].freq / 255 + 1) * 2;
			}
		}
	}
	//-----------------binary-----------------//
	int length_binary = 0;
	for (int i = 0; i < binary_pdf.size(); i++)
	{
		if (binary_pdf[i].freq <= 255)
		{
			length_binary += 2;
		}
		else
		{
			if (binary_pdf[i].freq % 255 == 0)
			{
				length_binary += (binary_pdf[i].freq / 255)*2;
			}
			else
			{
				length_binary += (binary_pdf[i].freq / 255 + 1)*2;
			}
		}
	}
	//-----------------image-----------------//
	int length_image = 0;
	for (int i = 0; i < image_pdf.size(); i++)
	{
		if (image_pdf[i].freq <= 255)
		{
			length_image += 2;
		}
		else
		{
			if (image_pdf[i].freq % 255 == 0)
			{
				length_image += (image_pdf[i].freq / 255) * 2;
			}
			else
			{
				length_image += (image_pdf[i].freq / 255 + 1) * 2;
			}
		}
	}
	//-----------------text-----------------//
	int length_text = 0;
	for (int i = 0; i < text_pdf.size(); i++)
	{
		if (text_pdf[i].freq <= 255)
		{
			length_text+=2;
		}
		else
		{
			if (text_pdf[i].freq % 255 == 0)
			{
				length_text += (text_pdf[i].freq / 255)*2;
			}
			else
			{
				length_text += (text_pdf[i].freq / 255 + 1)*2;
			}
		}
	}

	cout << "optimal size of audio: " << length_audio << endl;
	cout << "optimal size of binary: " << length_binary << endl;
	cout << "optimal size of image: " << length_image << endl;
	cout << "optimal size of text: " << length_text << endl;

}








void HW1_Problem_three_part_three(void) 
{
	string file_audio = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\audio.dat";
	string file_binary = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\binary.dat";
	string file_image = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\image.dat";
	string file_text = "E:\\MY_LOG\\669\\hw1\\input\\EE669_Fall_2017_HW1_Data_Files\\text.dat";
	vector<unsigned char> audio = ReadBinaryFile(file_audio);
	vector<unsigned char> binary = ReadBinaryFile(file_binary);
	vector<unsigned char> image = ReadBinaryFile(file_image);
	vector<unsigned char> text = ReadBinaryFile(file_text);
	vector<vector<unsigned char>> splitted_data = Split_Data_To_Block(text, 30);
	/*vector<bwt_cell> test = Encode_Block(splitted_data[0]);
	bwt_block_out test_book = Cell_To_Block_Out(test);
	vector<unsigned char> decoded = Decode_Single_Block_2(test_book);
	cout << decoded.size() << endl;
	for (int i = 0; i < 20; i++) 
	{	
			cout << (int)decoded[i] << "  " << (int)splitted_data[0][i] << endl;		
	}*/

	vector<unsigned char> bwt_data;
	for (int i = 0; i < splitted_data.size(); i++) 
	{
		vector<bwt_cell> temp = Encode_Block(splitted_data[i]);
		bwt_block_out temp_book = Cell_To_Block_Out(temp);
		int N = temp_book.code.size();
		for (int i = 0; i < N; i++) 
		{
			bwt_data.push_back(temp_book.code[i]);
		}
		bwt_data.push_back(temp_book.add_index);
		vector<unsigned char> decoded = Decode_Single_Block_2(temp_book);
		bool lp = true;
		for (int j = 0; j < 20; j++) 
		{
			if (splitted_data[i][j] != decoded[j]) 
			{
				lp = false;
			}
		}
		if (lp == true) 
		{
			cout << "pass" << endl;
		}
		else 
		{
			cout << "fail" << endl;
		}
	}
	cout << "BWT done. " << endl;
	cout << "Start improved run_length_coding..." << endl;
	vector<unsigned char> compressed_data = Improved_Run_Length_Encode(bwt_data);
	cout << "size:" << compressed_data.size() << endl;

	unsigned char buffer[99999999];
	int index = 0;
	for (vector<unsigned char>::iterator it = compressed_data.begin(); it != compressed_data.end(); it++)
	{
		buffer[index] = *it;
		index++;
	}
	string path = "E:\\MY_LOG\\669\\hw1\\output\\Renew_text_BWT30_improved_run_length.dat";
	FILE *fp_write = fopen(path.c_str(), "wb");
	if (fp_write == NULL)
	{
		printf("\nFail to create the file.");
	}
	else
	{
		printf("\nScuess to create the file.");
	}
	fwrite(buffer, sizeof(unsigned char), compressed_data.size(), fp_write);
	fclose(fp_write);
	cout << "done: " << path << endl;

}

