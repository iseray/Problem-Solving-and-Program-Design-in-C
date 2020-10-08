/* Draw a pirate */
#include <graphics.h>

int
main(void)
{
	int midX, midY;
	int leftEyeX, rightEyeX, eyeY;
	int noseX, noseY;
	int headRadius;
	int smileRadius;
	int stepX; stepY;
	initwindow(500, 400, "Pirate - press key to close", 200, 150);
	
	/* Draw head. */
	midX = getmaxx() / 2;
	midY = getmaxy() / 2;
	headRadius = getmaxy() / 4;
	circle(midX, midY, headRadius);
}
