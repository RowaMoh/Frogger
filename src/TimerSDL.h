/*
 * LTimer.h
 *
 *  Created on: Apr 25, 2016
 *      Author: Kian
 */

#ifndef TIMERSDL_H_
#define TIMERSDL_H_
#include "Timer.h"
#include "SDL2/SDL_ttf.h"
#include <sstream>
namespace Au_sdl{
class TimerSDL: public Au::Timer {
public:
		//Initializes variables
		TimerSDL(SDL_Renderer*);
		~TimerSDL();
		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();
		void update();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;
		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;
		//The timer status
		bool mPaused;
		bool mStarted;

		SDL_Texture *tTexture;
		SDL_Renderer *gRenderer;
		TTF_Font* gFont;
		SDL_Color textColor;
		int width = 80;
		int height = 25;
		float x;
		float y;
		SDL_Rect renderQuad;
		//In memory text stream
		std::stringstream timeText;

};
}

#endif /* TIMERSDL_H_ */
