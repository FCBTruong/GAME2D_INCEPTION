#pragma once
#ifndef SOLVE_TABLE_H_
#define SOVLE_TABLE_H_

#include "Common_Function.h"
#include "Object.h"

bool Up(int table_algorithm[G_SIZE][G_SIZE], int &score, Object table_obj[G_SIZE][G_SIZE]);
bool Down(int table_algorithm[G_SIZE][G_SIZE], int &score, Object table_obj[G_SIZE][G_SIZE]);
bool Left(int table_algorithm[G_SIZE][G_SIZE], int &score, Object table_obj[G_SIZE][G_SIZE]);
bool Right(int table_algorithm[G_SIZE][G_SIZE], int &score, Object table_obj[G_SIZE][G_SIZE]	);

#endif // !SOLVE_TABLE_H_
