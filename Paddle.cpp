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
	sfw::drawLine(xPositionA, yPositionA, xPositionA, yPositionB, BLACK);
}