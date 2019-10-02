#include "Game.h"
#include "Solve_Table.h"

Game::Game()
{
	Size_ = 0;
	Score_ = 0;
	HighScore_ = 0;
	dir_ = Dir_NULL;
	status = Status_NONE;
	y_val_ = 0;
	x_val_ = 0;
	for(int i = 0 ;i <G_SIZE ; i ++)
		for (int j = 0; j < G_SIZE; j++)
		{
			table_object_[i][j].SetValue(0);
		}
	
	score_position_.x = 270;
	score_position_.y = 43;
	score_high_position_.x = 410;
	score_high_position_.y = 43;
	is_sound_ = false;
	index_ = 0;
}

Game::~Game()
{
	Score_High_text_.Delete();
	Score_Text_.Delete();
	for(int i = 0 ; i < G_SIZE ; i ++)
		for (int j = 0; j < G_SIZE; j++)
		{
			table_object_[i][j].Delete();
		}
	for (int i = 2; i <= 2048; i *= 2)
	{
		List_Object_[i].Delete();
		List_Animation_[i].Delete();
	}
}

void Game:: HandleInput(SDL_Event events, Sound *m_sound)
{
	if(events.type == SDL_KEYDOWN)
	{
		int x = Score_;
		switch (events.key.keysym.sym)
		{
			// go up //
		case SDLK_UP:
			dir_ = UP;
			y_val_ = - MOVE_SPEED;
			if (Up(table_algorithm, Score_,table_object_)) 
			{
				if (Score_ > x) m_sound->PlayMoveSound();
				if (!RanDom()) break;
				if (Score_ <= x)  m_sound->PlaySoundCreatNumber();
			}
			break;

			// go down //
		case SDLK_DOWN:
			dir_ = DOWN;
			y_val_ = MOVE_SPEED;
			if (Down(table_algorithm, Score_, table_object_))
			{
				if (Score_ > x) m_sound->PlayMoveSound();
				if (!RanDom()) break;
				if (Score_ <= x)  m_sound->PlaySoundCreatNumber();
			}
			break;

			// go right //
		case SDLK_RIGHT:
			dir_ = RIGHT;
			x_val_ = MOVE_SPEED;
			if (Right(table_algorithm, Score_, table_object_))
			{
				if (Score_ > x) m_sound->PlayMoveSound();
				if (!RanDom()) break;
				if (Score_ <= x)  m_sound->PlaySoundCreatNumber();
			}
			break;

			// go left //
		case SDLK_LEFT:
			dir_ = LEFT;
			x_val_ = - MOVE_SPEED;
			if (Left(table_algorithm, Score_, table_object_))
			{
				if (Score_ > x) m_sound->PlayMoveSound();
				if (!RanDom()) break;
				if (Score_ <= x)  m_sound->PlaySoundCreatNumber();
			}
			break;
		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
	   // to do	
	}
    else if (events.type == SDL_MOUSEBUTTONDOWN)
	{
        // to do
	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{
		// to do
	}
	else 
	{
		// to do
	}
}

void Game::MoveAction()
{
	switch (dir_)
	{
	case Game::UP: 
		if (dir_ == UP)
		{
			dir_ = Dir_NONE;
			for (int j = 0; j < G_SIZE; j++)
				for (int i = 0; i < G_SIZE; i++)
				{
					if (i == 0 && table_object_[i][j].GetValue() != 0) continue;
					if (table_object_[i][j].GetValue() == 0) continue;

					int check_y = table_object_[i][j].GetRect().y;
					table_object_[i][j].Move(0, y_val_);
					int min_y;
					for (int k = i - 1; k >= 0; k--)
					{
						min_y = table_object_[k][j].GetRect().y;
						if (k == 0 && table_object_[k][j].GetValue() == 0) min_y -= (OBJECT_HEIGHT + DISTANCE);
						if (table_object_[i][j].GetValue() == table_object_[k][j].GetValue())
						{
							int z = 0;
							for (int t = k - 1; t >= 0; t--)
							{
								if (table_object_[t][j].GetValue() == 0) continue;
								if (table_object_[i][j].GetValue() == table_object_[t][j].GetValue())
									z++;
								else break;
							}
							if(z % 2 == 0 ) min_y -= (OBJECT_HEIGHT+DISTANCE);
						}
						if (table_object_[k][j].GetValue() != 0) break;
					}
					if (table_object_[i][j].GetRect().y - OBJECT_HEIGHT - DISTANCE < min_y)
						table_object_[i][j].Move(0, - y_val_);
					if (check_y != table_object_[i][j].GetRect().y) dir_ = UP;
				}
		}
		break;
	case Game::DOWN:
		if (dir_ == DOWN)
		{
			dir_ = Dir_NONE;
			for (int j = 0; j < G_SIZE; j++)
				for (int i = G_SIZE - 1; i >= 0; i--)
				{
					if (i == G_SIZE - 1 && table_object_[i][j].GetValue() != 0) continue;
					if (table_object_[i][j].GetValue() == 0) continue;
					int check_y = table_object_[i][j].GetRect().y;
					table_object_[i][j].Move(0, y_val_);
					int max_y;
					for (int k = i + 1; k < G_SIZE; k++)
					{
						max_y = table_object_[k][j].GetRect().y;
						if (k == G_SIZE - 1 && table_object_[k][j].GetValue() == 0) max_y += OBJECT_HEIGHT + DISTANCE;
						if (table_object_[i][j].GetValue() == table_object_[k][j].GetValue())
						{
							int z = 0;
							for (int t = k + 1; t < G_SIZE; t++)
							{
								if (table_object_[t][j].GetValue() == 0) continue;
								if (table_object_[i][j].GetValue() == table_object_[t][j].GetValue())
									z++;
								else break;
							}
							if (z % 2 == 0) max_y += OBJECT_HEIGHT + DISTANCE;
						}
						if (table_object_[k][j].GetValue() != 0) break;
					}
					if (table_object_[i][j].GetRect().y + OBJECT_HEIGHT + DISTANCE > max_y)
						table_object_[i][j].Move(0, - y_val_);
					if (check_y != table_object_[i][j].GetRect().y) dir_ = DOWN;
				}
		}
		break;
	case Game::LEFT:
		if (dir_ == LEFT)
		{
			dir_ = Dir_NONE;
			for (int i = 0; i < G_SIZE; i++)
				for (int j = 0; j < G_SIZE; j ++)
				{
					if (j == 0 && table_object_[i][j].GetValue() != 0) continue;
					if (table_object_[i][j].GetValue() == 0) continue;

					int check_x = table_object_[i][j].GetRect().x;
					table_object_[i][j].Move(x_val_, 0);
					int min_x;
					for (int k = j - 1; k >= 0; k --)
					{
						min_x = table_object_[i][k].GetRect().x;
						if (k == 0 && table_object_[i][k].GetValue() == 0) min_x -= (OBJECT_WIDTH + DISTANCE);
						if (table_object_[i][j].GetValue() == table_object_[i][k].GetValue())
						{
							int z = 0;
							for (int t = k - 1; t >= 0; t--)
							{
								if (table_object_[i][t].GetValue() == 0) continue;
								if (table_object_[i][j].GetValue() == table_object_[i][t].GetValue())
									z++;
								else break;
							}
							if (z % 2 == 0) min_x -=( OBJECT_WIDTH + DISTANCE);
						}
						if (table_object_[i][k].GetValue() != 0) break;
					}
					if (table_object_[i][j].GetRect().x - OBJECT_WIDTH - DISTANCE < min_x)
						table_object_[i][j].Move(-x_val_, 0);
					if (check_x != table_object_[i][j].GetRect().x) dir_ = LEFT;
				}
		}
		break;

	case Game::RIGHT: 
		if (dir_ == RIGHT)
		{
			dir_ = Dir_NONE;
			for (int i = 0; i < G_SIZE; i++)
				for (int j = G_SIZE - 1; j >= 0; j--)
				{
					if (j == G_SIZE - 1 && table_object_[i][j].GetValue() != 0) continue;
					if (table_object_[i][j].GetValue() == 0) continue;
					int check_x = table_object_[i][j].GetRect().x;
					table_object_[i][j].Move(x_val_, 0);
					int max_x;
					for (int k = j + 1; k < G_SIZE; k ++)
					{
			            max_x = table_object_[i][k].GetRect().x;
						if (k == G_SIZE - 1 && table_object_[i][k].GetValue() == 0) max_x += OBJECT_WIDTH + DISTANCE;
						if (table_object_[i][j].GetValue() == table_object_[i][k].GetValue())
						{
							int z = 0;
							for (int t = k + 1; t < G_SIZE; t ++)
							{
								if (table_object_[i][t].GetValue() == 0) continue;
								if (table_object_[i][j].GetValue() == table_object_[i][t].GetValue())
									z++;
								else break;
							}
							if (z % 2 == 0) max_x += OBJECT_WIDTH + DISTANCE;
						}
						if (table_object_[i][k].GetValue() != 0) break;
					}
					if(table_object_[i][j].GetRect().x + OBJECT_WIDTH + DISTANCE> max_x)
						table_object_[i][j].Move(- x_val_, 0);
					if (check_x != table_object_[i][j].GetRect().x) dir_ = RIGHT;
				}			
		}   
		break;
	default:
		break;
	}
}

bool Game::RanDom()
{
	int ani_x;
	int ani_y;
	if (Random(table_algorithm, ani_x, ani_y))
	{
		table_object_[ani_x][ani_y].SetAni(true);
		return true;
	}
	return false;
}

void Game::Set_Position()
{
	for (int i = 0; i < G_SIZE; i++)
	{
		for (int j = 0; j < G_SIZE; j++)
		{
			position_[i][j].width_ = ROOT_X + OBJECT_WIDTH * j + DISTANCE * j;
			position_[i][j].height_ = ROOT_Y + OBJECT_HEIGHT * i + DISTANCE * i;
		}
	}
}

void Game::SetTableObject()
{
	Object obj;
    for(int i = 0 ; i < G_SIZE ; i ++)
		for (int j = 0; j < G_SIZE; j++)
		{
			if (table_algorithm[i][j] == 0)
			{
				table_object_[i][j] = obj;
				table_object_[i][j].SetRect(position_[i][j].width_, position_[i][j].height_,
					OBJECT_WIDTH, OBJECT_HEIGHT);
			}
			else
			{
				bool check = false;
				if (table_object_[i][j].GetAni() == true)
					  check = true;

				table_object_[i][j] = List_Object_[table_algorithm[i][j]]; 
					if (check) table_object_[i][j].SetAni(true);
				table_object_[i][j].SetValue(table_algorithm[i][j]);
				table_object_[i][j].SetRect(position_[i][j].width_, position_[i][j].height_,
					OBJECT_WIDTH, OBJECT_HEIGHT);
			}
		}
}


void Game::SetListObject()
{
	List_Object_[2].LoadImg("Images/2abc.png");
	List_Object_[4].LoadImg("Images/4abc.png");
	List_Object_[8].LoadImg("Images/8abc.png");
	List_Object_[16].LoadImg("Images/16abc.png");
	List_Object_[32].LoadImg("Images/32abc.png");
	List_Object_[64].LoadImg("Images/64abc.png");
	List_Object_[128].LoadImg("Images/128abc.png");
	List_Object_[256].LoadImg("Images/256abc.png");
	List_Object_[512].LoadImg("Images/512abc.png");
	List_Object_[1024].LoadImg("Images/1024abc.png");
	List_Object_[2048].LoadImg("Images/2048abc.png");
}

void Game::SetOriginalTableAnimation()
{
	for (int i = 0; i < G_SIZE; i++)
		for (int j = 0; j < G_SIZE; j++)
		{
			if (table_object_[i][j].GetAni())
			{
				table_object_[i][j].SetAni(false);
			}
		}
}
void Game::Show(SDL_Surface * des,TTF_Font* font)
{
	if (dir_ == Dir_NONE || dir_ == Dir_NULL)
	{
		SetTableObject();
		
		for (int i = 0; i < G_SIZE; i++)
			for (int j = 0; j < G_SIZE; j++)
			{
				if (table_object_[i][j].GetValue() == 0) continue;
				if (table_object_[i][j].GetAni())
				{
					int pos = table_object_[i][j].GetValue();
					List_Animation_[pos].SetRectXY(table_object_[i][j].GetRect().x,
						table_object_[i][j].GetRect().y);
					List_Animation_[pos].Show(des, index_);
					SDL_Delay(2);
					continue;
				}
				table_object_[i][j].Show(des);
			}
		index_ += 1;
		if (index_ == 14) 
		{
			index_ = 0;
			SetOriginalTableAnimation();
			dir_ = Dir_Set;
		}
	}	
	else
	{
		for (int i = 0; i < G_SIZE; i++)
			for (int j = 0; j < G_SIZE; j++)
			{
				if (table_object_[i][j].GetValue() == 0) continue;
				table_object_[i][j].Show(des);
			}
	}
	if (dir_ == Dir_Set || dir_ == Dir_NULL)
	{
		if (Score_ > HighScore_) HighScore_ = Score_;
		Score_Text_.Delete();
		Score_Text_.SetObject();
		Score_Text_.SetText(IntStr(Score_));
		score_position_.x = 205 + (135 - IntStr(Score_).length() * SIZE_CHAR) / 2;
		Score_Text_.SetRect(score_position_.x, score_position_.y,0,0);
		Score_Text_.SetColor(TextObject::YELLOW_TEXT);
		Score_Text_.CreateGameText(font);

		Score_High_text_.Delete();
		Score_High_text_.SetObject();
		Score_High_text_.SetText(IntStr(HighScore_));
		score_high_position_.x = 350 + (135 - IntStr(HighScore_).length() * SIZE_CHAR) / 2;
		Score_High_text_.SetRect(score_high_position_.x, score_high_position_.y,0,0);
		Score_High_text_.SetColor(TextObject::YELLOW_TEXT);
		Score_High_text_.CreateGameText(font);
	}
	
	Score_High_text_.Show(des);
	Score_Text_.Show(des);

}

Game::Status Game::GameStatus()
{
	for(int i = 0 ;i < G_SIZE; i ++ )
		for (int j = 0;j < G_SIZE; j ++)
		{
			if (table_algorithm[i][j] == WIN_SCORE)
			{
				status = WIN;
				return WIN;
			}
		}

	for (int i = 0; i < G_SIZE; i ++)
		for (int j = 0; j < G_SIZE; j ++)
			if (table_algorithm[i][j] == 0)
			{
				status = Status_NONE;
				return Status_NONE;
			}

	for (int i = 0; i < G_SIZE; i++)
		for (int j = 1; j < G_SIZE; j++)
		{
			if (table_algorithm[i][j - 1] == table_algorithm[i][j])
			{
				status = Status_NONE;
				return Status_NONE;
			}
		}

	for (int j = 0; j < G_SIZE; j++)
		for (int i = 1; i < G_SIZE; i++)
		{
			if (table_algorithm[i - 1][j] == table_algorithm[i][j])
			{
				status = Status_NONE;
				return Status_NONE;
			}
		}
	status = LOSE;
	return LOSE;
}

void Game::LoadImgAnimation()
{
	for(int i = 2 ; i <= 2048; i *= 2)
	List_Animation_[i].LoadImg(i);
}


	