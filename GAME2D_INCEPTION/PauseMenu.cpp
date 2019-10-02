#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	Continue.SetShape(GameFunction::CIRCLE);
	Home.SetShape(GameFunction::CIRCLE);
	Guide.SetShape(GameFunction::CIRCLE);
	p_Dir_ = P_NULL;
	p_sound = NULL;
	index = 1;

	guide1 = SDLCommonFunc::LoadImageA("Images/guide/guide1.png");
	guide2 = SDLCommonFunc::LoadImageA("Images/guide/guide2.png");
	guide3 = SDLCommonFunc::LoadImageA("Images/guide/guide3.png");

	left_.LoadImg1("images/guide/leftOFF.png");
	left_.LoadImg2("images/guide/leftON.png");
	right_.LoadImg1("images/guide/rightOFF.png");
	right_.LoadImg2("images/guide/rightON.png");
	
	left_.SetShape(GameFunction::CIRCLE);
	left_.SetShowKind(GameFunction::REPLACE);
	left_.SetRect(5, 276, 48, 48);
	
	right_.SetShape(GameFunction::CIRCLE);
	right_.SetShowKind(GameFunction::REPLACE);
	right_.SetRect(452, 276, 48, 48);
}

PauseMenu::~PauseMenu()
{
	if (PauseScreen != NULL)
	{
		SDL_FreeSurface(PauseScreen);
	}
	if (guide1 != NULL)
	{
		SDL_FreeSurface(guide1);
	}
	if (guide2 != NULL)
	{
		SDL_FreeSurface(guide2);
	}
	if (guide3 != NULL)
	{
		SDL_FreeSurface(guide3);
	}
}

void PauseMenu::Show(SDL_Surface * des)
{
	SDLCommonFunc::ApplySurface(PauseScreen, des, 0, 0);
	Continue.Show(des);
	Home.Show(des);
	Guide.Show(des);
	p_sound->Show(des);
}

void PauseMenu::InputAction(SDL_Event p_even)
{
	if (Continue.InputAction(p_even))
	{
		p_Dir_ = CONTINUE;
	}
	if(Home.InputAction(p_even)) p_Dir_ = HOME;
	if(Guide.InputAction(p_even)) p_Dir_ = GUIDE;
	p_sound->InputAction(p_even);
}

void PauseMenu::SolveGuide(SDL_Event g_even)
{
	if (left_.InputAction(g_even))
	{
		if (index > 0) index--;
	}

	if (right_.InputAction(g_even))
	{
		if (index < 4) index ++;
	}
	right_.InputAction(g_even);
}

void PauseMenu::ShowGuide(SDL_Surface* des)
{
	switch (index)
	{
	case 1: SDLCommonFunc::ApplySurface(guide1, des, 0, 0);
		break;
	case 2: SDLCommonFunc::ApplySurface(guide2, des, 0, 0);
		break;
	case 3: SDLCommonFunc::ApplySurface(guide3, des, 0, 0);
		break;
	default:
		break;
	}
	left_.Show(des);
	right_.Show(des);
}