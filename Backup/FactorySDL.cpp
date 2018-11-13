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


FactorySDL::FactorySDL(){
	gWindow = NULL;
	bTexture = NULL;
	gRenderer = NULL;
}

Frog* FactorySDL::createFrog(){
	return new FrogSDL(gRenderer);
}

std::shared_ptr<Car> FactorySDL::createCar(){
	return std::shared_ptr<Car>(new CarSDL(gRenderer));
}

std::shared_ptr<Bullet> FactorySDL::createBullet(){
	return std::shared_ptr<Bullet>(new BulletSDL(gRenderer));
}

InputHandler* FactorySDL::createControl(){
	return new InputHandlerSDL;
}

Timer* FactorySDL::createTimer(){
	return new TimerSDL;
}

void FactorySDL::init(){
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
	gWindow = SDL_CreateWindow( "Frogger", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( gWindow == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create renderer for window
		gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
		if( gRenderer == NULL )
		{
			printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
	                }
			//Load Background image
				SDL_Surface* loadedSurface = IMG_Load("Background.png");
				//Create texture from surface pixels
				bTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
				    if( bTexture == NULL )
				    {
				    	printf( "Failed to load texture image!\n" );
				    }
				    //Get rid of loaded surface
					SDL_FreeSurface( loadedSurface );
		}
	}
	}

}

void FactorySDL::loadBackground(){
		//Clear screen
		//SDL_RenderClear( global::gRenderer );
	   //Render texture to screen
		SDL_RenderCopy( gRenderer, bTexture, NULL,NULL);
		//Update screen
	   //SDL_RenderPresent( global::gRenderer );
}

void FactorySDL::clear(){
	//SDL_RenderClear(global::gRenderer);
	SDL_RenderClear(gRenderer);
}

void FactorySDL::present(){
	//SDL_RenderPresent( global::gRenderer );
	SDL_RenderPresent( gRenderer );
}

void FactorySDL::close()
{

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

