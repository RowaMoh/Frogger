/*
 * Car.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef CAR_H_
#define CAR_H_
#include "Enemy.h"

class Car: public Enemy{
private:
	//int atkpower;

public:
	Car();
	//void attack();
	virtual ~Car();
	virtual void moveLeft(float) = 0;
	virtual void moveRight(float) = 0;
	virtual void update() = 0;
	/*virtual float getPosY() = 0;
	virtual float getPosX() = 0;
	virtual void setPosY(float) = 0;
	virtual void setPosX(float) = 0;*/
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
};

#endif /* CAR_H_ */
