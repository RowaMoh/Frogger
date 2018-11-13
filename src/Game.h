/*
 * Game.h
 *
 *  Created on: Feb 26, 2016
 *      Author: Kian
 */

#ifndef GAME_H_
#define GAME_H_
#include "Factory.h"
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

class Game {

private:

public:
	Game(Au::Factory*);
	~Game();
	void start();
;

private:
	bool gRunning;
	float lane1 = 75;
	float lane2 = 120;
	float lane3 = 210;
	float lane4 = 255;
	float lane5 = 345;
	float lane6 = 390;
	Au::Factory* Fact;
	std::stringstream timeText;

};

#endif /* GAME_H_ */
