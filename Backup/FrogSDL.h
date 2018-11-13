/*
 * FrogSDL.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef FROGSDL_H_
#define FROGSDL_H_
#include "Frog.h"
#include "SDL.h"
#include "SDL_image.h"
#include "stdio.h"


class FrogSDL: public Frog {
public:
	FrogSDL(SDL_Renderer*);
	~FrogSDL();
	void visual();

	void update();
	/*void setPosX(float);
	void setPosY(float);
	float getPosX();
	float getPosY();*/
	int getWidth();
	int getHeight();
	void dying();


private:
	SDL_Rect renderQuad;
	SDL_Texture *fTexture;
	SDL_Renderer *gRenderer;
	//float x;
	//float y;
	int width = 25;
	int height = 25;
	};

#endif /* FROGSDL_H_ */
