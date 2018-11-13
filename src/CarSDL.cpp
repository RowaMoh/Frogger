/*
 * CarSDL.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#include "CarSDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
namespace Au_sdl{
CarSDL::CarSDL(SDL_Renderer* tRenderer){
	cTexture = NULL;
	gRenderer = tRenderer;
	VelX = 100;
    //srand((unsigned)time(0)); //calling the same seed for all objects, this means you will always get the same sequence of values
    int random_integer;
    random_integer = (rand()%8)+1; // rand()%n we generate a number from 0 to n-1, and +1 so its not zero based
    switch(random_integer){
    	    case 1:
    	    	carChoice = "images/bCar.png";
    	    	break;
    	    case 2:
    	    	carChoice = "images/gCar.png";
    	    	break;
    	    case 3:
    	    	carChoice = "images/wCar.png";
    	    	break;
    	    case 4:
    	    	carChoice = "images/blCar.png";
    	    	break;
    	    case 5:
    	    	carChoice = "images/oCar.png";
    	    	break;
    	    case 6:
    	        carChoice = "images/pCar.png";
    	        break;
    	    case 7:
    	        carChoice = "images/rCar.png";
    	        break;
    	    case 8:
    	        carChoice = "images/yCar.png";
    	        break;

    	    default:
    	    	break;

    	    }
    SDL_Surface* loadedSurface = IMG_Load(carChoice.c_str());  //c_str() converts to const char*(which is needed for the function)
    //Create texture from surface pixels
    cTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    if( cTexture == NULL ){
    	printf( "Failed to load texture image!\n" );
    }
    //Get rid of loaded surface
    SDL_FreeSurface( loadedSurface );
}

CarSDL::~CarSDL(){
	SDL_DestroyTexture( cTexture );
	cTexture = NULL;
	//printf("Destroyed!");
}

void CarSDL::update(){
	    //Render texture to screen
	if(y == lane1 || y == lane3 || y == lane5){
    	SDL_RenderCopyEx(gRenderer, cTexture, NULL, &renderQuad,angle ,&center, SDL_FLIP_NONE);
	} else {
		SDL_RenderCopy( gRenderer, cTexture, NULL, &renderQuad );
	}
}



void CarSDL::moveRight(float timeStep){
	//velocity*timestep of 1/60(seconds) example-> 640 *1/60 pixels = ~10.67 pixels
	//Move the car right
	x += VelX * timeStep;
	renderQuad = { (int)x, (int)y, width, height }; //convert positions to integers, to prevent issues with compiler
}

void CarSDL::moveLeft(float timeStep){
	//velocity*timestep of 1/60(seconds) example-> 640 *1/60 pixels = ~10.67 pixels
	//Move the car left
	x -= VelX * timeStep;
	renderQuad = { (int)x, (int)y, width, height }; //convert positions to integers, to prevent issues with compiler
}

bool CarSDL::getDirection(){
	if(getPosY() == lane1 || getPosY() == lane3 || getPosY() == lane5){
		return 0; //left
	}
	if(getPosY() == lane2 || getPosY() == lane4 || getPosY() == lane6){
			return 1; //right
		}
}

std::string CarSDL::getType(){
	return "normal";
}

int CarSDL::getWidth(){
	return width;
}

int CarSDL::getHeight(){
	return height;
}

}
