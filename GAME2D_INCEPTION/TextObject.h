#pragma once
#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_

#include "Common_Function.h"
#include "Object.h"

class TextObject : public Object
{
public:
	enum TextColor
	{
		RED_TEXT = 0,
		WHITE_TEXT = 1,
		YELLOW_TEXT = 2,
		BLACK = 3,
		BLUE = 4
	};
	TextObject();
	~TextObject(); 
	void SetText(const std::string &text) { str_text_ = text; }
	void SetColor(const int & type);
	void CreateGameText(TTF_Font* font);
	void SetObject()
	{
		SDL_Surface *m = new SDL_Surface;
		object_ = m;
	}
	bool InputAction(SDL_Event t_even);
	bool CheckFocusRect(const int& x, const int& y, const SDL_Rect& rect);

private:
	std::string str_text_;
	SDL_Color text_color_;
};

#endif // !TEXT_OBJECT_H_
