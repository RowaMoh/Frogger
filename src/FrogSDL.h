/*
 * FrogSDL.h
 *
 *  Created on: Feb 22, 2016
 *      Author: Kian
 */

#ifndef FROGSDL_H_
#define FROGSDL_H_
#include "Frog.h"
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "stdio.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <sstream>

namespace Au_sdl{
class FrogSDL: public Au::Frog {
public:
	FrogSDL(SDL_Renderer*);
	~FrogSDL();
	void update();
	int getWidth();
	int getHeight();
	void changeColor(std::string);
	bool win();
	int getLives();
	void setLives(int);

private:
	SDL_Rect renderQuad;
	SDL_Rect levelQuad = {160,120,320,240};
	SDL_Texture *fTexture;
	SDL_Texture *levelTexture;
	SDL_Renderer *gRenderer;
	//float x;
	//float y;
	int width = 25;
	int height = 25;
	TTF_Font* gFont;
	SDL_Color textColor;
	Mix_Chunk *gWin = NULL;
	int level;
	std::stringstream levelText;
	int lives;
	};
}
#endif /* FROGSDL_H_ */
