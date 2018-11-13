/*
 * Factory.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef FACTORY_H_
#define FACTORY_H_
#include "Frog.h"
#include "Car.h"
#include "Timer.h"
#include "Bullet.h"
#include <memory>
#include "InputHandler.h"
//Forward declaration(Factory included in InputHandler.h)
//->to prevent circular inclusion and reduce compile time
//class InputHandler;
namespace Au{
class Factory {
public:
	Factory();
	virtual Au::Frog* createFrog() = 0;
	virtual void init() = 0;
	virtual void close() = 0;
	virtual void clear() = 0;
	virtual void present() = 0;
	virtual void loadBackground() = 0;
	virtual void showBullets(int) = 0;
	virtual void showLives(int) = 0;
	virtual std::shared_ptr<Au::Car> createCar() = 0;
	virtual std::shared_ptr<Au::Car> createBonusCar() = 0;
	virtual std::shared_ptr<Au::Bullet> createBullet() = 0;
	virtual Au::InputHandler* createControl() = 0;
	virtual Timer* createTimer() = 0;
	virtual ~Factory();

};
}
#endif /* FACTORY_H_ */
