/*
 * CarSDL.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef CARSDL_H_
#define CARSDL_H_
#include "Car.h"
#include "SDL.h"
#include <string>

class CarSDL: public Car {
private:
	SDL_Rect renderQuad;
	SDL_Texture *cTexture;
	SDL_Point center = {35,20};
	float angle = 180;
	// float x, y; //FLOAT! aangezien de timer met float werkt
	//The velocity of the car
	float VelX;  //FLOAT!
	std::string carChoice;
	int width = 70;
	int height = 40;
	float lane1 = 74;
	float lane2 = 120;
	float lane3 = 212;
	float lane4 = 257;
	float lane5 = 344;
	float lane6 = 390;
	SDL_Renderer *gRenderer;
	static const int ANIMATION_FRAMES = 4;
	SDL_Rect gSpriteClips[ ANIMATION_FRAMES ];

public:
	CarSDL(SDL_Renderer*);
	~CarSDL();
	void moveRight(float);
	void moveLeft(float);
	void update();
	/*float getPosY();
	float getPosX();
	void setPosY(float);
	void setPosX(float);*/
	int getWidth();
	int getHeight();
	void dead();
};

#endif /* CARSDL_H_ */
