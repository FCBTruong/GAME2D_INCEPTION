#pragma once
#ifndef RANDOM_H_
#define RANDOM_H_
	
#include "Common_Function.h"
#include <ctime>	
#include <vector>

bool Random(int arr[G_SIZE][G_SIZE], int &ani_x, int &ani_y);

struct coordinate
{
	int x;
	int y;
};

#endif // !RANDOM_H_
