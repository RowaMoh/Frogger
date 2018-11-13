/*
 * Enemy.h
 *
 *  Created on: Jun 19, 2016
 *      Author: Kian
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Entity.h"

class Enemy: public Entity {
public:
	Enemy();
	virtual ~Enemy();
	virtual int getWidth()=0;
	virtual int getHeight()=0;
	virtual void update()=0;
};

#endif /* ENEMY_H_ */
