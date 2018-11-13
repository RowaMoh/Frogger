/*
 * FrogSDL.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#include "FrogSDL.h"
#include "FactorySDL.h"

FrogSDL::FrogSDL(SDL_Renderer* tRenderer){
	x = 300;
	y = 440;
	fTexture = NULL;
	gRenderer = tRenderer;
	//Load frog image
	SDL_Surface* loadedSurface = IMG_Load("images/Frog.png");
	//Create texture from surface pixels
    fTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if( fTexture == NULL )
        {
            printf( "Failed to load texture image!\n" );
        }
    //Get rid of loaded surface
    SDL_FreeSurface( loadedSurface );
}

FrogSDL::~FrogSDL(){
	//Free loaded image
	SDL_DestroyTexture( fTexture );
    fTexture = NULL;
    //printf("Destroyed!");
}

void FrogSDL::update(){
	renderQuad = { (int)x, (int)y, width, height };
	//Render texture to screen
	SDL_RenderCopy( gRenderer, fTexture, NULL, &renderQuad );
}
/*
void FrogSDL::setPosX(float posx){
	x = posx;
}

void FrogSDL::setPosY(float posy){
	y = posy;
}

float FrogSDL::getPosX(){
	return x;
}

float FrogSDL::getPosY(){
	return y;
}
*/
int FrogSDL::getWidth(){
	return width;
}

int FrogSDL::getHeight(){
	return height;
}

void FrogSDL::dying(){

}
