#include "Solve_Table.h"
#include <algorithm>

bool Up(int table_algorithm[G_SIZE][G_SIZE], int &score,Object table_obj[G_SIZE][G_SIZE])
{
	bool is = false;
	for (int j = 0; j < G_SIZE; j++)
		for (int i = 0; i < G_SIZE; i++)
		{
			if (table_algorithm[i][j] == 0) continue;
			for (int k = i + 1; k < G_SIZE; k++)
			{
				if (table_algorithm[k][j] == 0) continue;
				if (table_algorithm[k][j] == table_algorithm[i][j])
				{
					table_algorithm[i][j] = 2 * table_algorithm[i][j];
					table_obj[i][j].SetAni(true);
					score += table_algorithm[i][j];
					is = true;
					table_algorithm[k][j] = 0;
					i = k ;
					break;
				}
				else break;
			}
		}

	for (int j = 0; j < G_SIZE; j++)
		for (int i = 0; i < G_SIZE; i++)
		{
			if (table_algorithm[i][j] == 0)
			{
				for (int k = i + 1; k < G_SIZE; k++)
				{
					if (table_algorithm[k][j] != 0)
					{
						is = true;
						bool bw = table_obj[i][j].GetAni();
						table_obj[i][j].SetAni(table_obj[k][j].GetAni());
						table_obj[k][j].SetAni(bw);
						std::swap(table_algorithm[i][j], table_algorithm[k][j]);
						break;
					}
				}
			}
		}
	return is;
}

bool Down(int table_algorithm[G_SIZE][G_SIZE], int &score, Object table_obj[G_SIZE][G_SIZE])
{
	bool is = false;
	for (int j = 0; j < G_SIZE; j++)
		for (int i = G_SIZE - 1; i >= 0; i--)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (table_algorithm[k][j] == 0) continue;
				if (table_algorithm[k][j] == table_algorithm[i][j])
				{
					is = true;
					table_algorithm[i][j] = 2 * table_algorithm[i][j];
					table_obj[i][j].SetAni(true);
					score += table_algorithm[i][j];
					table_algorithm[k][j] = 0;
					i = k;
					break;
				}
				else break;
			}
		}

	for (int j = 0; j < G_SIZE; j++)
		for (int i = G_SIZE - 1; i >= 0; i--)
		{
			if (table_algorithm[i][j] == 0)
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (table_algorithm[k][j] != 0)
					{
						is = true;
						bool bw = table_obj[i][j].GetAni();
						table_obj[i][j].SetAni(table_obj[k][j].GetAni());
						table_obj[k][j].SetAni(bw);
						std::swap(table_algorithm[i][j], table_algorithm[k][j]);
						break;
					}
				}
			}
		}
	return is;
}

bool Left(int table_algorithm[G_SIZE][G_SIZE], int &score, Object table_obj[G_SIZE][G_SIZE])
{
	bool is = false;
	for (int i = 0; i < G_SIZE; i++)
		for (int j = 0; j < G_SIZE; j++)
		{
			for (int k = j + 1; k < G_SIZE; k++)
			{
				if (table_algorithm[i][k] == 0) continue;
				if (table_algorithm[i][j] == table_algorithm[i][k])
				{
					is = true;
					table_algorithm[i][j] *= 2;
					table_obj[i][j].SetAni(true);
					score += table_algorithm[i][j];
					table_algorithm[i][k] = 0;
					break;
				}
				else break;
			}
		}
	for (int i = 0; i < G_SIZE; i++)
		for (int j = 0; j < G_SIZE; j++)
		{
			if (table_algorithm[i][j] == 0)
				for (int k = j + 1; k < G_SIZE; k++)
				{
					if (table_algorithm[i][k] != 0)
					{
						is = true;
						bool bw = table_obj[i][j].GetAni();
						table_obj[i][j].SetAni(table_obj[i][k].GetAni());
						table_obj[i][k].SetAni(bw);
						std::swap(table_algorithm[i][k], table_algorithm[i][j]);
						break;
					}
				}
		}
	return is;
}

bool Right(int table_algorithm[G_SIZE][G_SIZE], int &score, Object table_obj[G_SIZE][G_SIZE])
{
	bool is = false;
	for (int i = 0; i < G_SIZE; i++)
		for (int j = G_SIZE - 1; j >= 0; j--)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (table_algorithm[i][k] == 0) continue;
				if (table_algorithm[i][j] == table_algorithm[i][k])
				{
					is = true;
					table_algorithm[i][j] *= 2;
					table_obj[i][j].SetAni(true);
					score += table_algorithm[i][j];
					table_algorithm[i][k] = 0;
					break;
				}
				else break;
			}
		}

	for (int i = 0; i < G_SIZE; i++)
		for (int j = G_SIZE - 1; j >= 0; j--)
		{
			if (table_algorithm[i][j] == 0)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (table_algorithm[i][k] != 0)
					{
						is = true;
						bool bw = table_obj[i][j].GetAni();
						table_obj[i][j].SetAni(table_obj[i][k].GetAni());
						table_obj[i][k].SetAni(bw);	
						std::swap(table_algorithm[i][k], table_algorithm[i][j]);
						break;
					}
				}
			}
		}
	return is;
}

