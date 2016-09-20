#pragma once

class Ball;

struct Brick
{
	float x, y, size;
	bool isAlive;

	void init(float x, float y, float size);
	void draw();
	void update(Ball &b, Paddle &p);
};