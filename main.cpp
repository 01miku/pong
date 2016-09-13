
#include "sfwdraw.h"
#include "GameState.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

int paddleSpeed = 4;
int paddleSpeedUp = 4;
int paddleSpeedDown = 4;

float ballSpeed = 5;

int playerScore = 00;


struct Paddle 
{
	float xPositionA = 20;
	float xPositionB = 20;
	float yPositionA = 0;
	float yPositionB = 100;
	int width;
	int length;
	int speed;
};

struct Ball 
{
	float x, y;
	int height;
	int width;
	int size;
	int speedX, speedY;
};

struct Boundary 
{
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
	sfw::drawLine(790, 590, 790, 10, RED);
}

void drawBoundaryLeft() 
{
	sfw::drawLine(10, 10, 10, 800, YELLOW);
}

void drawNet() 
{
	sfw::drawLine(400, 20, 400, 60, WHITE);
	sfw::drawLine(400, 85, 400, 125, WHITE);
	sfw::drawLine(400, 150, 400, 190, WHITE);
	sfw::drawLine(400, 215, 400, 255, WHITE);
	sfw::drawLine(400, 280, 400, 320, WHITE);
	sfw::drawLine(400, 345, 400, 385, WHITE);
	sfw::drawLine(400, 410, 400, 450, WHITE);
	sfw::drawLine(400, 475, 400, 515, WHITE);
	sfw::drawLine(400, 540, 400, 580, WHITE);
}

void drawScore( unsigned int font ) {
	char string[12];
	sprintf_s(string, "SCORE: %d", playerScore);
	sfw::drawString(font, string, 320, 600, 20, 20, 0, ' ');
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
	
	srand(time(0));
	
	sfw::initContext(800, 600,"NSFW Draw");

	GameState game;
	

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned int d = sfw::loadTextureMap("./res/fontmap.png",16,16);

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

	
		drawBall(ball);
		updateBall(ball);

		drawPaddle(p);
		updatePaddle(p);


		drawBoundaryBottom();

		drawBoundaryTop();

		drawBoundaryRight();

		drawBoundaryLeft();

		drawNet();

		drawScore(f);


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

		if (ball.x < 0) // reset ball and subtract score
		{
			ball.x = 400;
			ball.y = rand()%600;

		}
		
		if (ball.x > 800) 
		{
			playerScore = playerScore + 1;
		}
	
	
	}



	sfw::termContext();
}