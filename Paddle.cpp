#include "Paddle.h"

#include "sfwdraw.h"

void Paddle::update()
{
	if (sfw::getKey('W'))
	{
		yPositionA += paddleSpeedUp;
		yPositionB += paddleSpeedUp;
	}

	if (sfw::getKey('S'))
	{
		yPositionB -= paddleSpeedDown;
		yPositionA -= paddleSpeedDown;
	}

	if (yPositionA > 500) 
	{
		paddleSpeedUp = 0;
	}
	if (yPositionA < 500)
	{
		paddleSpeedUp = paddleSpeed;
	}
	if (yPositionB < 100)
	{
		paddleSpeedDown = 0;
	}
	if (yPositionB > 100)
	{
		paddleSpeedDown = paddleSpeed;
	}
}

void Paddle::draw()
{
	sfw::drawLine(xPositionA, yPositionA, xPositionB, yPositionB, BLACK);
	sfw::drawLine(xPositionA + 1, yPositionA, xPositionB + 1, yPositionB, RED);
	sfw::drawLine(xPositionA + 2, yPositionA, xPositionB + 2, yPositionB, BLACK);
	sfw::drawLine(xPositionA + 3, yPositionA, xPositionB + 3, yPositionB, RED);
	sfw::drawLine(xPositionA + 4, yPositionA, xPositionB + 4, yPositionB, BLACK);
	sfw::drawLine(xPositionA + 5, yPositionA, xPositionB + 5, yPositionB, RED);
	sfw::drawLine(xPositionA + 6, yPositionA, xPositionB + 6, yPositionB, BLACK);
}