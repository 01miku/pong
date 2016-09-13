#pragma once

class Paddle
{
public:
	float xPositionA = 20;
	float xPositionB = 20;
	float yPositionA = 0;
	float yPositionB = 100;

	int paddleSpeed = 4;
	int paddleSpeedUp = 4;
	int paddleSpeedDown = 4;

	int width;
	int length;
	int speed;

	int score;

	void update();
	void draw();
};