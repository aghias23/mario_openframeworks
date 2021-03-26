#include "Enemy.h"

Enemy::Enemy()
{
}

void Enemy::loadEnemy() {
	enemy.load("enemy.png");
}

float Enemy::enemyLoc(float x) {
	x = x + velocity;

	return x;
}

void Enemy::drawEnemy(float x) {
	enemy.draw(x, 625);
	rect.set(x, 625, 40, 40);
}

void Enemy::enemyLev0() {

	float xPos = 0;
	xPos = xPos + 5;

	int count = 1;
	drawEnemy(700 + xPos);
	count++;
		
}

Enemy::~Enemy()
{
}
