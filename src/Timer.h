/*
 * Timer.h
 *
 *  Created on: May 5, 2016
 *      Author: Kian
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "SDL2/SDL.h"
namespace Au{
class Timer {
public:
	Timer();
	virtual ~Timer();
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void pause() = 0;
	virtual void unpause() = 0;
	virtual Uint32 getTicks() = 0;
	virtual bool isStarted() = 0;
	virtual bool isPaused() = 0;
	virtual void update() = 0;
};
}

#endif /* TIMER_H_ */
