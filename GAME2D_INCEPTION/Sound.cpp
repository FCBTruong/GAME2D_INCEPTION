#include "Sound.h"

Sound::Sound()
{
	s_status_ = ON;
}

Sound::~Sound()
{
	if (MoveSound_ != NULL) Mix_FreeChunk(MoveSound_);
	if (SoundCreateNumber_ != NULL) Mix_FreeChunk(SoundCreateNumber_);
	if (WinSound_ != NULL) Mix_FreeChunk(WinSound_);
	if (LoseSound_ != NULL) Mix_FreeChunk(LoseSound_);
}

bool Sound::LoadMoveSound(const char * file_name)
{
	MoveSound_ = Mix_LoadWAV(file_name);
	if (MoveSound_ == NULL) return false;
	return true;
}

bool Sound::LoadSoundCreateNumber(const char * file_name)
{
	SoundCreateNumber_ = Mix_LoadWAV(file_name);
	if (SoundCreateNumber_ == NULL) return false;
	return true;
}

bool Sound::LoadWinSound(const char * file_name)
{
	WinSound_ = Mix_LoadWAV(file_name);
	if (WinSound_ == NULL) return false;
	return true;
}

bool Sound::LoadLoseSound(const char * file_name)
{
    LoseSound_ = Mix_LoadWAV(file_name);
	if (LoseSound_ == NULL) return false;
	return true;
}

void Sound::PlayMoveSound()
{
	if(s_status_ == ON) Mix_PlayChannel(-1, MoveSound_, 0);
}

void Sound::PlayLoseSound()
{
	if (s_status_ == ON) Mix_PlayChannel(-1, LoseSound_, 0);
}

void Sound::PlaySoundCreatNumber()
{
	if (s_status_ == ON) Mix_PlayChannel(-1, SoundCreateNumber_, 0);
}

void Sound::PlayWinSound()
{
	if (s_status_ == ON) Mix_PlayChannel(-1, WinSound_, 0);
}

void Sound::Show(SDL_Surface * des)
{
	if (s_status_ == ON)
	{
		SoundOn_.Show(des);
	}
	else if (s_status_ == OFF)
	{
		SoundOff_.Show(des);
	}
}

void Sound::SetRect(const int &x, const int &y, const int &w, const int &h)
{
	SoundOn_.SetRect(x ,y, w, h);
	SoundOff_.SetRect(x, y, w, h);
}

void Sound::SetShape(GameFunction::Shape x)
{
	SoundOn_.SetShape(x);
	SoundOff_.SetShape(x);
}

bool Sound::LoadImgSoundOn(const char * file_name1, const char * file_name2)
{
	if(SoundOn_.LoadImg1(file_name1) && SoundOn_.LoadImg2(file_name2))
		return true; // before; // after
	return false;
}

bool Sound::LoadImgSoundOff(const char * file_name1, const char * file_name2)
{
	if(SoundOff_.LoadImg1(file_name1) && SoundOff_.LoadImg2(file_name2))
		return true; // before // after
	return false;
}

void Sound::InputAction(SDL_Event s_even)
{
	if (s_status_ == ON)
	{
		if (SoundOn_.InputAction(s_even))
			s_status_ = OFF;
	}
	else 
	{
		if (SoundOff_.InputAction(s_even))
			if (s_status_ == OFF) s_status_ = ON;
	}
}