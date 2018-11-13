/*
 * BonusCarSDL.cpp
 *
 *  Created on: Jul 26, 2016
 *      Author: Kian
 */

#include "BonusCarSDL.h"
#include <stdio.h>
#include "SDL_image.h"

namespace Au_sdl {

BonusCarSDL::BonusCarSDL(SDL_Renderer* tRenderer) {
	bTexture = NULL;
	gRenderer = tRenderer;
	VelX = 100;
	SDL_Surface* loadedSurface = IMG_Load("images/bonusCar.png");
	//Create texture from surface pixels
	bTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
	if( bTexture == NULL ){
		printf( "Failed to load texture image!\n" );
	}
	//Get rid of loaded surface
	SDL_FreeSurface( loadedSurface );
}

BonusCarSDL::~BonusCarSDL() {
	SDL_DestroyTexture( bTexture );
	bTexture = NULL;
}

void BonusCarSDL::update(){
	    //Render texture to screen
	if(y == lane1 || y == lane3 || y == lane5){
    	SDL_RenderCopyEx(gRenderer, bTexture, NULL, &renderQuad,angle ,&center, SDL_FLIP_NONE);
	} else {
		SDL_RenderCopy( gRenderer, bTexture, NULL, &renderQuad );
	}
}

void BonusCarSDL::moveRight(float timeStep){
	//velocity*timestep of 1/60(seconds) example-> 640 *1/60 pixels = ~10.67 pixels
	//Move the car right
	x += VelX * timeStep;
	renderQuad = { (int)x, (int)y, width, height }; //convert positions to integers, to prevent issues with compiler
}

void BonusCarSDL::moveLeft(float timeStep){
	//velocity*timestep of 1/60(seconds) example-> 640 *1/60 pixels = ~10.67 pixels
	//Move the car left
	x -= VelX * timeStep;
	renderQuad = { (int)x, (int)y, width, height }; //convert positions to integers, to prevent issues with compiler
}


bool BonusCarSDL::getDirection(){
	if(getPosY() == lane1 || getPosY() == lane3 || getPosY() == lane5){
		return 0;
	}
	if(getPosY() == lane2 || getPosY() == lane4 || getPosY() == lane6){
			return 1;
		}
}

std::string BonusCarSDL::getType(){
	return "bonus";
}

int BonusCarSDL::getWidth(){
	return width;
}

int BonusCarSDL::getHeight(){
	return height;
}

} /* namespace Au_sdl */
