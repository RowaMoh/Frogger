/*
 * CollisionHandler.h
 *
 *  Created on: May 6, 2016
 *      Author: Kian
 */

#ifndef COLLISIONHANDLER_H_
#define COLLISIONHANDLER_H_
//#include "Car.h"
//#include "Frog.h"
//#include "Bullet.h"
#include "Factory.h"
#include <vector>
#include <queue>
//using namespace Au;

class CollisionHandler {
public:
	CollisionHandler();
	~CollisionHandler();
	void checkFrogBulletCarCollision(Au::Frog *Fr, std::vector<std::shared_ptr<Au::Car>>& carObjects, Au::Factory* Fact,std::queue<std::shared_ptr<Au::Bullet>>& bullets, float lane,float time);
	void checkBorderCarCollision(Au::Factory*, std::vector<std::shared_ptr<Au::Car>>& carObjects);
	//vector of shared_ptrs passed by reference to modify it in function
private:
	//SDL_Rect frog;
	//SDL_Rect car;
	//The sides of the rectangles
	int leftfrog, leftcar, rightfrog, rightcar;
	int topfrog, topcar, bottfrog, bottcar;
	int leftbullet, topbullet, bottbullet, rightbullet;
	float lane1 = 75;
	float lane2 = 120;
	float lane3 = 210;
	float lane4 = 255;
	float lane5 = 345;
	float lane6 = 390;
};

#endif /* COLLISIONHANDLER_H_ */
