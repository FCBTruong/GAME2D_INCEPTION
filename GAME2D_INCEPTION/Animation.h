#ifndef ANIMATION_H
#define ANIMATION_H

#include "Common_Function.h"
#include "Object.h"
#include "String_Processing.h"

class Animation
{
public:
	Animation();
	~Animation();
	void Show(SDL_Surface * des, const int &x);
	void LoadImg(const int &x);
	void SetRectXY(const int &x, const int &y);
	void Delete();
	//Object get() const { return list_[0]; }
private:
	Object list_[14];
};

#endif // !ANIMATION_h
