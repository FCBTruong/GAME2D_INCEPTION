#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <Windows.h>
#include <iostream>
#include "Object.h"
#undef main

const int SCREEN_WIDTH = 505;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int OBJECT_WIDTH = 90;
const int OBJECT_HEIGHT = 90;
const int DISTANCE = 15;
const int G_SIZE = 4;
const int ROOT_X = 50;
const int ROOT_Y = 160;
const int WIN_SCORE = 2048;
const int MOVE_SPEED = 3;
const int SIZE_CHAR = 17;
const int option[6] = { 2, 2, 2,2,2, 4 };

static int HIGH_SCORE = 0;
static SDL_Surface * g_screen;
static SDL_Surface * g_bkground;
static SDL_Surface * g_over;
static SDL_Surface * g_win;
static SDL_Event  g_even;	
static SDL_Event  p_even;
static SDL_Event  h_even;
static TTF_Font * g_score_font = NULL;
static TTF_Font * g_home_font = NULL;

namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface * src, SDL_Surface * des, int x, int y);
	void CleanUp();
}

struct Position
{
	int width_;
	int height_;
};

#endif // COMMON_FUNCTION_H_
