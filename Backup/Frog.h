/*
 * Frog.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef FROG_H_
#define FROG_H_
#include "Player.h"

class Frog: public Player {
//this is an abstract class -> cannot create object of an abstract class, thats why you return FrogSDL with createFrog function -> see tutorial programiz
public:
	Frog();
	virtual ~Frog();
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void update() = 0;
	/*void setPosX(float);
	void setPosY(float);
	float getPosY();
	float getPosX();*/
};

#endif /* FROG_H_ */
