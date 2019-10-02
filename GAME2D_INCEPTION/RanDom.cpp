#include "RanDom.h"

bool Random(int arr[G_SIZE][G_SIZE],int &ani_x, int &ani_y)
{
	std::vector<coordinate> v_coordinates;
	for(int i = 0 ; i < G_SIZE ; i ++)
		for(int j = 0 ; j < G_SIZE ; j ++)
			if (arr[i][j] == 0)
			{
				coordinate c;
				c.x = i;
				c.y = j;
				v_coordinates.push_back(c);
			}
	int v_size = v_coordinates.size();
	if (v_size == 0) return false;
	int is = rand() % v_size;

	int optionValue = rand() % 6;
	arr[v_coordinates.at(is).x][v_coordinates.at(is).y] = option[optionValue];
	ani_x = v_coordinates.at(is).x;
	ani_y = v_coordinates.at(is).y;
	return true;
}