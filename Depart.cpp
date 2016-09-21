#include "Depart.h"
#include "sfwdraw.h"
#include <cstdio>



void Depart::init(int a_font)
{
	font = a_font;
	//sfw::setBackgroundColor(RED);
}

void Depart::play()
{
	timer = 10.0f;
}


void Depart::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Press 'Q' or Wait for Depart Time: %f", timer);
	sfw::drawString(font, buffer, 100, 100, 16, 16);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.f), 80);
	sfw::drawString(font, "You Scared?", 125, 425, 25, 25, 0, 0, WHITE);
	sfw::setBackgroundColor(RED);
}

void Depart::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Depart::next()
{
	if (timer < 0 || sfw::getKey('Q'))
		return TERMINATE;
	
	return DEPART;
}
