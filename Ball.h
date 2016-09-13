#pragma once

class Paddle;	// forward declaration

class Ball
{
public:
	float x, y;
	int height;
	int width;
	int size;
	int speedX, speedY;

	void update(Paddle &p);
	void draw();
};