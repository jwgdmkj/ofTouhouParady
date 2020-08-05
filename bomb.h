#pragma once

#include "ofMain.h"
#include "ofxGif.h"

class Bomb{
public:
	void setup();
	void update();
	void draw();

	ofxGIF::fiGifLoader gifloader;
	int index = 0;
	float gifDelay = 100;
	float startTime;
};