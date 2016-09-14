#include "Option.h"
#include "sfwdraw.h"
#include <cstdio>

void Option::init(int a_font)
{
	font = a_font;
}

void Option::play()
{
	select = 0; timer = 1.0f;
}

void Option::draw()
{
	sfw::drawString(font, "Press enter on the selection:", 80, 140, 16, 16, 0, 0, BLUE);

	sfw::drawString(font, "GOTO (G)AME!", 100, 120, 16, 16, 0, 0, select == 1 ? MAGENTA : WHITE);
	sfw::drawString(font, "GOTO (D)epart!", 100, 100, 16, 16, 0, 0, select == 0 ? MAGENTA : WHITE);

	sfw::drawLine(100, 80, 100 + 240 * (timer / 1.f), 80);
}

void Option::step()
{
	timer -= sfw::getDeltaTime();
	if (timer < 0)
	{
		timer = 1.f;
		select = 1 - select; // flip selection between 0 and 1
	}
}

APP_STATE Option::next()
{
	if (sfw::getKey('G')) return ENTER_ACTION;
	if (sfw::getKey('D')) return ENTER_DEPART;

	if (sfw::getKey(KEY_ENTER))
	{
		if (select == 0) return ENTER_DEPART;
		if (select == 1) return ENTER_SPLASH;
	}
	return OPTION;
}
