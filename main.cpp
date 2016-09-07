
#include "sfwdraw.h"
#include <cstdio>

int paddleSpeed = 4;
int paddleSpeedUp = 4;
int paddleSpeedDown = 4;

float ballSpeed = 5;

//
//struct Score 
//{
//	int points;
//	int leftWallScore;
//	int ballCollideWall;
//};



struct Paddle {
	float xPositionA = 20;
	float xPositionB = 20;
	float yPositionA = 0;
	float yPositionB = 100;
	int width;
	int length;
	int speed;
};

struct Ball {
	float x, y;
	int height;
	int width;
	int size;
	int speedX, speedY;
};

struct Boundary {
	int height;
	int width;
	int length;
	int drawBoundaryBottom;
	int drawBoundaryTop;
	int drawBoundaryLeft;
	int drawBoundaryRight;
};



void drawPaddle(const Paddle &p) 
{
	sfw::drawLine(p.xPositionA, p.yPositionA, p.xPositionA, p.yPositionB, WHITE);
	//sfw::drawLine(p.x, p.y, p.xB, p.yB, WHITE);
}

void drawBall(const Ball &ball) 
{
	sfw::drawCircle(ball.x, ball.y, ball.size, 25, BLUE);
}

void drawBoundaryBottom() 
{
	sfw::drawLine(10, 10, 800, 10, RED);
}

void drawBoundaryTop() 
{
	sfw::drawLine(800, 590, 0, 590, RED);
}

void drawBoundaryRight() 
{
	sfw::drawLine(790, 590, 790, 10, YELLOW);
}

void drawBoundaryLeft() 
{
	sfw::drawLine(10, 10, 10, 800, YELLOW);
}

void updateBall(Ball &ball) 
{
	ball.x += ball.speedX;
	ball.y += ball.speedY;
	// if the ball hits a boundary, flip the direction.

	if (ball.x > 800)
		ball.speedX *= -1;

	if (ball.x < 0)
		ball.speedX *= -1;

	if (ball.y > 600)
		ball.speedY *= -1;

	if (ball.y < 0)
		ball.speedY *= -1;
	//float ballVelocityX = ballSpeed;
	//float ballVelocityY = ballSpeed;
}

void updatePaddle(Paddle &p) 
{
	if (sfw::getKey('W'))
	{
		p.yPositionA += paddleSpeedUp;
		p.yPositionB += paddleSpeedUp;
	}

	if (sfw::getKey('S'))
	{
		p.yPositionB -= paddleSpeedDown;
		p.yPositionA -= paddleSpeedDown;
	}

}



void main()
{
	sfw::initContext(800, 600,"NSFW Draw");

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png",16,16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");

	float acc = 0;
	char c = '\0';

	Ball ball;
	ball.x = 400;
	ball.y = 300;
	ball.size = 12;
	ball.speedX = 5;
	ball.speedY = 4;

	Paddle p;
	p.xPositionA = 20;
	p.xPositionB = 20;
	p.yPositionA = 0;
	p.yPositionB = 100;

	Boundary bound;
	bound.drawBoundaryBottom;
	bound.drawBoundaryTop;
	bound.drawBoundaryRight;
	bound.drawBoundaryLeft;




	sfw::setBackgroundColor(BLACK);

	

	while (sfw::stepContext())
	{

		//drawPaddle(paddle1);
		//updatePaddle(paddle1);

		//isColliding(ball, paddle1);

		//checkBoundaries(ball, top, down, left, right);
		//
		//
		//sfw::drawString(f, " !\"#$%&'()*+,./-\n0123456789:;<=>?\n@ABCDEFGHIJKLMNO\nPQRSTUVWXYZ[\\]^_\n`abcdefghijklmno\npqrstuvwxyz{|}~", 0, 600, 48, 48, 0, ' ');
		//sfw::drawTexture(r, 0, 600, 800, 600, 0, false,0, 0x88888888);

		//acc += sfw::getDeltaTime();
		//sfw::drawString(d, "TIME 4 FUN", 400, 300, 48, 48, -acc*24,'\0',MAGENTA);

		//

		//sfw::drawString(d, "6", 400, 32, 24, 24);
		//sfw::drawString(d, "12", 400, 600 - 32, 24, 24);
		//sfw::drawString(d, "3", 800-32, 300, 24, 24);
		//sfw::drawString(d, "9", 32, 300, 24, 24);

		//if(sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
		//	sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2.5, sfw::getTextureHeight(u)/2.5,45,true,0,0x88ffffff);
		//else sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u)/2, sfw::getTextureHeight(u)/2);

		drawBall(ball);
		updateBall(ball);

		drawPaddle(p);
		updatePaddle(p);


		drawBoundaryBottom();

		drawBoundaryTop();

		drawBoundaryRight();

		drawBoundaryLeft();


		if (p.yPositionA > 500)
		{
			paddleSpeedUp = 0;
		}
		if (p.yPositionA < 500)
		{
			paddleSpeedUp = paddleSpeed;
		}
		if (p.yPositionB < 100)
		{
			paddleSpeedDown = 0;
		}
		if (p.yPositionB > 100)
		{
			paddleSpeedDown = paddleSpeed;
		}

		
		// if the ball's y is less than the A pos OR greater than the B pos
		if (ball.x < p.xPositionA && ball.y > p.yPositionA && ball.y < p.yPositionB)			// trying to collide ball with paddle
		{
			ball.x = p.xPositionA;
			ball.speedX *= -1;
		}

		if (ball.x < 0) // reset ball
		{
			ball.x = 400;
			ball.y = 300;
			//ball.speedX = 0;
			//ball.speedY = 0;
		}
	}



	sfw::termContext();
}