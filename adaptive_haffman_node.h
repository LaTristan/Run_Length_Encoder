#pragma once
#ifndef ADAPTIVE_HAFFMAN_NODE_H
#define ADAPTIVE_HAFFMAN_NODE_H
#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

struct adaptive_haffman_node
{
	int left_or_right = -1;
	int weight = -1;
	int order = 0;
	adaptive_haffman_node *left_child = NULL;
	adaptive_haffman_node *right_child = NULL;
	adaptive_haffman_node *father = NULL;
	bool is_leaf = false;
	bool is_root = false;
	bool is_NYT = false;
	bool used = false;
	unsigned char symbol = 0x00;


	//----create a common node----//
	adaptive_haffman_node()
	{   
		order = 0;
		left_or_right = -1;
		weight = -1;
		left_child = NULL;
		right_child = NULL;
		father = NULL;
		is_leaf = false;
		is_root = false;
		is_NYT = false;
		used = false;
		symbol = 0x00;
	}
};





#endif 
