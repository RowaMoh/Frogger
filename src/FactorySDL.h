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
#include <sstream>
#include "SDL_ttf.h"
namespace Au_sdl{
class FactorySDL: public Au::Factory {
public :
	FactorySDL();
	~FactorySDL();
	Au::Frog* createFrog();
	std::shared_ptr<Au::Car> createCar();
	std::shared_ptr<Au::Car> createBonusCar();
	std::shared_ptr<Au::Bullet> createBullet();
	Au::InputHandler* createControl();
	Au::Timer* createTimer();
	void init();
	void close();
	void loadBackground();
	void clear();
	void present();
	void showBullets(int);
	void showLives(int);

private:
	SDL_Window* gWindow;
	SDL_Texture* bTexture;
	SDL_Texture* bulletTexture;
	SDL_Texture* livesTexture;
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	SDL_Renderer *gRenderer;
	std::stringstream bulletsText;
	std::stringstream livesText;
	TTF_Font* bFont;
	SDL_Color textColor;
	SDL_Rect renderQuadB;
};
}

#endif /* FACTORYSDL_H_ */
