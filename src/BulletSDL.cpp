/*
 * BulletSDL.cpp
 *
 *  Created on: May 31, 2016
 *      Author: Kian
 */

#include "BulletSDL.h"
#include "SDL_image.h"
#include "stdio.h"
namespace Au_sdl {
BulletSDL::BulletSDL(SDL_Renderer* tRenderer) {
	VelY = 400;
	y = 600;
	gRenderer = tRenderer;
	//Load frog image
	SDL_Surface* loadedSurface = IMG_Load("images/Bullet.png");
	//Create texture from surface pixels
    fTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if( fTexture == NULL ){
            printf( "Failed to load texture image!\n" );
        }
    //Get rid of loaded surface
    SDL_FreeSurface( loadedSurface );
}

BulletSDL::~BulletSDL() {
	//Free loaded image
	SDL_DestroyTexture( fTexture );
    fTexture = NULL;
}


void BulletSDL::update(){
    SDL_RenderCopy( gRenderer, fTexture, NULL, &renderQuad );
}

void BulletSDL::shoot(float timeStep){
	y -= VelY * timeStep;
	renderQuad = { (int)x, (int)y, width, height };
}

int BulletSDL::getWidth(){
	return width;
}

int BulletSDL::getHeight(){
	return height;
}

}
