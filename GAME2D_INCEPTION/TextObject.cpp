#include "TextObject.h"

TextObject::TextObject()
{
	//str_text_ = "";
	rect_.x = 200;
	rect_.y = 200;
}

TextObject::~TextObject()
{
	// to do
	SDL_FreeSurface(object_);
	
}
void TextObject::SetColor(const int &type)
{
	if (type == RED_TEXT)
	{
		SDL_Color color = { 255, 0, 0 };
		text_color_ = color;
	}
	else if (type == WHITE_TEXT)
	{
		SDL_Color color = { 225, 225, 225 };
		text_color_ = color;
	}
	else if (type == YELLOW_TEXT)
	{
		SDL_Color color = { 218, 225, 137 };
		text_color_ = color; 
	}
	else if (type == BLUE)
	{

		SDL_Color color = { 0, 200, 198 };
		text_color_ = color;
	}
	else
	{
		SDL_Color color = {};
		text_color_ = color;
	}
}

void TextObject::CreateGameText(TTF_Font *font)
{
	object_ = TTF_RenderText_Blended(font, str_text_.c_str(), text_color_);
}

bool TextObject::CheckFocusRect(const int& x, const int& y, const SDL_Rect& rect)
{
	if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
	{
		return true;
	}
	return false;
}

bool TextObject::InputAction(SDL_Event t_even)
{
	int tx, ty;
	switch (t_even.type)
	{
	case SDL_MOUSEMOTION:
		tx = t_even.motion.x;
		ty = t_even.motion.y;

		if (CheckFocusRect(tx, ty, rect_))
		{
			SetColor(TextObject::RED_TEXT);
		}
		else
		{
			SetColor(TextObject::BLACK);
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (t_even.button.button == SDL_BUTTON_LEFT)
		{
			tx = t_even.motion.x;
			ty = t_even.motion.y;
			if (CheckFocusRect(tx, ty, rect_))
			{
				return  true;
			}
		}
	default:
		break;
	}
	return false;
}

