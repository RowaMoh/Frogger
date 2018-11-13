/*
 * InputHandler.h
 *
 *  Created on: Apr 11, 2016
 *      Author: Kian
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_
#include "Game.h"
#include "Frog.h"
#include "Bullet.h"
#include <memory>

class InputHandler {
public:
	InputHandler();
	virtual ~InputHandler();
	virtual void update(Frog*,Game*,std::shared_ptr<Bullet>) = 0;
	virtual void update1(Frog*,Game*) = 0;
};

#endif /* INPUTHANDLER_H_ */
