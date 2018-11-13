/*
 * Game.h
 *
 *  Created on: Feb 26, 2016
 *      Author: Kian
 */

#ifndef GAME_H_
#define GAME_H_

class Game {

private:

public:
	Game();
	~Game();
	void start();
	bool running();
	void quit();

private:
	bool gRunning;

};

#endif /* GAME_H_ */
