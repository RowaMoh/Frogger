/*
 * Bullet.h
 *
 *  Created on: May 31, 2016
 *      Author: Kian
 */

#ifndef BULLET_H_
#define BULLET_H_
#include "Player.h"

namespace Au {
class Bullet: public Player {
public:
	Bullet();
	virtual ~Bullet();
	virtual void update() = 0;
	virtual void shoot(float timeStep) = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
};
}

#endif /* BULLET_H_ */
