#include "Object.h"

Object::Object()
{
	rect_.x = 0;
	rect_.y = 0;
	value_ = 0;
	object_ = NULL;
	ani_ = false;
}

Object::~Object()
{
	
}

bool Object::LoadImg(const std::string file_path)
{
	object_ = SDLCommonFunc::LoadImage(file_path);
	if (object_ == NULL) return false;
	return true;
}

void Object::Move(const int &x, const int &y)
{
	rect_.x += x;
	rect_.y += y;
}

void Object::Show(SDL_Surface * des)
{
	if (object_ != NULL)
	{
		SDLCommonFunc::ApplySurface(object_, des, rect_.x, rect_.y);
	}
}