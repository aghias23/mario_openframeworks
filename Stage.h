#pragma once

#include "ofMain.h"
#include "ofImage.h"
#include "ofRectangle.h"
#include "ofTrueTypeFont.h"
#include "Enemy.h"

using namespace std;

class Stage
{
public:

	ofImage stage[10];

	ofRectangle rect[51];

	ofTrueTypeFont font;

	Enemy enemy;

	int score = 0;

	float velocity = 5;

	float enemyX[10] = {700, 500, 500, 500, 500, 500, 300, 800, 800, 500};
	float velEnemy = 5;

	float loc = 1;

	int count = 0;

	void loadImages();

	bool is_visible_0 = 1;
	bool is_visible_1 = 1;
	bool is_visible_2 = 1;
	bool is_visible_3 = 1;
	bool is_visible_4 = 1;
	bool is_visible_5 = 1;
	bool is_visible_6 = 1;
	bool is_visible_7 = 1;
	bool is_visible_8 = 1;
	bool is_visible_9 = 1;

	float enemyLoc(float enemyX);

	void stageLoad(float xPos);

	int stageLoad0(float xPos);
	int stageLoad1(float xPos);
	int stageLoad2(float xPos);
	int stageLoad3(float xPos);
	int stageLoad4(float xPos);
	int stageLoad5(float xPos);
	int stageLoad6(float xPos);
	int stageLoad7(float xPos);
	int stageLoad8(float xPos);
	void stageLoad9(float xPos);
	void stageLoad10();

	Stage();
	~Stage();
};

