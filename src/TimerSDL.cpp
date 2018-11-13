/*
 * LTimer.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: Kian
 */

#include "TimerSDL.h"
#include <stdio.h>
#include <string>
namespace Au_sdl{
TimerSDL::TimerSDL(SDL_Renderer* tRenderer){
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;

    x = 0;
    y = 435;
  	tTexture = NULL;
   	gRenderer = tRenderer;
   	gFont = NULL;
   	//Open the font
   	gFont = TTF_OpenFont( "Vera.ttf", 30 );
   	if( gFont == NULL ){
   		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
   	}else{
   		//Set text color as black
		textColor = { 255, 255, 255, 255 };
   	}

}

TimerSDL::~TimerSDL(){
	//Free loaded image
	SDL_DestroyTexture( tTexture );
	tTexture = NULL;
	TTF_CloseFont( gFont );
	gFont = NULL;
}

void TimerSDL::start(){
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void TimerSDL::stop(){
    //Stop the timer
    mStarted = false;

    //Unpause the timer
    mPaused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}

void TimerSDL::pause(){
    //If the timer is running and isn't already paused
    if( mStarted && !mPaused ){
        //Pause the timer
        mPaused = true;

        //Calculate the paused ticks
        mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
    }
}

void TimerSDL::unpause(){
    //If the timer is running and paused
    if( mStarted && mPaused )
    {
        //Unpause the timer
        mPaused = false;

        //Reset the starting ticks
        mStartTicks = SDL_GetTicks() - mPausedTicks;

        //Reset the paused ticks
        mPausedTicks = 0;
    }
}

Uint32 TimerSDL::getTicks(){
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( mStarted ){
        //If the timer is paused
        if( mPaused ){
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        } else {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool TimerSDL::isStarted(){
	//Timer is running and paused or unpaused
    return mStarted;
}

bool TimerSDL::isPaused(){
	//Timer is running and paused
    return mPaused && mStarted;
}

void TimerSDL::update(){
	//Need to free the previous texture first
	SDL_DestroyTexture( tTexture );
	tTexture = NULL;
	//Because time constantly changes, you need to keep reloading font every time
	timeText.str( "" ); //important, or else the time gets rendered next to previous
	timeText << "Time:" << getTicks();// - mStarted;
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, timeText.str().c_str(), textColor );
	if( textSurface != NULL ){
		//Create texture from surface pixels
		tTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( tTexture == NULL ){
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		//Get rid of old surface
		SDL_FreeSurface( textSurface );
		}else{
			printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
		}
	renderQuad = { (int)x, (int)y, width, height };
	//Render texture to screen
	SDL_RenderCopy( gRenderer, tTexture, NULL, &renderQuad );
}
}
