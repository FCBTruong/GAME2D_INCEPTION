#ifndef SOUND_H_
#define SOUND_H_

#include "Common_Function.h"
#include "GameFunction.h"

class Sound
{
public:
	enum StatusSound
	{
		ON,
		OFF,
		S_NULL,
		sound
	};
	Sound();
	~Sound();
	
	bool LoadMoveSound(const char * file_name);
	bool LoadSoundCreateNumber(const char * file_name);
	bool LoadWinSound(const char * file_name);
	bool LoadLoseSound(const char * file_name);
	void PlayMoveSound();
	void PlaySoundCreatNumber();
	void PlayWinSound();
	void PlayLoseSound();
	void Show(SDL_Surface * des);
	void SetRect(const int &x, const int &y, const int &w, const int &h);
	void SetShape(GameFunction::Shape x);
	void InputAction(SDL_Event s_even);
	bool LoadImgSoundOn(const char * file_name1, const char * file_name2);
	bool LoadImgSoundOff(const char * file_name1, const char * file_name2);
	void SetStatus(const StatusSound &x) { s_status_ = x; }
private:
	GameFunction SoundOn_;
	GameFunction SoundOff_;
	Mix_Chunk * MoveSound_;
	Mix_Chunk * SoundCreateNumber_;
	Mix_Chunk * WinSound_;
	Mix_Chunk * LoseSound_;
	StatusSound s_status_;
};

#endif // !
