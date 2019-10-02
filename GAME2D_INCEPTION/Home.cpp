#include "Home.h"

HOME::HOME()
{
	Home_screen_ = SDLCommonFunc::LoadImage("Images/HOME.png");
	newgame_.SetColor(TextObject::BLACK);
	setting_.SetColor(TextObject::BLACK);
	high_score_.SetColor(TextObject::BLACK);
	home_status_ = NONE;
	High_score_screen_ = SDLCommonFunc::LoadImage("Images/high_score.png");
	Setting_screen_ = SDLCommonFunc::LoadImage("Images/setting_screen.png");
	high_score_back_.LoadImg1("Images/high_back.png");
	high_score_back_.LoadImg2("Images/high_backON.png");
	high_score_back_.SetShape(GameFunction::CIRCLE);
	high_score_back_.SetShowKind(GameFunction::REPLACE);
	high_score_back_.SetRect(416, 102, 32, 32);

	Setting_Sound_ON.LoadImg1("Images/setting_sound_ON1.png");
	Setting_Sound_ON.LoadImg2("Images/setting_sound_ON2.png");
	Setting_Sound_ON.SetShowKind(GameFunction::REPLACE);
	Setting_Sound_ON.SetRect(205, 310, 100, 50);

	Setting_Sound_OFF.LoadImg1("Images/setting_sound_OFF1.png");
	Setting_Sound_OFF.LoadImg2("Images/setting_sound_OFF2.png");
	Setting_Sound_OFF.SetShowKind(GameFunction::REPLACE);
	Setting_Sound_OFF.SetRect(205, 310, 100, 50);

	is_sound_ = true;
}

HOME::~HOME()
{
	SDL_FreeSurface(Home_screen_);
	SDL_FreeSurface(Setting_screen_);
	SDL_FreeSurface(High_score_screen_);
}

void HOME::Show(SDL_Surface* des,TTF_Font  *font,const int &h)
{
	SDLCommonFunc::ApplySurface(Home_screen_, des, 0, 0);
	newgame_.Show(des);
	high_score_.Show(des);
	setting_.Show(des);
	if (home_status_ == HIGHSCORE)
	{
		SetOrigin();
		SDLCommonFunc::ApplySurface(High_score_screen_, des, 0, 0);
		Score_High_text_.Delete();
		Score_High_text_.SetObject();
		Score_High_text_.SetText(IntStr(h));
		int x = 252 - IntStr(h).length() * SIZE_CHAR / 2;
		Score_High_text_.SetRect(x, 330, 0, 0);
		Score_High_text_.SetColor(TextObject::BLACK);
		Score_High_text_.CreateGameText(font);
		Score_High_text_.Show(des);
		high_score_back_.Show(des);
	}
	if(home_status_ == SETTING)
	{
		SetOrigin();
		SDLCommonFunc::ApplySurface(Setting_screen_, des, 0, 0);
		if (is_sound_) Setting_Sound_ON.Show(des);
		else Setting_Sound_OFF.Show(des);
		high_score_back_.Show(des);
	}
}

void HOME::CreateFontHome(TTF_Font* font)
{
	newgame_.Delete();
	newgame_.SetObject();
	high_score_.Delete();
	high_score_.SetObject();
	setting_.Delete();
	setting_.SetObject();

	newgame_.SetText("NEW GAME");

	setting_.SetText("SETTING");

	high_score_.SetText("HIGH SCORE");

	newgame_.SetRect(174, 311, 155, 30);
	high_score_.SetRect(166, 396, 167, 30);
	setting_.SetRect(191, 480, 118, 30);
	newgame_.CreateGameText(font);
	setting_.CreateGameText(font);
	high_score_.CreateGameText(font);
}

void HOME::InputAction(SDL_Event h_even)
{
	if (home_status_ == NONE)
	{
		if (newgame_.InputAction(h_even))
		{
			home_status_ = NEWGAME;
		}
		if (setting_.InputAction(h_even)) home_status_ = SETTING;
		if (high_score_.InputAction(h_even))
		{
			home_status_ = HIGHSCORE;
		}
	}

	if (home_status_ == HIGHSCORE || home_status_ == SETTING)
	{
		if (high_score_back_.InputAction(h_even))
		{
			home_status_ = NONE;
			high_score_back_.SetIs(true);
		}
	}
	if (home_status_ == SETTING)
	{
		if (is_sound_)
		{
			if(Setting_Sound_ON.InputAction(h_even))
			is_sound_ = false;
		}
		else
		{
			if(Setting_Sound_OFF.InputAction(h_even))
			is_sound_ = true;
		}
	}
}

bool HOME::CheckFocusRect(const int& x, const int& y, const SDL_Rect& rect)
{
	if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
	{
		return true;
	}
	return false;
}

void HOME::SetOrigin()
{
	newgame_.SetColor(5);
	setting_.SetColor(5);
	high_score_.SetColor(5);
}