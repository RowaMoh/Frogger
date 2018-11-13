/*
 * FactorySDL.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_
#include "Factory.h"
#include "SDL.h"

class FactorySDL: public Factory {
public :
	FactorySDL();
	Frog* createFrog();
	std::shared_ptr<Car> createCar();
	std::shared_ptr<Bullet> createBullet();
	InputHandler* createControl();
	Timer* createTimer();
	void init();
	void close();
	void loadBackground();
	void clear();
	void present();
private:
	SDL_Window* gWindow;
	SDL_Texture* bTexture;
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	SDL_Renderer *gRenderer;
};


#endif /* FACTORYSDL_H_ */
