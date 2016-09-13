#include "sfwdraw.h"
#include "GameState.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

void main()
{
	srand(time(0));
	
	sfw::initContext(800, 600,"NSFW Draw");

	GameState game;
	game.init();
	
	while (sfw::stepContext())
	{
		game.update();
		game.draw();
	}

	sfw::termContext();
}