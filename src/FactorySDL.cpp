/*
 * FactorySDL.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */
#include "FactorySDL.h"
#include "InputHandlerSDL.h"
#include "FrogSDL.h"
#include "CarSDL.h"
#include "TimerSDL.h"
#include "BulletSDL.h"
#include "BonusCarSDL.h"
namespace Au_sdl{
FactorySDL::FactorySDL(){
	gWindow = NULL;
	bTexture = NULL;
	bulletTexture = NULL;
	gRenderer = NULL;
}

FactorySDL::~FactorySDL(){

}

Au::Frog* FactorySDL::createFrog(){
	return new FrogSDL(gRenderer);
}

std::shared_ptr<Au::Car> FactorySDL::createCar(){
	return std::shared_ptr<Au::Car>(new CarSDL(gRenderer));
}

std::shared_ptr<Au::Car> FactorySDL::createBonusCar(){
	return std::shared_ptr<Au::Car>(new BonusCarSDL(gRenderer));
}

std::shared_ptr<Au::Bullet> FactorySDL::createBullet(){
	return std::shared_ptr<Au::Bullet>(new BulletSDL(gRenderer));
}

Au::InputHandler* FactorySDL::createControl(){
	return new InputHandlerSDL();
}

Au::Timer* FactorySDL::createTimer(){
	return new TimerSDL(gRenderer);
}

void FactorySDL::init(){
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 ){
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}else{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			printf( "Warning: Linear texture filtering not enabled!" );
		}
	gWindow = SDL_CreateWindow( "Frogger", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
	}else{
		//Create renderer for window
		gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
		if( gRenderer == NULL ){
			printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		}else{
			//Initialize renderer color
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) ){
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			}
			//Initialize SDL_mixer
			if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) //44100 sound frequency->standard
			{
				printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
			}

			//Load Background image
			SDL_Surface* loadedSurface = IMG_Load("Background.png");
			//Create texture from surface pixels
			bTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
			if( bTexture == NULL ){
				printf( "Failed to load texture image!\n" );
			}
			//Get rid of loaded surface
			SDL_FreeSurface( loadedSurface );

			//Initialize SDL_ttf
			if( TTF_Init() == -1 ){
				printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
			}
		}
	}
	}
	//Open the font
	bFont = TTF_OpenFont( "Vera.ttf", 30 );
	if( bFont == NULL ){
		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
	}else{
		//Set text color as black
		textColor = { 255, 255, 255, 255 };
	}

}

void FactorySDL::loadBackground(){
	   //Render texture to screen
		SDL_RenderCopy( gRenderer, bTexture, NULL,NULL);
}

void FactorySDL::clear(){
	//SDL_RenderClear(global::gRenderer);
	SDL_RenderClear(gRenderer);
}

void FactorySDL::present(){
	//SDL_RenderPresent( global::gRenderer );
	SDL_RenderPresent( gRenderer );
}

void FactorySDL::close(){

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
}

void FactorySDL::showBullets(int bullets){
	SDL_DestroyTexture( bulletTexture );
	bulletTexture = NULL;
	//Because time constantly changes, you need to keep reloading font every time
	bulletsText.str( "" ); //important, or else the time gets rendered next to previous
	bulletsText << "Bullets:" << bullets;
	//Render text surface
	SDL_Surface* bullettextSurface = TTF_RenderText_Solid(bFont, bulletsText.str().c_str(), textColor );
	if( bullettextSurface != NULL ){
		//Create texture from surface pixels
		bulletTexture = SDL_CreateTextureFromSurface( gRenderer, bullettextSurface );
		if( bulletTexture == NULL ){
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		//Get rid of old surface
		SDL_FreeSurface( bullettextSurface );
		}else{
			printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
		}
	renderQuadB = { 0, 455, 80, 25 };
	//Render texture to screen
	SDL_RenderCopy( gRenderer, bulletTexture, NULL, &renderQuadB );
}

void FactorySDL::showLives(int lives){
	SDL_DestroyTexture( livesTexture );
	livesTexture = NULL;
	if(lives == 0){
		//Render text surface
		SDL_Surface* livesTextSurface = TTF_RenderText_Solid(bFont, "Game Over", textColor );
		if( livesTextSurface != NULL ){
			//Create texture from surface pixels
			livesTexture = SDL_CreateTextureFromSurface( gRenderer, livesTextSurface );
			if( livesTexture == NULL ){
				printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
			}
			//Get rid of old surface
			SDL_FreeSurface( livesTextSurface );
		}else{
			printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
		}
		renderQuadB = {120,120,400,240};
		//Render texture to screen
		SDL_RenderCopy( gRenderer, livesTexture, NULL, &renderQuadB );
		present();
		SDL_Delay(2000);
	}else{
		livesText.str( "" );
		livesText << "Lives:" << lives;
		//Render text surface
		SDL_Surface* livesTextSurface = TTF_RenderText_Solid(bFont, livesText.str().c_str(), textColor );
		if( livesTextSurface != NULL ){
			//Create texture from surface pixels
			livesTexture = SDL_CreateTextureFromSurface( gRenderer, livesTextSurface );
			if( livesTexture == NULL ){
				printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
			}
			//Get rid of old surface
			SDL_FreeSurface( livesTextSurface );
			}else{
				printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
			}
		renderQuadB = { 550, 455, 80, 25 };
		//Render texture to screen
		SDL_RenderCopy( gRenderer, livesTexture, NULL, &renderQuadB );
	}
}
}
