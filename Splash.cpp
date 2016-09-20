#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>



void Splash::init(int a_font)
{
	font = a_font;
	sfw::setBackgroundColor(CYAN);
}


void Splash::play()
{
	timer = 10.0f;
}



void Splash::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Press (S)tart or Wait: %f", timer, BLACK);
	sfw::drawString(font, buffer, 100, 100, 16, 16);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.0f), 80);
	
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
