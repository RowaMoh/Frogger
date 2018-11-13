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
#include "SDL_mixer.h"
namespace Au_sdl{
class InputHandlerSDL: public Au::InputHandler {
public:
	InputHandlerSDL();
	~InputHandlerSDL();
	void update(Au::Frog*,std::shared_ptr<Au::Bullet>, bool&);
	void update1(Au::Frog*, bool&);

private:
	Mix_Chunk *gShoot = NULL;
	Mix_Chunk *gMove = NULL;
};
}
#endif /* INPUTHANDLERSDL_H_ */
