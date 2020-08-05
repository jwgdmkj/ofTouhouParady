#pragma once
#ifndef Player_h
#define Player_h

#include <stdio.h>
#include "ofMain.h"

class Player {
public:

	ofPoint pos;
	ofPoint collisionpos;
	float width, height, speed, centerwidth;
	int lives;

	bool is_left_pressed, is_right_pressed, is_down_pressed,
		is_up_pressed, visible;

	void setup(ofImage * _img, ofPoint _pos, bool visiblecenter,
		ofImage * _center);
	void update(bool visible);
	void draw(bool visible);
	void shoot();

	bool check_canshoot();

	ofImage * img;
	ofImage * center;
};
#endif