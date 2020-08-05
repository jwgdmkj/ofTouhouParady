#pragma once

#ifndef LevelController_h
#define LevelController_h

#include <stdio.h>

#include "ofMain.h"

class LevelController {
public:
	float start_time;
	float interval_time;

	void setup(float e);
	bool should_spawn();
};

#endif /* LevelController_hpp */