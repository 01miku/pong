#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>

void Splash::init(int a_font)
{
	font = a_font;
}

void Splash::play()
{
	timer = 3.0f;
}

void Splash::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Press 'P' or Wait for Splash Time: %f", timer);
	sfw::drawString(font, buffer, 100, 100, 16, 16);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.0f), 80);
}

void Splash::step()
{
	timer -= sfw::getDeltaTime();
	
}

APP_STATE Splash::next()
{
	if (timer < 0 || sfw::getKey('P'))
		return ENTER_OPTION;

	return SPLASH;
}
