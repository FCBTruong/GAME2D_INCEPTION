#pragma once
#ifndef HIGH_SCORE_H_
#define HIGH_SCORE_H_

#include "Common_Function.h"
#include <fstream>

void GetHighScore()
{
	std::ifstream f("Images/guide/high/p/highsc.txt");
	while (!f.fail())
	{
		f >> HIGH_SCORE;
	}
}

void SetHighScore()
{
	std::ofstream f("Images/guide/high/p/highsc.txt");
	f << HIGH_SCORE;
	f.close();
}
#endif // !HIGH_SCORE_H_
