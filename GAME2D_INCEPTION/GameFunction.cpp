#include "GameFunction.h"

GameFunction::GameFunction()
{
	shape_ = SQUARE;
	is_ = true;
	s_kind_ = ZOOM;
}

GameFunction::~GameFunction()
{
	f_object_begin_.Delete();
	f_object_after_.Delete();
}

void GameFunction::Show(SDL_Surface * des)
{
	if(is_) f_object_begin_.Show(des);
	else f_object_after_.Show(des);
}

bool GameFunction::CheckFocusRect(const int&x, const int &y, const SDL_Rect& rect)
{
	switch (shape_)
	{
	case SQUARE:
		if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
		{
			return true;
		}
		break;
	case CIRCLE:
		int o_x;
		int o_y;
		int r;
		int l;
		o_x = rect.x + rect.w / 2;
		o_y = rect.y + rect.h / 2;
		r = rect.w / 2;
		l = sqrt((x - o_x) * (x - o_x) + (y - o_y) * (y - o_y));
		if (l <= r) return true;
		break;
	default: break;
	}
	return false;
}

bool GameFunction::LoadImg1(const char *file_name)
{
	return f_object_begin_.LoadImg(file_name);
}

bool GameFunction::LoadImg2(const char *file_name)
{
	return f_object_after_.LoadImg(file_name);
}

bool GameFunction::InputAction(SDL_Event f_even)
{
	int fx, fy; // mouse position
	switch (f_even.type)
	{
	case SDL_MOUSEMOTION:
		fx = f_even.motion.x;
		fy = f_even.motion.y;

		if (GameFunction::CheckFocusRect(fx, fy, f_object_begin_.GetRect()))
		{
			is_ = false;
		}
		else
		{
			is_ = true;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (f_even.button.button == SDL_BUTTON_LEFT)
		{
			fx = f_even.motion.x;
			fy = f_even.motion.y;
			if (GameFunction::CheckFocusRect(fx, fy, f_object_after_.GetRect()))
			{
				return  true;
			}
		}
	default:
		break;
	}
	return false;
}