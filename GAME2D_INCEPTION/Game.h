#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "Common_Function.h"
#include "TextObject.h"
#include "RanDom.h" 
#include <iterator> 
#include <map> 
#include "String_Processing.h"
#include "Sound.h"
#include "Animation.h"

class Game
{
public:
	enum Dir
	{
	 Dir_NULL,
	 Dir_NONE,
	 Dir_Set,
	 UP,
	 DOWN,
	 LEFT,
	 RIGHT
	};

	enum Status
	{
		Status_NONE = 0,
		LOSE = 1,
		WIN = 2
	};

	Game();
	~Game();
	bool RanDom();
	void SetHighScore(const int & highscore) { HighScore_ = highscore; }
	int GetHighScore() const { return HighScore_; }
	int GetScore() const { return Score_; }
    void HandleInput(SDL_Event events,Sound *m_sound);
    void Show(SDL_Surface * des,TTF_Font *font);
	void MoveAction();
	void SetListObject();
	void Set_Position();
	void SetHighScore(int &x) { HighScore_ = x; }
	void SetTableObject();
	Status GameStatus();
	void SetIsSound(bool x) { is_sound_ = x; }
	bool GetIsSound() const { return is_sound_; }
	void LoadImgAnimation();
	void SetOriginalTableAnimation();
	Status GetStatus() const { return status; }

private:
	int Size_;
	int Score_;
	int HighScore_;
	TextObject Score_Text_;
	TextObject Score_High_text_;
	std::map<int, Object> List_Object_;
	std::map<int, Animation> List_Animation_;
	Position position_[G_SIZE][G_SIZE];
	int table_algorithm[G_SIZE][G_SIZE];
	Object table_object_[G_SIZE][G_SIZE];
	int y_val_;
	int x_val_;
	SDL_Rect score_position_;
	SDL_Rect score_high_position_;
	Dir dir_;
	Status status;
	bool is_sound_;
	int index_;
};

#endif // !GAME_H_

