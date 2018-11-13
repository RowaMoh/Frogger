/*
 * InputHandlerSDL.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Kian
 */

#include "InputHandlerSDL.h"
#include "SDL.h"

InputHandlerSDL::InputHandlerSDL() {
	// TODO Auto-generated constructor stub

}

InputHandlerSDL::~InputHandlerSDL() {
	// TODO Auto-generated destructor stub
}

void InputHandlerSDL::update(Frog *Fr, Game *game, std::shared_ptr<Bullet> bullet)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
    	if(event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym)
        {

            case SDLK_DOWN:
            	if(Fr->getPosY() >= 0 && Fr->getPosY() < 440){
                Fr->setPosY(Fr->getPosY() + 45);
            	}
            	else{
            		Fr->setPosY(440);
            	}
                break;

            case SDLK_UP:
            	if(Fr->getPosY() <= 440 && Fr->getPosY() > 50){
            	Fr->setPosY(Fr->getPosY() - 45);
            	}
            	else{
            		Fr->setPosY(0);
            	}
                break;

            case SDLK_LEFT:
            	if(Fr->getPosX() <= 600 && Fr->getPosX() > 30){
            	Fr->setPosX(Fr->getPosX() - 45);
            	}
               	else{
               		Fr->setPosX(600);
               	}
            	break;

            case SDLK_RIGHT:
            	if(Fr->getPosX() >= 0 && Fr->getPosX() < 570){
            	Fr->setPosX(Fr->getPosX() + 45);
            	}
            	else{
           		Fr->setPosX(15);
               	}
            	break;

            case SDLK_SPACE:
            	if(bullet->getPosY() <= Fr->getPosY()){
            		break;
            	} else{
            	bullet->setPosX(Fr->getPosX());
            	bullet->setPosY(Fr->getPosY());
            	}
              	break;

            default:
                break;
        }
        }
    	else if(event.type == SDL_QUIT){
    		game->quit();
    	}
    }
}

void InputHandlerSDL::update1(Frog* Fr,Game* game){
	SDL_Event event;
	    while(SDL_PollEvent(&event))
	    {
	    	if(event.type == SDL_KEYDOWN){
	        switch (event.key.keysym.sym)
	        {

	            case SDLK_DOWN:
	            	if(Fr->getPosY() >= 0 && Fr->getPosY() < 440){
	                Fr->setPosY(Fr->getPosY() + 45);
	            	}
	            	else{
	            		Fr->setPosY(440);
	            	}
	                break;

	            case SDLK_UP:
	            	if(Fr->getPosY() <= 440 && Fr->getPosY() > 50){
	            	Fr->setPosY(Fr->getPosY() - 45);
	            	}
	            	else{
	            		Fr->setPosY(0);
	            	}
	                break;

	            case SDLK_LEFT:
	            	if(Fr->getPosX() <= 600 && Fr->getPosX() > 30){
	            	Fr->setPosX(Fr->getPosX() - 45);
	            	}
	               	else{
	               		Fr->setPosX(600);
	               	}
	            	break;

	            case SDLK_RIGHT:
	            	if(Fr->getPosX() >= 0 && Fr->getPosX() < 570){
	            	Fr->setPosX(Fr->getPosX() + 45);
	            	}
	            	else{
	           		Fr->setPosX(15);
	               	}
	            	break;

	            default:
	                break;
	        }
	        }
	    	else if(event.type == SDL_QUIT){
	    		game->quit();
	    	}
	    }
}
