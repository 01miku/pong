#pragma once

class Web {

public:
	unsigned pic6;
	
	float xPositionAA = 400;
	//float xPositionBB = 400;
	float yPositionAA = 300;
	//float yPositionBB = 100;
	

	int webSpeed = 1;
	//int webSpeedUp = 5;
	//int webSpeedDown = 5;

	void update();
	void draw();
};