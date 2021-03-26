#pragma once

#include "ofMain.h"
#include "ofImage.h"
#include "Bricks.h"
#include "Stage.h"
#include "ofRectangle.h"
#include "ofTrueTypeFont.h"

using namespace std;

class Player
{
public:

	Stage stage;

	ofTrueTypeFont font;

	int timer;

	bool jump;

	float x = 100;
	float y = 605;
	float yLoc = y;
	
	
	float velocity = 10.0;
	float gravity = 9.81;

	ofRectangle player;

	ofImage playerImage;
	ofImage playerImageRight[3];
	ofImage playerImageLeft[3];
	ofImage playerImageJump;



	void loadPlayerImage();

	void drawPlayer(float xPos, float yPos, bool left, bool right, bool up);

	float playerRun(bool left, bool right);
	float playerJump(bool up);

	Player();
	~Player();
};

