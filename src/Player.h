/*
 * Player.h
 *
 *  Created on: Jun 18, 2016
 *      Author: Kian
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Entity.h"
namespace Au {
class Player: public Entity {
public:
	Player();
	virtual ~Player();
	virtual void update() = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
};
}
#endif /* PLAYER_H_ */
