#include "Player.h"

Player::Player()
{
}

void Player::loadPlayerImage() {
	char str[100];
	playerImage.load("mario.png");

	for (int i = 0; i < 3; i++) {
		sprintf(str, "mariomoveright%d.png", i);
		playerImageRight[i].load(str);
	}

	for (int i = 0; i < 3; i++) {
		sprintf(str, "mariomoveleft%d.png", i);
		playerImageLeft[i].load(str);
	}

	playerImageJump.load("mariojump.png");

	stage.loadImages();
	font.load(OF_TTF_SANS, 75);
}

void Player::drawPlayer(float xPos, float yPos, bool left, bool right, bool up) {

	stage.stageLoad(xPos);

	if (ofGetElapsedTimeMillis() - timer >= 10) {

		if (right == 1) {
			if (ofGetElapsedTimeMillis() <= 100) {
				playerImageRight[0].draw(xPos, yPos);
			}
			if ((ofGetElapsedTimeMillis() > 100) && (ofGetElapsedTimeMillis() - timer <= 200)) {
				playerImageRight[1].draw(xPos, yPos);
			}
			if ((ofGetElapsedTimeMillis() > 200) && (ofGetElapsedTimeMillis() - timer <= 300)) {
				playerImageRight[2].draw(xPos, yPos);
				ofResetElapsedTimeCounter();
			}
			timer = ofGetElapsedTimeMillis();
		}

		if (left == 1) {
			if (ofGetElapsedTimeMillis() <= 100) {
				playerImageLeft[0].draw(xPos, yPos);
			}
			if ((ofGetElapsedTimeMillis() > 100) && (ofGetElapsedTimeMillis() - timer <= 200)) {
				playerImageLeft[1].draw(xPos, yPos);
			}
			if ((ofGetElapsedTimeMillis() > 200) && (ofGetElapsedTimeMillis() - timer <= 300)) {
				playerImageLeft[2].draw(xPos, yPos);
				ofResetElapsedTimeCounter();
			}
			timer = ofGetElapsedTimeMillis();
		}

		if (up == 1) {
			playerImageJump.draw(xPos, yPos);
		}

		if ((right == 0) && (left == 0) && (up == 0)) playerImage.draw(xPos, yPos);

		timer = ofGetElapsedTimeMillis();
	}

	player.set(xPos, yPos, 38, 50);

	if (yPos >= 768) {
		stage.stageLoad9(xPos);
	}

}

float Player::playerRun(bool left, bool right) {

	float xPos;
	int count = 1;

	if (ofGetElapsedTimeMillis() >= 10 * count) {

		if (right == 1) {
			x = x + 5;
		}
		if (left == 1) {

			if (x >= 0) {
				x = x - 5;
			}
			else {
				x = 0;
			}
		}
		if (x >= 1027) {
			x = 0;
		}

		count++;
	}

	xPos = x;
	return xPos;
}

float Player::playerJump(bool up) {
	float yPos;
	int count = 1;
	jump = 0;
	float jumpHeight = 210;

	if (ofGetElapsedTimeMillis() >= 10 * count) {

		if (up == 1) {
			if ((y >= yLoc - jumpHeight) && (jump == 0)) {
				y = y - 10;

				if ((y == yLoc - jumpHeight) && (jump == 0)) {
					up = 0;
					jump = 1;
				}
			}
		}

		if (up == 0) {
			
			if (stage.count == 0) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_0 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_0) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[0].intersects(player) == 1) yLoc = 400;
				else if (stage.rect[1].intersects(player) == 1) yLoc = 400;
				else if (stage.rect[2].intersects(player) == 1) yLoc = 210;
				else if (stage.rect[3].intersects(player) == 1) yLoc = 510;
				else yLoc = 605;
			}
			if (stage.count == 1) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_1 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_1) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[4].intersects(player) == 1) yLoc = 460;
				else if (stage.rect[5].intersects(player) == 1) yLoc = 410;
				else yLoc = 605;
			}
			if (stage.count == 2) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_2 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_2) == 1) {
						stage.count = 10;
					}

				}
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_2 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_2) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[6].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[7].intersects(player) == 1) yLoc = 410;
				else yLoc = 605;
			}
			if (stage.count == 3) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_3 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_3) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[8].intersects(player) == 1) {
					yLoc = 780;
					stage.count = 10;
				}
				else if (stage.rect[9].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[10].intersects(player) == 1) yLoc = 190;
				else yLoc = 605;
			}
			if (stage.count == 4) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_4 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_4) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[11].intersects(player) == 1) yLoc = 190;
				else if (stage.rect[12].intersects(player) == 1) yLoc = 190;
				else if (stage.rect[13].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[14].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[15].intersects(player) == 1) {
					yLoc = 780;
					if (y > 750) {
						stage.count = 10;
					}
				}
				else yLoc = 605;
			}
			if (stage.count == 5) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_5 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_5) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[16].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[17].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[18].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[19].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[20].intersects(player) == 1) yLoc = 200;
				else if (stage.rect[21].intersects(player) == 1) yLoc = 200;

				else yLoc = 605;
			}
			if (stage.count == 6) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_6 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_6) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[22].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[23].intersects(player) == 1) yLoc = 200;
				else if (stage.rect[24].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[25].intersects(player) == 1) yLoc = 460;
				else if (stage.rect[26].intersects(player) == 1) yLoc = 510;
				else if (stage.rect[27].intersects(player) == 1) yLoc = 560;
				else if (stage.rect[28].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[29].intersects(player) == 1) yLoc = 460;
				else if (stage.rect[30].intersects(player) == 1) yLoc = 510;
				else if (stage.rect[31].intersects(player) == 1) yLoc = 560;

				else yLoc = 605;
			}
			if (stage.count == 7) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_7 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_7) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[32].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[33].intersects(player) == 1) yLoc = 460;
				else if (stage.rect[34].intersects(player) == 1) yLoc = 510;
				else if (stage.rect[35].intersects(player) == 1) yLoc = 560;
				else if (stage.rect[36].intersects(player) == 1) yLoc = 410;
				else if (stage.rect[37].intersects(player) == 1) yLoc = 460;
				else if (stage.rect[38].intersects(player) == 1) yLoc = 510;
				else if (stage.rect[39].intersects(player) == 1) yLoc = 560;
				else if (stage.rect[40].intersects(player) == 1) {
					yLoc = 780;
					stage.count = 10;
				}
				else if (stage.rect[41].intersects(player) == 1) yLoc = 510;

				else yLoc = 605;
			}
			if (stage.count == 8) {
				if (player.intersects(stage.enemy.rect) == 1) {
					if (player.y + 10 < stage.enemy.rect.y) {
						stage.is_visible_8 = 0;
						stage.score = stage.score + 100;
					}
					if ((player.y + 10 >= stage.enemy.rect.y) && (stage.is_visible_8) == 1) {
						stage.count = 10;
					}

				}
				if (stage.rect[43].intersects(player) == 1) yLoc = 150;
				else if (stage.rect[44].intersects(player) == 1) yLoc = 230;
				else if (stage.rect[45].intersects(player) == 1) yLoc = 290;
				else if (stage.rect[46].intersects(player) == 1) yLoc = 350;
				else if (stage.rect[47].intersects(player) == 1) yLoc = 400;
				else if (stage.rect[48].intersects(player) == 1) yLoc = 450;
				else if (stage.rect[49].intersects(player) == 1) yLoc = 500;
				else if (stage.rect[50].intersects(player) == 1) yLoc = 550;
				else if (stage.rect[42].intersects(player) == 1) yLoc = 510;


				else yLoc = 605;
			}

			if ((stage.count == 9) || (stage.count == 10)) {
				char str[255]; // an array of chars
				sprintf(str, "Score: %f", stage.score);

				font.drawString(str, 50, 200);
			}

			if (y <= yLoc) {
				y = y + 10;
			}
		}

		count++;
	}



	yPos = y;
	return yPos;
}



Player::~Player()
{
}
