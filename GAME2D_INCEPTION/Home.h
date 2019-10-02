#pragma once
#ifndef HOME_H
#define HOME_H

#include "Common_Function.h"
#include "TextObject.h"
#include "GameFunction.h"
#include "String_Processing.h"

class HOME
{
public:
	enum status
	{
		SETTING,
		NEWGAME,
		NONE,
		HIGHSCORE
	};

	HOME();
	~HOME();
	
	void Show(SDL_Surface* des, TTF_Font * font,const int &h);
	bool Load(const char* x)
	{
		Home_screen_ = SDLCommonFunc::LoadImage(x);
		if (Home_screen_ != NULL) return true;
		return false;
	}
	void CreateFontHome(TTF_Font* font);
	void InputAction(SDL_Event h_even);
	bool CheckFocusRect(const int& x, const int& y, const SDL_Rect& rect);
	status GetStatus() const { return home_status_; }
	void SetStatus(const status& x) { home_status_ = x; }
	void SetOrigin();
	bool GetIsSound() const { return is_sound_; }
private:
	SDL_Surface *Home_screen_;
	SDL_Surface *High_score_screen_;
	SDL_Surface* Setting_screen_;
	TextObject newgame_;
	TextObject high_score_;
	TextObject setting_;
	status home_status_;
	GameFunction high_score_back_;
	GameFunction Setting_Sound_ON;
	GameFunction Setting_Sound_OFF;
	TextObject Score_High_text_;
	bool is_sound_;
};

#endif // !HOME_H
