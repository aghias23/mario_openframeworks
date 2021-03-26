#pragma once

#include "ofImage.h"

using namespace std;

class Bricks
{
public:

	ofImage redBrick;
	ofImage qBrick;

	void loadBricks();
	void drawRedBrick(float x, float y);
	void drawQBrick(float x, float y);

	Bricks();
	~Bricks();
};

