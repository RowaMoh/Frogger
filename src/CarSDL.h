/*
 * CarSDL.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef CARSDL_H_
#define CARSDL_H_
#include "Car.h"
#include "SDL2/SDL.h"
#include <string>
namespace Au_sdl{
class CarSDL: public Au::Car {
private:
	SDL_Rect renderQuad;
	SDL_Texture *cTexture;
	SDL_Point center = {35,20};
	float angle = 180;
	// float x, y; //FLOAT! aangezien de timer met float werkt
	//The velocity of the car
	//float VelX;  //FLOAT!
	std::string carChoice;
	int width = 70;
	int height = 40;
	float lane1 = 75;
	float lane2 = 120;
	float lane3 = 210;
	float lane4 = 255;
	float lane5 = 345;
	float lane6 = 390;
	SDL_Renderer *gRenderer;

public:
	CarSDL(SDL_Renderer*);
	~CarSDL();
	void moveRight(float);
	void moveLeft(float);
	void update();
	bool getDirection();
	std::string getType();
	int getWidth();
	int getHeight();
};
}

#endif /* CARSDL_H_ */
