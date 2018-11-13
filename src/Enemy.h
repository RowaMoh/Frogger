/*
 * Enemy.h
 *
 *  Created on: Jun 19, 2016
 *      Author: Kian
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Entity.h"
namespace Au {
class Enemy: public Entity {
public:
	Enemy();
	virtual ~Enemy();
	virtual void update()=0;
	virtual bool getDirection() = 0;
	float getVel();
	void setVel(float);
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

protected:
	float VelX;
};
}
#endif /* ENEMY_H_ */
