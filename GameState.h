#pragma once
#include "sfwdraw.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Paddle.h"
#include "Ball.h"
#include "constdecl.h"
#include "Brick.h"
#include "web.h"

class GameState 
{
	unsigned font;
	Ball ball;
	Paddle p;
	Web web;
	float timer2;
	unsigned pic;
	unsigned pic2;
	unsigned pic5;

	//Brick bricks[30];

public:
	void init();
	void update();
	void draw();
	void play2();

	
	
	APP_STATE next();
};