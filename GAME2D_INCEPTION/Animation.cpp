#include "Animation.h"

Animation::Animation()
{
/*	for (int i = 0; i < 4; i++)
	{
		list_[i].SetRect(0,0,60 + i * 10, 60 + i * 10);
	}
	list_[4].SetRect(0, 0, 94, 94); */
}

Animation::~Animation()
{
	for (int i = 0; i < 14; i++)
	{
		list_[i].Delete();
	}
}

void Animation::Show(SDL_Surface * des, const int &x)
{
	list_[x].Show(des);
}

void Animation::LoadImg(const int &x)
{
	std::string  s= "Images/animation/_abc.png";
	std::string m;
	s.insert(16, IntStr(x));
	s.insert(17 + IntStr(x).length(), IntStr(x));
	m = s;
	for (int i = 0; i < 14; i++)
		{
		    m.insert(18 + IntStr(x).length() * 2, IntStr(i));
			list_[i].LoadImg(m);
			m = s;
		}
}

void Animation::SetRectXY(const int &x, const int &y)
{
	list_[0].SetRectXY(x + 25, y + 25);
	list_[1].SetRectXY(x + 22, y + 22);
	list_[2].SetRectXY(x + 20, y + 20);
	list_[3].SetRectXY(x + 17, y + 17);
	list_[4].SetRectXY(x + 15, y + 15);
	list_[5].SetRectXY(x + 12, y + 12);
	list_[6].SetRectXY(x + 10, y + 10);
	list_[7].SetRectXY(x + 7, y + 7);
	list_[8].SetRectXY(x + 5, y + 5);
	list_[9].SetRectXY(x + 2, y + 2);
	list_[10].SetRectXY(x + 0, y + 0);
	list_[11].SetRectXY(x - 2, y - 2);
	list_[12].SetRectXY(x - 4, y - 4);
	list_[13].SetRectXY(x - 6, y - 6);
}
void Animation::Delete()
{
	for (int i = 0; i < 14; i++)
	{
		list_[i].Delete();
	}
}