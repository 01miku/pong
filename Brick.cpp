#include "Ball.h"
#include "sfwdraw.h"
#include "Brick.h"
#include "Paddle.h"


void Brick::init(float a_x, float a_y, float a_size)
{
	x = a_x;
	y = a_y;
	size = a_size;
	isAlive = true;
}

void Brick::draw()
{
	if(isAlive)
		sfw::drawLine(x, y, x, y + size, RED);
}

void Brick::update(Ball &b, Paddle &p)
{
	if (isAlive)
	{
		if ((b.x + b.size) > x && // if we collided
			(b.y - b.size >  y) && b.y + b.size < (y + size))
		{
			b.bricksBroken++;
			p.score += 1;
			p.score2 += 1;
			b.x = x - b.size;	// reset the ball to the front of the brick
			b.speedX *= -1;		// flip its direction
			isAlive = false;	// flag this brick as dead.
			if (p.score2 >= 3 && b.speedX <= 20)
			{
				p.score2 = 0;
				b.speedX += 1;
				if (b.speedY > 0)
					b.speedY += 1;
				else
					b.speedY -= 1;
			}
		}
	}
}
