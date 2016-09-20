#pragma once

class Paddle
{
public:
	float xPositionA = 20;
	float xPositionB = 20;
	float yPositionA = 0;
	float yPositionB = 100;

	int paddleSpeed = 5;
	int paddleSpeedUp = 5;
	int paddleSpeedDown = 5;

	int width;
	int length;
	int speed;

	int score;
	int score2;

	void update();
	void draw();
};