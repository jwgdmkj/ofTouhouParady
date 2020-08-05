#include "bomb.h"

int index = 0;

void Bomb::setup()
{
	gifloader.load("bomb.gif");
}

void Bomb::update()
{
	if (ofGetElapsedTimeMillis() % 3)
	{
		index++;
		if (index > gifloader.pages.size() - 1) index = 0;
	}
}

void Bomb::draw()
{
	gifloader.pages[index].draw(0, 0);
}

/*
void ofApp::setup(){
	ofSetWindowShape(1280, 1080);
	ofSetFrameRate(60);
	gifloader.load("test.gif");
	ofEnableAlphaBlending();
	startTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update() {
	if (ofGetElapsedTimeMillis() - startTime >= gifDelay) {
		index++;
		if (index > gifloader.pages.size() - 1) {
			index = 0;
		}
		startTime = ofGetElapsedTimeMillis();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	ofSetColor(255, 255, 255, 255);
	ofImage img = gifloader.pages[index];

	ofPixels pix = img.getPixels();
	img.setFromPixels(pix);
	img.draw(100, 100);
}
*/