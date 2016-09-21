#pragma once

#include "constdecl.h"

class Splash
{
	int font;
	float timer;
	float timer2;

	unsigned pic3;
	unsigned pic4;

public:
	void init(int a_font);

	void play();
	void play2();

	void draw();
	void step();

	APP_STATE next();


};
