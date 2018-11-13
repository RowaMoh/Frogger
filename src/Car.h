/*
 * Car.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef CAR_H_
#define CAR_H_
#include "Enemy.h"
#include <string>
namespace Au {
class Car: public Enemy{
public:
	Car();
	virtual ~Car();
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void moveLeft(float) = 0;
	virtual void moveRight(float) = 0;
	virtual void update() = 0;
	virtual bool getDirection() = 0;
	virtual std::string getType() = 0;
};
}
#endif /* CAR_H_ */
