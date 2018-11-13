/*
 * InputHandlerSDL.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Kian
 */

#include "InputHandlerSDL.h"
#include "SDL.h"
#include <iostream>
namespace Au_sdl{
InputHandlerSDL::InputHandlerSDL() {
	   //Load sound effects
	    gShoot = Mix_LoadWAV( "sounds/shoot.wav" );
	    if( gShoot == NULL )
	    {
	        printf( "Failed to load shoot sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	    }

	    gMove = Mix_LoadWAV( "sounds/jump.wav" );
	    if( gMove == NULL )
	    {
	    	printf( "Failed to load move sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	    }
}

InputHandlerSDL::~InputHandlerSDL() {
	Mix_FreeChunk( gShoot );
    Mix_FreeChunk( gMove );
    gShoot = NULL;
    gMove = NULL;

}

void InputHandlerSDL::update(Au::Frog *Fr, std::shared_ptr<Au::Bullet> bullet, bool &pRunning){

    SDL_Event event;
    while(SDL_PollEvent(&event)){
    	if(event.type == SDL_KEYDOWN){
    		switch (event.key.keysym.sym)
    		{

    		case SDLK_y:
    			Fr->changeColor("yellow");
        	break;

    		case SDLK_r:
    			Fr->changeColor("red");
            break;

    		case SDLK_b:
    			Fr->changeColor("blue");
            break;

            case SDLK_g:
            	Fr->changeColor("green");
            break;

            case SDLK_DOWN:
        	if(Fr->getPosY() >= 0 && Fr->getPosY() < 435){
        		Mix_PlayChannel( -1, gMove, 0 );
        		Fr->setPosY(Fr->getPosY() + 45);
            	}
            else{
            	Fr->setPosY(435);
            	}
            break;

            case SDLK_UP:
           	if(Fr->getPosY() <= 435 && Fr->getPosY() > 30){
           		Mix_PlayChannel( -1, gMove, 0 );
            	Fr->setPosY(Fr->getPosY() - 45);
            	//std::cout << Fr->getPosY() << std::endl;
            	}else{
            		Fr->setPosY(30);
            	}
            break;

            case SDLK_LEFT:
           	if(Fr->getPosX() <= 600 && Fr->getPosX() > 30){
           		Mix_PlayChannel( -1, gMove, 0 );
            	Fr->setPosX(Fr->getPosX() - 45);
            	}
           	else{
               		Fr->setPosX(600);
               	}
           	break;

        case SDLK_RIGHT:
           	if(Fr->getPosX() >= 0 && Fr->getPosX() < 570){
           		Mix_PlayChannel( -1, gMove, 0 );
            	Fr->setPosX(Fr->getPosX() + 45);
            	}
            else{
           		Fr->setPosX(15);
               	}
            break;

        case SDLK_SPACE:
            if(bullet->getPosY() <= Fr->getPosY()){
            	break;
            	}
            else{
            	Mix_PlayChannel( -1, gShoot, 0 );
            	bullet->setPosX(Fr->getPosX());
            	bullet->setPosY(Fr->getPosY());
            	}
           	break;

        default:
            break;
    		}
    	}
    	else if(event.type == SDL_QUIT){
    		pRunning = false;
    	}
    	else{
    		update1(Fr,pRunning);
    	}
    }
}

void InputHandlerSDL::update1(Au::Frog* Fr, bool &pRunning){
	SDL_Event event;
	    while(SDL_PollEvent(&event))
	    {
	    	if(event.type == SDL_KEYDOWN){
	    		switch (event.key.keysym.sym)
	    		{
	        case SDLK_y:
	        	Fr->changeColor("yellow");
	        	break;

	        case SDLK_r:
	            Fr->changeColor("red");
	            break;

	        case SDLK_b:
	        	Fr->changeColor("blue");
	            break;

	        case SDLK_g:
	            Fr->changeColor("green");
	            break;

	        case SDLK_DOWN:
	            if(Fr->getPosY() >= 0 && Fr->getPosY() < 440){
	            	Mix_PlayChannel( -1, gMove, 0 );
	                Fr->setPosY(Fr->getPosY() + 45);
	            }
	            else{
	           		Fr->setPosY(440);
	           	}
	            break;

	        case SDLK_UP:
	           	if(Fr->getPosY() <= 440 && Fr->getPosY() > 50){
	           		Mix_PlayChannel( -1, gMove, 0 );
	            	Fr->setPosY(Fr->getPosY() - 45);
	           	}
	           	else{
	           		Fr->setPosY(30);
	           	}
	            break;

	        case SDLK_LEFT:
	            if(Fr->getPosX() <= 600 && Fr->getPosX() > 30){
	            	Mix_PlayChannel( -1, gMove, 0 );
	            	Fr->setPosX(Fr->getPosX() - 45);
	           	}
	           	else{
	           		Fr->setPosX(600);
            	}
	            break;

	        case SDLK_RIGHT:
	            if(Fr->getPosX() >= 0 && Fr->getPosX() < 570){
	            	Mix_PlayChannel( -1, gMove, 0 );
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
	    		pRunning = false;
	    	}
	    }
}

}
