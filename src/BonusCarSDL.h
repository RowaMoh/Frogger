/*
 * BonusCarSDL.h
 *
 *  Created on: Jul 26, 2016
 *      Author: Kian
 */

#ifndef BONUSCARSDL_H_
#define BONUSCARSDL_H_

#include "Car.h"

#include "SDL.h"

namespace Au_sdl {

class BonusCarSDL: public Au::Car {
public:
	BonusCarSDL(SDL_Renderer* tRenderer);
	~BonusCarSDL();
	void moveRight(float);
	void moveLeft(float);
	int getWidth();
	int getHeight();
	void update();
	bool getDirection();
	std::string getType();

private:
	SDL_Rect renderQuad;
	SDL_Texture *bTexture;
	SDL_Renderer *gRenderer;
	int width = 70;
	int height = 40;
	float lane1 = 75;
	float lane2 = 120;
	float lane3 = 210;
	float lane4 = 255;
	float lane5 = 345;
	float lane6 = 390;
	SDL_Point center = {35,20};
	float angle = 180;
};

} /* namespace Au_sdl */

#endif /* BONUSCARSDL_H_ */
