#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "Common_Function.h"
#include "GameFunction.h"
#include "Sound.h"

class PauseMenu
{
public:
	enum DirPauseGame
	{
		P_NULL,
		CONTINUE,
		HOME,
		GUIDE
	};
	PauseMenu();
	~PauseMenu();
	void LoadHomeImageON(const char * file_name)
	{
		Home.LoadImg2(file_name);
	}
	void LoadHomeImageOFF(const char * file_name)
	{
		Home.LoadImg1(file_name);
	}
	
	void LoadGuideImageON(const char * file_name)
	{
		Guide.LoadImg2(file_name);
	}
	void LoadGuideImageOFF(const char * file_name)
	{
		Guide.LoadImg1(file_name);
	}

	void LoadContinueImageON(const char * file_name)
	{
		Continue.LoadImg2(file_name);
	}
	void LoadContinueImageOFF(const char * file_name)
	{
		Continue.LoadImg1(file_name);
	}
	void LoadPauseScreen(const char * file_name)
	{
		PauseScreen = SDLCommonFunc::LoadImage(file_name);
	}
	void SetRectHome(const int &x, const int & y, const int & w, const int &h)
	{
		Home.SetRect(x, y, w, h);
	}

	void SetSound(Sound * sound)
	{
		p_sound = sound;
	}

	void SetRectGuide(const int &x, const int & y, const int & w, const int &h)
	{
		Guide.SetRect(x, y, w, h);
	}

	void SetRectContinue(const int &x, const int & y, const int & w, const int &h)
	{
		Continue.SetRect(x, y, w, h);
	}

	void SetDirPauseGame(const DirPauseGame &x) { p_Dir_ = x; }
	DirPauseGame GetDirPauseMenu() { return p_Dir_; }
	void Show(SDL_Surface * des);
	void InputAction(SDL_Event p_even);
	void SetOrigin()
	{
		Home.SetIs(true);
		Guide.SetIs(true);
		Continue.SetIs(true);
		p_Dir_ = P_NULL;
		left_.SetIs(true);
		right_.SetIs(true);
		index = 1;
	}
	void SolveGuide(SDL_Event g_even);
	void ShowGuide(SDL_Surface * des);
	int GetIndex() const { return index; }
private:
	
	SDL_Surface * PauseScreen;
	GameFunction Home;
	GameFunction Guide;
	GameFunction Continue;
	DirPauseGame p_Dir_;
	Sound *p_sound;

	// Guide:
	int index;
	SDL_Surface* guide1;
	SDL_Surface* guide2;
	SDL_Surface* guide3;
	GameFunction left_;
	GameFunction right_;
	//GameFunction 
};

#endif // !PAUSE_MENU_H
