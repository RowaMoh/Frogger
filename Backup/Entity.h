/*
 * Entity.h
 *
 *  Created on: Jun 18, 2016
 *      Author: Kian
 */

#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
public:
	Entity();
	virtual ~Entity();
	void setPosX(float);
	void setPosY(float);
	float getPosY();
	float getPosX();
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void update() = 0;

protected:
	float x,y;
};

#endif /* ENTITY_H_ */
