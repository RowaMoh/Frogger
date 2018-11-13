/*
 * InputHandlerSDL.h
 *
 *  Created on: Apr 29, 2016
 *      Author: Kian
 */

#ifndef INPUTHANDLERSDL_H_
#define INPUTHANDLERSDL_H_
//Factory and Game included in InputHandler.h, Frog included in Factory
#include "InputHandler.h"

class InputHandlerSDL: public InputHandler {
public:
	InputHandlerSDL();
	~InputHandlerSDL();
	void update(Frog*,Game*,std::shared_ptr<Bullet>);
	void update1(Frog*,Game*);
};

#endif /* INPUTHANDLERSDL_H_ */
