#include "Bricks.h"



Bricks::Bricks()
{
}

void Bricks::loadBricks() {
	redBrick.load("brickred.png");
	qBrick.load("qBrick.png");
}

void Bricks::drawRedBrick(float x, float y) {
	redBrick.draw(x, y);
}

void Bricks::drawQBrick(float x, float y) {
	qBrick.draw(x, y);
}

Bricks::~Bricks()
{
}
