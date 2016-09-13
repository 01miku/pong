#include <iostream>
#include "GameState.h"

void GameState::init()
{
	font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);

	ball.x = 400;
	ball.y = 300;
	ball.size = 12;
	ball.speedX = 5;
	ball.speedY = 4;

	p.xPositionA = 20;
	p.xPositionB = 20;
	p.yPositionA = 0;
	p.yPositionB = 100;

	p.score = 0;
}

void GameState::update() 
{
	
	// update Ball
	ball.update(p);
	
	//update Paddle
	p.update();
}

void GameState::draw() 
{
	//draw Paddle
	p.draw();
	//draw Ball
	ball.draw();
	//draw Boundary Bottom
	sfw::drawLine(10, 10, 800, 10, RED);
	//draw Boundary Top
	sfw::drawLine(800, 590, 0, 590, RED);
	//draw Boundary Right
	sfw::drawLine(790, 590, 790, 10, RED);
	//draw Boundary Left
	sfw::drawLine(10, 10, 10, 800, YELLOW);
	
	//draw Net
	sfw::drawLine(400, 20, 400, 60, WHITE);
	sfw::drawLine(400, 85, 400, 125, WHITE);
	sfw::drawLine(400, 150, 400, 190, WHITE);
	sfw::drawLine(400, 215, 400, 255, WHITE);
	sfw::drawLine(400, 280, 400, 320, WHITE);
	sfw::drawLine(400, 345, 400, 385, WHITE);
	sfw::drawLine(400, 410, 400, 450, WHITE);
	sfw::drawLine(400, 475, 400, 515, WHITE);
	sfw::drawLine(400, 540, 400, 580, WHITE);
	
	//draw Score
	char string[12];
	sprintf_s(string, "SCORE: %d", p.score);
	sfw::drawString(font, string, 320, 600, 20, 20, 0, ' ');


}