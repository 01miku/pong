#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>





void Splash::init(int a_font)
{
	font = a_font;
	pic3 = sfw::loadTextureMap("./res/web.jpg", 1, 1);
}


void Splash::play()
{
	timer = 10.0f;
}



void Splash::draw()
{
	char buffer[80];
	
	//sfw::drawString(font, buffer, 100, 100, 16, 16);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.0f), 80);
	sfw::drawTexture(pic3, 400, 300, 800, 600);
	//sprintf_s(buffer, "Press (S)tart or Wait: %f", timer, WHITE);
	sfw::drawString(font, "Welcome to Haunted Pong", 125, 425, 25, 25, 0, 0, WHITE);
	sfw::drawString(font, "How to PLay:", 125, 350, 15, 15, 0, 0, WHITE);
	sfw::drawString(font, "Move your Paddle UP with (W)", 125, 325, 15, 15, 0, 0, WHITE);
	sfw::drawString(font, "Move your Paddle DOWN with (S)", 125, 300, 15, 15, 0, 0, WHITE);
	sfw::drawString(font, "Try to score as many points as possible", 100, 250, 15, 15, 0, 0, WHITE);
	sfw::drawString(font, "by hitting the moving ball with your paddle", 100, 225, 15, 15, 0, 0, WHITE);
	sfw::drawString(font, "press ESC anytime during play to return to the menu", 15, 150, 15, 15, 0, 0, WHITE);
	sfw::drawString(font, "Cliff Wilson", 150, 100, 20, 20, 0, 0, WHITE);
	
}

void Splash::step()
{
	timer -= sfw::getDeltaTime();

	
}

APP_STATE Splash::next()
{
	if (timer < 0 || sfw::getKey('S'))
		return ENTER_OPTION;

	return SPLASH;
}
