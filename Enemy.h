#pragma once
#include <stdio.h>
#include "ofMain.h"

class Enemy {
public:

	ofPoint pos;
	float speed;
	float amplitude;
	float width;
	float height;

	float start_shoot;
	float shoot_interval;

	void setup(float max_enemy_shoot_interval,
		ofImage * enemy_image);
	void update();
	void draw();
	bool time_to_shoot();
	float leftscreen = ofGetWidth() / 20;
	float rightscreen = 55 * (ofGetWidth() / 100);
	float upscreen = ofGetHeight() / 13;
	float downscreen = 11 * (ofGetHeight() / 13);
	float middlepoint1 = leftscreen + (rightscreen) / 2;
	float middlepoint2 = 3 * upscreen;
	int enemymoving = -1;
	unsigned int enemyhealth = 100;
	unsigned int nowhealth = enemyhealth;

	ofImage * img;
	int backnforth;
};