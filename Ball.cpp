#include "Ball.h"

#include "sfwdraw.h"
#include "Paddle.h"
#include <random>

void Ball::update(Paddle &p)
{
	x += speedX;
	y += speedY;


	// if the ball hits a boundary, flip the direction.

	if (x > 790 - size)
	{
		if (p.score2 >= 3 && speedX <= 20)
		{
			p.score2 = 0;
			speedX += 1;
			if (speedY > 0)
				speedY += 1;
			else
				speedY -= 1;
		}

		x = 790 - size;
		speedX *= -1;
		p.score += 1;
		p.score2 += 1;
	}

	if (x < 0)
	{
		speedX *= -1;
		x = 400;
		y = rand() % 600;
		p.score = 0;
		speedX = 3;
		speedY = 3;
		
	}

	if (y > 590 - size) 
	{
		y = 590 - size;
		speedY *= -1;
	}
	if (y < 10 + size) 
	{
		y = 10 + size;
		speedY *= -1;
	}
	if ((x - size) < (p.xPositionA + 6) &&
		(y + size) > p.yPositionA &&
		(y - size) < p.yPositionB)
	{
		x = p.xPositionA + 6 + size;
		speedX *= -1;
	}


}

void Ball::draw()
{
	sfw::drawCircle(x, y, size, 25, BLACK);
}