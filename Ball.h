#pragma once
#include "web.h"

class Paddle;	// forward declaration

class Ball
{
public:
	float x, y;
	int height;
	int width;
	int size;
	float speedX, speedY;
	float speedXX, speedYY;
	int lock = 0;
	
	//int bricksBroken;

	void update(Paddle &p, Web &web);
	void draw();
};
//PlaySound("C:\\Users\\Commander\\Desktop\\test.wav", NULL, SND_FILENAME);