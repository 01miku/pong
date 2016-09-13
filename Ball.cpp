#include "Ball.h"

#include "sfwdraw.h"
#include "Paddle.h"
#include <random>

void Ball::update(Paddle &p)
{
	x += speedX;
	y += speedY;
	// if the ball hits a boundary, flip the direction.

	if (x > 800)
	{
		speedX *= -1;
		p.score += 1;
	}

	// hit the left wall
	if (x < 0)
	{
		speedX *= -1;
		x = 400;
		y = rand() % 600;
	}

	if (y > 600)
		speedY *= -1;

	if (y < 0)
		speedY *= -1;

	if (x < p.xPositionA &&
		y > p.yPositionA &&
		y < p.yPositionB)
	{
		x = p.xPositionA;
		speedX *= -1;
	}
}

void Ball::draw()
{
	sfw::drawCircle(x, y, size, 25, BLUE);
}