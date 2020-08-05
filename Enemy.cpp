#include "Enemy.h"

//water setup
void Enemy::setup(float max_enemy_amplitude,
	float max_enemy_shoot_interval, ofImage * enemy_img) 
{
	pos.x = ofRandom(ofGetWidth());
	pos.y = 200;
	img = enemy_img;
	width = img->getWidth();
	speed = 3;
	amplitude = ofRandom(max_enemy_amplitude);
	shoot_interval = ofRandom(0.5, max_enemy_shoot_interval);

	start_shoot = ofGetElapsedTimef();
	backnforth = 0;
}

void Enemy::update() {
	pos.y += amplitude * cos(ofGetElapsedTimef());
	pos.x += amplitude * sin(ofGetElapsedTimef());
}

void Enemy::draw(){
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
