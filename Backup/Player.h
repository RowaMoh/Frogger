/*
 * Player.h
 *
 *  Created on: Jun 18, 2016
 *      Author: Kian
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Entity.h"

class Player: public Entity {
public:
	Player();
	virtual ~Player();
	/*void setPosX(float);
	void setPosY(float);
	float getPosY();
	float getPosX();*/
	virtual int getWidth()=0;
	virtual int getHeight()=0;
	virtual void update()=0;
};

#endif /* PLAYER_H_ */
