/*
 * BulletSDL.h
 *
 *  Created on: May 31, 2016
 *      Author: Kian
 */

#ifndef BULLETSDL_H_
#define BULLETSDL_H_
#include "Bullet.h"
#include "SDL.h"

namespace Au_sdl {
class BulletSDL: public Au::Bullet {
public:
	BulletSDL(SDL_Renderer*);
	~BulletSDL();
	void update();
	/*float getPosY();
	float getPosX();
	void setPosY(float);
	void setPosX(float);*/
	void shoot(float timeStep);
	int getWidth();
	int getHeight();

private:
	SDL_Rect renderQuad;
	SDL_Texture *fTexture;
	SDL_Renderer *gRenderer;
	int width = 25;
	int height = 25;
	float VelY;
};
}
#endif /* BULLETSDL_H_ */
