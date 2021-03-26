#pragma once

#include "ofImage.h"
#include "ofRectangle.h"

class Enemy
{
public:

	ofImage enemy;
	ofRectangle rect;


	void loadEnemy();

	float velocity = 1;

	void drawEnemy(float x);

	float enemyLoc(float x);

	void enemyLev0();

	Enemy();
	~Enemy();
};

