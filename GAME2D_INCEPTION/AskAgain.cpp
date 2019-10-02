#include "AskAgain.h"

AskAgain::AskAgain()
{

	Sure_.SetRect(60, 345, 140, 60);
	Cancel_.SetRect(295, 345, 140, 60);
	s_ask_ = NONE;
}

AskAgain::~AskAgain()
{
	if (bkAskAgain != NULL)
		SDL_FreeSurface(bkAskAgain);
}

void AskAgain::InputEvent(SDL_Event ask_even)
{
	if (Sure_.InputAction(ask_even)) s_ask_ = SURE;
	if (Cancel_.InputAction(ask_even)) s_ask_ = CANCEL;
}

void AskAgain::Show(SDL_Surface* des)
{
	SDLCommonFunc::ApplySurface(bkAskAgain, des, 5, 5);
	Sure_.Show(des);
	Cancel_.Show(des);
}