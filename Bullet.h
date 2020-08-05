#pragma once
#ifndef Bullet_h
#define Bullet_h

#include <stdio.h>
#include <math.h>
#include "ofMain.h"

class Bullet{
public:
	ofPoint pos;
	float speed;
	float width;
	int from_player;
	ofPoint rightpos;
	ofPoint leftpos;

	void setup(int f_p, ofPoint p1, 
		float s, ofImage * bullet_img);
	void update();
	void draw();

	ofImage* img;
}; 

#endif