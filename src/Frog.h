/*
 * Frog.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef FROG_H_
#define FROG_H_
#include "Player.h"
#include <string>
namespace Au {
class Frog: public Player {
//this is an abstract class -> cannot create object of an abstract class, thats why you return FrogSDL with createFrog function -> see tutorial programiz
public:
	Frog();
	virtual ~Frog();
	virtual void update() = 0;
	virtual void changeColor(std::string) = 0;
	virtual bool win() = 0;
	virtual int getLives() = 0;
	virtual void setLives(int) = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
};
}
#endif /* FROG_H_ */
