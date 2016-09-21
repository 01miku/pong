#pragma once

#include  "constdecl.h"

class Option
{
	int font;
	float timer;
	int select;

	unsigned pic3;
	unsigned pic4;

public:
	void init(int a_font);

	void play();
	void draw();
	void step();

	APP_STATE next();
};
