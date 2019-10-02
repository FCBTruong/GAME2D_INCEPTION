#pragma once
#ifndef OBJECT_H_
#define OBJECT_H_

#include "Common_Function.h"

class Object
{
public:
	Object();
	~Object();

	SDL_Surface* Getobject() const { return object_; };
	bool LoadImg(const std::string file_name);
	void Show(SDL_Surface * des);
	
	void SetRect(const int &x, const int &y, const int &w, const int & h)
	{
		rect_.x = x;
		rect_.y = y;
		rect_.w = w;
		rect_.h = h;
	}
	void SetRectXY(const int &x, const int & y)
	{
		rect_.x = x;
		rect_.y = y;
	}
	void SetAni(const bool &x)
	{
		ani_ = x;
	}
	bool GetAni() const { return ani_; }
	void Move(const int &x, const int &y);
	int GetValue() const { return value_; }
	void SetValue(const int &val) { value_ = val; }
	SDL_Rect GetRect() const { return rect_; }
	SDL_Surface* Get_Object() { return object_; }
	void Delete()
	{
		if (object_ != NULL) SDL_FreeSurface(object_);
	}
	void SetAniValue(const int& x) { ani_value_ = x; }
	int GetAniValue() const { return ani_value_; }
protected:
	SDL_Rect rect_;
	SDL_Surface * object_;
	int value_;
	bool ani_; // check animation
	int ani_value_;
};

#endif // !OBJECT_H_

