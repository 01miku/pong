#include "web.h"
#include "sfwdraw.h"
#include <cmath>

void Web::update()
{
	/*if (sfw::getKey('E')) 
	{
		yPositionAA += webSpeedUp;
		yPositionBB += webSpeedUp;
	}
	
	if (sfw::getKey('D')) 
	{
		yPositionBB -= webSpeedDown;
		yPositionAA -= webSpeedDown;
	}*/

	if (yPositionAA >= 600) 
	{
		webSpeed = fabsf(webSpeed) * -1;
	}
	if (yPositionAA <= 0) 
	{
		webSpeed = fabsf(webSpeed);
	}
	
	yPositionAA = yPositionAA + webSpeed;
	
	
	/*if (yPositionBB < 100)
	{
		webSpeedDown = 0;
	}
	if (yPositionBB > 100) 
	{
		webSpeedDown = webSpeed;
	}*/

}

void Web::draw()
{

	sfw::drawTexture(pic6, xPositionAA, yPositionAA, 100, 100);

}
