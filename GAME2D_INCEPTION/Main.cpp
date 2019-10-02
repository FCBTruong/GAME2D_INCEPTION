#include "Common_Function.h"
#include "Game.h"
#include "RanDom.h"
#include "Menu.h"
#include "GameFunction.h"
#include "PauseMenu.h"
#include "Sound.h"
#include "AskAgain.h"
#include "Home.h"
#include "HighScore.h"

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	SDL_WM_SetCaption("2048", "2048");
	SDL_WM_SetIcon(IMG_Load("Images/icon.png"), NULL);
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SYSWMEVENTMASK);
	if (g_screen == NULL)
		return false;

	if (TTF_Init() == -1)
	{
		return false;
	}
	g_score_font = TTF_OpenFont("Roboto/Roboto-Regular.ttf", 30);
	if (g_score_font == NULL)
	{
		return false;
	}

	g_home_font = TTF_OpenFont("Roboto/Roboto-BlackItalic.ttf", 30);
	if (g_home_font == NULL)
	{
		return false;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
    }

	GetHighScore();
	return true;
}

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
{
	if (Init() == false) return 0;
    srand(time(0));
	GetHighScore();

	g_bkground = SDLCommonFunc::LoadImage("Images/bkground_main.png");
	g_over = SDLCommonFunc::LoadImage("Images/gameover.png");
	g_win = SDLCommonFunc::LoadImage("Images/gamewin.png");

	GameFunction restart;
	// set restart //
	if (restart.LoadImg1("Menu/restartOFF.png") == false) return 0;
	if (restart.LoadImg2("Menu/restartON.png") == false) return 0;
	restart.SetRect(365, 90, 50, 50);

	GameFunction pause;
	// set pause //
	if (pause.LoadImg1("Menu/pause-buttonOFF.png") == false) return 0;
	if (pause.LoadImg2("Menu/pause-buttonON.png") == false) return 0;
	pause.SetRect(285,90,50,50);

	PauseMenu *pause_menu = new PauseMenu;
	// set pause_menu //
	pause_menu->LoadPauseScreen("Menu/PauseMenu.png");

	pause_menu->LoadContinueImageON("Menu/play-buttonON.png") ;
	pause_menu->LoadContinueImageOFF("Menu/play-buttonOFF.png");
	pause_menu->SetRectContinue(203, 185, 100, 100);

	
	pause_menu->LoadGuideImageON("Menu/guideON.png");
	pause_menu->LoadGuideImageOFF("Menu/guideOFF.png");
	pause_menu->SetRectGuide(217, 400, 70, 70);

	pause_menu->LoadHomeImageON("Menu/houseON.png");
	pause_menu->LoadHomeImageOFF("Menu/houseOFF.png");
	pause_menu->SetRectHome(55, 400, 70, 70);

	// set Sound //
	Sound *m_sound = new Sound;
	if (m_sound->LoadSoundCreateNumber("Sound/SoundCreateNumber.wav") == false) return 0;
	if (m_sound->LoadMoveSound("Sound/MoveSound.wav") == false) return 0;
	if (m_sound->LoadLoseSound("Sound/LoseSound.wav") == false) return 0;
	if (m_sound->LoadWinSound("Sound/WinSound.wav") == false) return 0;
	if (!m_sound->LoadImgSoundOn("Sound/SoundONoff.png","Sound/SoundONon.png")) return 0;
	if (!m_sound->LoadImgSoundOff("Sound/SoundOFFoff.png","Sound/SoundOFFon.png")) return 0;

	m_sound->SetRect(380, 400, 70, 70);
	m_sound->SetShape(GameFunction::CIRCLE);
	
	pause_menu->SetSound(m_sound);

Home_Game:
	HOME* home = new HOME;
	bool home_check = true;
	while (home_check)
	{
		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				home_check = false;
				return 0;
			}
			home->InputAction(g_even);
		}

		home->CreateFontHome(g_home_font);
		home->Show(g_screen, g_score_font, HIGH_SCORE);
		if (home->GetStatus() == HOME::NEWGAME)
		{
			home->SetOrigin();
			home->SetStatus(HOME::NONE);
			home_check = false;
		}
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}

	if (home->GetIsSound()) m_sound->SetStatus(Sound::ON);
	else m_sound->SetStatus(Sound::OFF);
	
Start:
	Game *g = new Game;
	g->SetHighScore(HIGH_SCORE);
	g->SetListObject();
	g->Set_Position();
	g->RanDom();
	g->RanDom();
	g->LoadImgAnimation();
	m_sound->PlaySoundCreatNumber();
	bool game_status = false;

	AskAgain *ask = new AskAgain;
	ask->Load();

	bool is_running = true;
	
	// Apply BackGround //

	if (g_bkground == NULL || g_over == NULL || g_win == NULL)
	{
		return 0;
	}
	// Process //
	while (is_running)
	{
		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				if (g->GetScore() > HIGH_SCORE) HIGH_SCORE = g->GetScore();
				SetHighScore();
				is_running = false;
				break;
			}

			if (restart.InputAction(g_even))
			{
				if (g->GetStatus() == Game::LOSE || g->GetStatus() == Game::WIN) goto Start;
				bool restart_ask = true;
				while(restart_ask)
				{
					while (SDL_PollEvent(&g_even))
					{
						if (g_even.type == SDL_QUIT)
						{
							if (g->GetScore() > HIGH_SCORE) HIGH_SCORE = g->GetScore();
							SetHighScore();
							is_running = false;
							break;
						}
						ask->InputEvent(g_even);
					}

					SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
					restart.Show(g_screen);
					pause.Show(g_screen);
					g->Show(g_screen, g_score_font);
					ask->Show(g_screen);

					if (ask->GetStatus() == AskAgain::SURE)
					{
						if (g->GetHighScore() > HIGH_SCORE) HIGH_SCORE = g->GetHighScore();
						goto Start;
					}
					if (ask->GetStatus() == AskAgain::CANCEL)
					{
						ask->SetIsCancel(true);
						restart_ask = false;
						restart.SetIs(true);
						ask->SetStatus(AskAgain::NONE);
					}
					if (SDL_Flip(g_screen) == -1)
						return 0;
				}
			}
			if (pause.InputAction(g_even))
			{
				bool is = true;
				while (is)
				{
					while (SDL_PollEvent( &h_even))
					{
						if (h_even.type == SDL_QUIT)
						{
							if (g->GetScore() > HIGH_SCORE) HIGH_SCORE = g->GetScore();
							SetHighScore();
							is = false;
							is_running = false;
							break;
						}
						pause_menu->InputAction(h_even);
						//m_sound->InputAction(p_even);
					}

					if (pause_menu->GetDirPauseMenu() == PauseMenu::CONTINUE)
					{
						pause_menu->SetOrigin();
						is = false;
						pause.SetIs(true);
					}

					if (pause_menu->GetDirPauseMenu() == PauseMenu::HOME)
					{

						if (g->GetStatus() != Game::Status_NONE)
						{
							pause.SetIs(true);
							pause_menu->SetOrigin();
							goto Home_Game;
						}
						is = false;
						home_check = true;
						while (home_check)
						{
							while (SDL_PollEvent(&h_even))
							{
								if (h_even.type == SDL_QUIT)
								{
									home_check = false;
									return 0;
								}
								home->InputAction(h_even);
							}

							home->CreateFontHome(g_home_font);
							home->Show(g_screen, g_score_font ,HIGH_SCORE);

							if (home->GetStatus() == HOME::NEWGAME)
							{
								home->SetOrigin();
								pause_menu->SetOrigin();
								home_check = false;
								home->SetStatus(HOME::NONE);
							}

							if (SDL_Flip(g_screen) == -1)
								return 0;
						}

						if (home->GetIsSound()) m_sound->SetStatus(Sound::ON);
						else m_sound->SetStatus(Sound::OFF);

						pause.SetIs(true);
					}

					if (pause_menu->GetDirPauseMenu() == PauseMenu::GUIDE)
					{
						bool guide_check = true;
						while (guide_check)
						{
							while (SDL_PollEvent(&h_even))
							{
								if (h_even.type == SDL_QUIT)
								{
									home_check = false;
									return 0;
								}
								pause_menu->SolveGuide(h_even);
							}
							pause_menu->ShowGuide(g_screen);
							if (pause_menu->GetIndex() == 4 || pause_menu->GetIndex() == 0)
							{
								guide_check = false;
								is = false;
								pause_menu->SetOrigin();
								pause.SetIs(true);
							}
							if (SDL_Flip(g_screen) == -1)
								return 0;
						}
					}

					SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
					restart.Show(g_screen);
					pause.Show(g_screen);
					g->Show(g_screen, g_score_font);
					pause_menu->Show(g_screen);
					
					if (SDL_Flip(g_screen) == -1)
						return 0;
				}
				pause_menu->SetDirPauseGame(PauseMenu::P_NULL);
			}
			if(!game_status) g->HandleInput(g_even, m_sound);
		}
	
		SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
		restart.Show(g_screen);
		pause.Show(g_screen);

		g->MoveAction();
		g->Show(g_screen, g_score_font);

		if (g->GameStatus() == 1)
		{
			// lose
			SDL_Delay(10);
			if(g->GetIsSound() == false) m_sound->PlayLoseSound();
			if (g->GetHighScore() > HIGH_SCORE) HIGH_SCORE = g->GetHighScore();
			SDLCommonFunc::ApplySurface(g_over, g_screen, ROOT_X, ROOT_Y);
			g->SetIsSound(true);
		}
		else if (g->GameStatus() == 2)
		{
			// win
			game_status = true;
			SDL_Delay(10);
			if (g->GetIsSound() == false) m_sound->PlayWinSound();
			if (g->GetHighScore() > HIGH_SCORE) HIGH_SCORE = g->GetHighScore();
			SDLCommonFunc::ApplySurface(g_win, g_screen, ROOT_X, ROOT_Y);
			g->SetIsSound(true);
			// to do
		}
	
		// UpDate Screen //
		
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}
	//delete g_score_font;
    SDLCommonFunc::CleanUp();
	SDL_Quit();
	return 0;
}