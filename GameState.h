#pragma once
#include "sfwdraw.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>



class GameState 
{
	unsigned font;

public:
	void init();
	void update();
	void draw();
};


GameState createGameState();

void initGameState(GameState & gs);

void updateGameState(GameState &gs);

void drawGameState(const GameState &gs);