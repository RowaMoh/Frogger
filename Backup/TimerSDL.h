/*
 * LTimer.h
 *
 *  Created on: Apr 25, 2016
 *      Author: Kian
 */

#ifndef TIMERSDL_H_
#define TIMERSDL_H_
#include "SDL.h"
#include "Timer.h"

class TimerSDL: public Timer {
public:
		//Initializes variables
		TimerSDL();
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

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};

#endif /* TIMERSDL_H_ */
