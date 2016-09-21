#include <iostream>
#include "GameState.h"


void GameState::init()
{	
	font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	pic = sfw::loadTextureMap("./res/redRum.png" , 1, 1);
	pic2 = sfw::loadTextureMap("./res/white.png", 1, 1);
	web.pic6 = sfw::loadTextureMap("./res/spider.png", 1, 1);
	
	
}

void GameState::play2() 
{
	sfw::setBackgroundColor(WHITE);

	ball.x = 400;
	ball.y = 300;
	ball.size = 12;
	ball.speedX = 5;
	ball.speedY = 3;
	ball.speedXX = 5;
	ball.speedYY = 3;

	//ball.bricksBroken = 0;

	p.xPositionA = 20;
	p.xPositionB = 20;
	p.yPositionA = 0;
	p.yPositionB = 100;

	//web.xPositionAA = 400;
	//web.xPositionBB = 200;
	//web.yPositionAA = 300;
	//web.yPositionBB = 0;



	p.score = 0;
	p.score2 = 0;
	timer2 = 4.0f;

		/*for (int i = 0; i < 30; ++i)
		{
			bricks[i].init(740 + (i / 10) * 20, (i % 10) * 58 + 4, 50);
		}*/
}


void GameState::update() 
{
	
	// update Ball
	ball.update(p, web);
	
	//update Paddle
	p.update();

	//update Web
	web.update();




	/*for (int i = 0; i < 30; ++i)
		bricks[i].update(ball, p);*/
	


	if (p.score % 10 == 0 && p.score != 0)
	{
		//sfw::setBackgroundColor(BLACK);
		sfw::drawTexture(pic, 400, 300, 800, 600);
	}

	timer2 --;

	if (timer2 <= 0) 
	{
		//sfw::setBackgroundColor(WHITE);
		sfw::drawTexture(pic2, 400, 300, 800, 600);
		timer2 = 4.0f;
	}


}

void GameState::draw()
{
	//draw Paddle
	p.draw();
	//draw Ball
	ball.draw();
	//draw Web
	web.draw();
	
	
	//draw Boundary Bottom
	sfw::drawLine(10, 10, 790, 10, BLACK);
	//draw Boundary Top
	sfw::drawLine(790, 590, 10, 590, BLACK);
	//draw Boundary Right
	sfw::drawLine(790, 590, 790, 10, RED);
	
	/*for (int i = 0; i < 30; ++i)
	{
		bricks[i].draw();
		sfw::drawLine(780, array[i], 780, (array[i] - 58), RED);
	}*/

	//draw Boundary Left
	sfw::drawLine(10, 10, 10, 590, BLACK);

	//draw Net
	sfw::drawLine(400, 20, 400, 60, BLACK);
	sfw::drawLine(400, 85, 400, 125, BLACK);
	sfw::drawLine(400, 150, 400, 190, BLACK);
	sfw::drawLine(400, 215, 400, 255, BLACK);
	sfw::drawLine(400, 280, 400, 320, BLACK);
	sfw::drawLine(400, 345, 400, 385, BLACK);
	sfw::drawLine(400, 410, 400, 450, BLACK);
	sfw::drawLine(400, 475, 400, 515, BLACK);
	sfw::drawLine(400, 540, 400, 580, BLACK);

	//draw Score
	char string[12];
	sprintf_s(string, "SCORE: %d", p.score);
	sfw::drawString(font, string, 320, 600, 20, 20, 0, ' ');
}
	APP_STATE GameState::next() 
	{
		if (sfw::getKey(KEY_ESCAPE))
			return ENTER_OPTION;
		
		return ACTION;
 
	}
