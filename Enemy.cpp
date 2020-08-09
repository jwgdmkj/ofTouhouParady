#include "Enemy.h"

//water setup
void Enemy::setup(float max_enemy_shoot_interval,
	ofImage * enemy_img)
{
	img = enemy_img;
	width = img->getWidth();
	height = img->getHeight();
	pos.x = middlepoint1;
	pos.y = middlepoint2 - 4 * height;
	speed = 8;
	//	amplitude = ofRandom(max_enemy_amplitude);
	shoot_interval = ofRandom(0.5, max_enemy_shoot_interval);

	start_shoot = ofGetElapsedTimef();
	backnforth = 0;
	enemymoving = -1;
}

void Enemy::update() {
	if (enemymoving == -1)
	{
		pos.y += speed;
		//	pos.y += amplitude * cos(ofGetElapsedTimef());
		//	pos.x += amplitude * sin(ofGetElapsedTimef());
		if (abs(pos.y - middlepoint2) < 8)
			enemymoving = 0;
	}
}

void Enemy::draw() {
	img->draw(pos.x - width / 2, pos.y - width / 2);
}

bool Enemy::time_to_shoot()
{
	if (ofGetElapsedTimef() - start_shoot > shoot_interval)
	{
		start_shoot = ofGetElapsedTimef();
		return true;
	}

	return false;
}
