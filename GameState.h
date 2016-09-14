#pragma once
#include "sfwdraw.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Paddle.h"
#include "Ball.h"
#include "constdecl.h"

class GameState 
{
	unsigned font;
	Ball ball;
	Paddle p;

public:
	void init();
	void update();
	void draw();
	APP_STATE next();
};