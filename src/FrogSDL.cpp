/*
 * FrogSDL.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#include "FrogSDL.h"
#include "FactorySDL.h"
#include <iostream>

namespace Au_sdl{
FrogSDL::FrogSDL(SDL_Renderer* tRenderer){
	lives = 3;
	level = 1;
	x = 300;
	y = 435;
	fTexture = NULL;
	levelTexture = NULL;
	gRenderer = tRenderer;
	gFont = NULL;
	//Open the font
   	gFont = TTF_OpenFont( "Vera.ttf", 60 );
   	if( gFont == NULL ){
   		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
   	}else{
   		//Set text color as black
		textColor = { 255, 255, 255, 255 };
   	}
	//Load frog image
	SDL_Surface* loadedSurface = IMG_Load("images/Frog.png");
	//Create texture from surface pixels
    fTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if( fTexture == NULL ){
            printf( "Failed to load texture image!\n" );
        }
    //Get rid of loaded surface
    SDL_FreeSurface( loadedSurface );
    gWin = Mix_LoadWAV( "sounds/win.wav" );
	    	    if( gWin == NULL )
	    	    {
	    	    	printf( "Failed to load win sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	    	    }

}

FrogSDL::~FrogSDL(){
	//Free loaded image
	SDL_DestroyTexture( fTexture );
    fTexture = NULL;
    SDL_DestroyTexture( levelTexture );
    levelTexture = NULL;
    Mix_FreeChunk( gWin );
    gWin = NULL;
    //printf("Destroyed!");
}

void FrogSDL::update(){
	renderQuad = { (int)x, (int)y, width, height };
	//Render texture to screen
	SDL_RenderCopy( gRenderer, fTexture, NULL, &renderQuad );
}

void FrogSDL::changeColor(std::string color){
	if(color == "yellow"){
	SDL_SetTextureColorMod(fTexture,255,255,0);
	}
	if(color == "red"){
		SDL_SetTextureColorMod(fTexture,255,0,0);
		}
	if(color == "blue"){
			SDL_SetTextureColorMod(fTexture,0,0,255);
			}
	if(color == "green"){
			SDL_SetTextureColorMod(fTexture,0,255,0);
			}
}

bool FrogSDL::win(){
	if(getPosY() == 30){
		level++;
		Mix_PlayChannel( -1, gWin, 0 );
		SDL_DestroyTexture( levelTexture );
			levelTexture = NULL;
		levelText.str( "" );
		levelText << "Level " << level;
		SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, levelText.str().c_str(), textColor );
			if( textSurface != NULL ){
				//Create texture from surface pixels
				levelTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
				if( levelTexture == NULL ){
					printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
				}
				//Get rid of old surface
				SDL_FreeSurface( textSurface );
				}else{
					printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
				}
			SDL_RenderCopy( gRenderer, levelTexture, NULL, &levelQuad );
			SDL_RenderPresent( gRenderer );
		SDL_Delay(3000);
		return true;
	    	}

}

int FrogSDL::getLives(){
	return lives;
}

void FrogSDL::setLives(int newlives){
	lives = newlives;
}

int FrogSDL::getWidth(){
	return width;
}

int FrogSDL::getHeight(){
	return height;
}

}

