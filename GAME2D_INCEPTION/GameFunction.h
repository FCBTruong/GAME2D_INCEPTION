#pragma once
#ifndef GAME_FUNCTION_H
#define GAME_FUNCTION_H
#include "Common_Function.h"
#include "TextObject.h"
#include "Object.h"

class GameFunction
{
public:
	enum Shape
	{
		SQUARE = 0,
	    CIRCLE = 1
	};

	enum ShowKind
	{
		ZOOM,
		REPLACE
	};

	GameFunction();
	~GameFunction();
	void SetShape(Shape x) { shape_ = x; };
	void Show(SDL_Surface * des);
	void SetIs(bool x) { is_ = x; }
	void SetShowKind(ShowKind x) { s_kind_ = x; }
	bool CheckFocusRect(const int&x, const int &y, const SDL_Rect& rect);
	bool InputAction(SDL_Event f_even);
	bool LoadImg1(const char *file_name);
	bool LoadImg2(const char *file_name);
	void SetRect(const int &x, const int &y, const int &w, const int &h)
	{
		f_object_begin_.SetRect(x, y, w, h);
		if(s_kind_ == ZOOM) f_object_after_.SetRect(x - 2, y - 2, w + 4, h + 4);
		else f_object_after_.SetRect(x, y, w, h);
	}
protected:
	TextObject f_text_object_;
	Object f_object_begin_;
	Object f_object_after_;
	Shape shape_;
	ShowKind s_kind_;
    bool is_;
};

#endif // !GAME_FUNCTION_H
