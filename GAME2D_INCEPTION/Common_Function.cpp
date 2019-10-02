#include "Common_Function.h"

SDL_Surface * SDLCommonFunc::LoadImage(std::string file_path)
{
	SDL_Surface * load_image = NULL;
	SDL_Surface * optimize_image = NULL;
	load_image = IMG_Load(file_path.c_str());
	if (load_image != NULL)
	{
		optimize_image = SDL_DisplayFormatAlpha(load_image);
		SDL_FreeSurface(load_image);
	}
	return optimize_image;
}

void SDLCommonFunc::ApplySurface(SDL_Surface * src, SDL_Surface * des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

void SDLCommonFunc::CleanUp()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
	SDL_FreeSurface(g_win);
	SDL_FreeSurface(g_over);
}