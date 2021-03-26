#include "Stage.h"

Stage::Stage()
{
}

void Stage::loadImages() {
	for (int i = 0; i < 10; i++) {
		char str[100];
		sprintf(str, "screen%d.png", i);
		stage[i].load(str);
	}
	enemy.loadEnemy();
	font.load(OF_TTF_SANS, 75);
}

void Stage::stageLoad(float xPos) {

	if (count == 0) {
		count = stageLoad0(xPos);
	}
	else if (count == 1) {
		count = stageLoad1(xPos);
	}
	else if (count == 2) {
		count = stageLoad2(xPos);
	}
	else if (count == 3) {
		count = stageLoad3(xPos);
	}
	else if (count == 4) {
		count = stageLoad4(xPos);
	}
	else if (count == 5) {
		count = stageLoad5(xPos);
	}
	else if (count == 6) {
		count = stageLoad6(xPos);
	}
	else if (count == 7) {
		count = stageLoad7(xPos);
	}
	else if (count == 8) {
		count = stageLoad8(xPos);
	}
	else if (count == 9) {
		stageLoad9(xPos);
		if (ofGetElapsedTimeMillis() > 100) {
		//	system("pause");
		}
	}
	else if (count == 10) {
		stageLoad10();
		if (ofGetElapsedTimeMillis() > 100) {
		//	system("pause");
		}
	}

}

float Stage::enemyLoc(float enemyX) {
	enemyX = enemy.enemyLoc(enemyX);
	return enemyX;
}

int Stage::stageLoad0(float xPos) {


	stage[0].draw(0, 0);

	enemyX[0] = enemyLoc(enemyX[0]);

	if (is_visible_0 == 1) {
		enemy.drawEnemy(enemyX[0]);
	}

	if (enemy.rect.intersects(rect[3]) == 1) {
		enemy.velocity = enemy.velocity * -1;
	}

	rect[0].set(210, 462, 50, 50);

	rect[1].set(415, 462, 250, 50);

	rect[2].set(516, 258, 50, 50);

	rect[3].set(824, 563, 100, 100);



	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad1(float xPos) {


	stage[1].draw(0, 0);

	enemyX[1] = enemyLoc(enemyX[1]);

	if (is_visible_1 == 1) {
		enemy.drawEnemy(enemyX[1]);
	}

	if (enemy.rect.intersects(rect[4]) == 1) {
		enemy.velocity = enemy.velocity * -1;
	}
	if (enemy.rect.intersects(rect[5]) == 1) {
		enemy.velocity = enemy.velocity * -1;
	}

	rect[4].set(312, 512, 100, 155);
	rect[5].set(720, 460, 102, 205);
	
	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad2(float xPos) {


	stage[2].draw(0, 0);

	enemyX[2] = enemyLoc(enemyX[2]);

	if (is_visible_2 == 1) {
		enemy.drawEnemy(enemyX[2]);
	}

	if ((enemy.rect.intersects(rect[6]) == 1) || (enemy.rect.intersects(rect[7]) == 1)) {
		enemy.velocity = enemy.velocity * -1;
	}


	rect[6].set(295, 460, 102, 205);
	rect[7].set(860, 460, 102, 205);

	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad3(float xPos) {

	stage[3].draw(0, 0);

	enemyX[3] = enemyLoc(enemyX[3]);

	if (is_visible_3 == 1) {
		enemy.drawEnemy(enemyX[3]);
	}

	if ((enemy.rect.intersects(rect[6]) == 1) || (enemy.rect.intersects(rect[7]) == 1)) {
		enemy.velocity = enemy.velocity * -1;
	}

	rect[8].set(230, 660, 100, 103);
	rect[9].set(639, 462, 155, 55);
	rect[10].set(793, 256, 250, 55);

	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad4(float xPos) {

	stage[4].draw(0, 0);


	enemyX[4] = enemyLoc(enemyX[4]);

	if (is_visible_5 == 1) {
		enemy.drawEnemy(enemyX[4]);
	}

	if ((enemy.rect.intersects(rect[6]) == 1) || (enemy.rect.intersects(rect[7]) == 1)) {
		enemy.velocity = enemy.velocity * -1;
	}


	rect[11].set(0, 256, 219, 50);
	rect[12].set(371, 256, 205, 50);
	rect[13].set(525, 460, 50, 50);
	rect[14].set(835, 460, 100, 50);
	rect[15].set(118, 660, 150, 105);

	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad5(float xPos) {

	stage[5].draw(0, 0);


	enemyX[5] = enemyLoc(enemyX[5]);

	if (is_visible_5 == 1) {
		enemy.drawEnemy(enemyX[5]);
	}

	if ((enemy.rect.intersects(rect[6]) == 1) || (enemy.rect.intersects(rect[7]) == 1)) {
		enemy.velocity = enemy.velocity * -1;
	}


	rect[16].set(75, 460, 50, 50);
	rect[17].set(225, 460, 50, 50);
	rect[18].set(380, 460, 50, 50);
	rect[19].set(688, 460, 50, 50);
	rect[20].set(229, 254, 50, 50);
	rect[21].set(841, 254, 150, 50);

	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad6(float xPos) {

	stage[6].draw(0, 0);


	enemyX[6] = enemyLoc(enemyX[6]);

	if (is_visible_6 == 1) {
		enemy.drawEnemy(enemyX[6]);
	}

	if (enemy.rect.intersects(rect[27]) == 1) {
		enemy.velocity = enemy.velocity * -1;
	}

	rect[22].set(253, 462, 100, 50);
	rect[23].set(205, 254, 200, 50);

	rect[24].set(662, 462, 50, 200);
	rect[25].set(612, 512, 50, 150);
	rect[26].set(562, 562, 50, 100);
	rect[27].set(512, 612, 50, 50);

	rect[28].set(819, 462, 50, 200);
	rect[29].set(869, 512, 50, 150);
	rect[30].set(919, 562, 50, 100);
	rect[31].set(969, 612, 50, 50);

	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad7(float xPos) {

	stage[7].draw(0, 0);


	enemyX[7] = enemyLoc(enemyX[7]);

	if (is_visible_7 == 1) {
		enemy.drawEnemy(enemyX[7]);
	}

	if ((enemy.rect.intersects(rect[39]) == 1) || (enemy.rect.intersects(rect[41]) == 1)) {
		enemy.velocity = enemy.velocity * -1;
	}


	rect[32].set(266, 462, 100, 200);
	rect[33].set(216, 512, 50, 150);
	rect[34].set(166, 562, 50, 100);
	rect[35].set(116, 612, 50, 50);

	rect[36].set(472, 462, 50, 200);
	rect[37].set(522, 512, 50, 150);
	rect[38].set(572, 562, 50, 100);
	rect[39].set(622, 612, 50, 50);

	rect[40].set(371, 600, 100, 200);

	rect[41].set(882, 562, 100, 100);

	if (xPos >= 1024) count++;
	return count;
}

int Stage::stageLoad8(float xPos) {

	stage[8].draw(0, 0);


	enemyX[8] = enemyLoc(enemyX[8]);

	if (is_visible_8 == 1) {
		enemy.drawEnemy(enemyX[8]);
	}

	if ((enemy.rect.intersects(rect[43]) == 1) || (enemy.rect.x >= 984)) {
		enemy.velocity = enemy.velocity * -1;
	}

	rect[42].set(191, 562, 100, 100);

	rect[43].set(652, 256, 100, 400);
	rect[44].set(602, 306, 100, 350);
	rect[45].set(552, 356, 100, 300);
	rect[46].set(502, 406, 100, 250);
	rect[47].set(442, 456, 100, 200);
	rect[48].set(392, 512, 100, 150);
	rect[49].set(342, 562, 100, 100);
	rect[50].set(292, 612, 100, 50);

	if (xPos >= 1024) count++;
	return count;
}

void Stage::stageLoad9(float xPos) {

	stage[9].draw(0, 0);
	font.drawString(std::string(OF_TTF_SANS) = "CONGRATULATIONS YOU WON!", 50, 100);
	char str[255]; // an array of chars
	sprintf(str, "Score: %f", score);

//	font.drawString(str, 50, 200);
}

void Stage::stageLoad10() {

	ofSetBackgroundColor(0, 0, 0);

	font.drawString(std::string(OF_TTF_SANS) = "SORRY YOU LOST", 50, ofGetHeight()/2);

	char str[255]; // an array of chars
	sprintf(str, "Score: %f", score);

//	font.drawString(str, 50, ofGetHeight()/2 + 200);
	

}

Stage::~Stage()
{
}
