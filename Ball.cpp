#include "Ball.h"
#include "GameState.h"
#include "sfwdraw.h"
#include "Paddle.h"
#include <random>
#include "web.h"
#include <cmath>


void Ball::update(Paddle &p, Web &web)
{
	x += speedX;
	y += speedY;



	// if the ball hits a boundary, flip the direction.

	if (x > 790 - size)
	{
		if (p.score2 >= 5 && speedX <= 25)
		{
			p.score2 = 0;
			speedX += 2;
			if (speedY > 0)
				speedY += 2;
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
		speedX = 5;
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



	if ((pow((x - web.xPositionAA), 2) + (pow((y - web.yPositionAA), 2)) <= 3844))
	{
		if (lock == 0)
		{
			speedXX = speedX;
			speedYY = speedY;
			lock = 1;
		}

		speedX = speedXX * 0.1f;
		speedY = speedYY * 0.1f;
	}

	if ((pow((x - web.xPositionAA), 2) + (pow((y - web.yPositionAA), 2)) > 3844) && lock == 1)
	{
		lock = 0;
		speedX = speedXX;
		speedY = speedYY;
	} 
}

void Ball::draw()
{
	sfw::drawCircle(x, y, size, 25, BLACK);
}