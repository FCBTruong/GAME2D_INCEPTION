#ifndef ASK_AGAIN_H
#define ASK_AGAIN_H

#include "Common_Function.h"
#include "GameFunction.h"

class AskAgain
{
public:
	enum Status
	{
		NONE,
		SURE,
		CANCEL
	};
	AskAgain();
	~AskAgain();
	void InputEvent(SDL_Event ask_even);
	void Show(SDL_Surface* des);
	void SetStatus(const Status& x) { s_ask_ = x; }
	Status GetStatus() const { return s_ask_; }
	void Load()
	{
		Sure_.LoadImg1("Images/sureOFF.png");
		Sure_.LoadImg2("Images/sureON.png");
		Cancel_.LoadImg1("Images/cancelOFF.png");
		Cancel_.LoadImg2("Images/cancelON.png");
		bkAskAgain = SDLCommonFunc::LoadImage("Images/restart.png");
	}
	void SetIsCancel(const bool& x) { Cancel_.SetIs(x); }
private:
	GameFunction Sure_;
	GameFunction Cancel_;
	SDL_Surface* bkAskAgain;
	Status s_ask_;
};

#endif // !ASK_AGAIN_H
