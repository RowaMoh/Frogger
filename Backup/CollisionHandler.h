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
//#include <memory>
#include <vector>

class CollisionHandler {
public:
	CollisionHandler();
	~CollisionHandler();
	bool checkFrogCarCollision(Frog *Fr, std::shared_ptr<Car>);
	bool checkBulletCarCollision(std::shared_ptr<Car>,std::shared_ptr<Bullet>);
	void checkBorderCarCollision(Factory*, std::vector<std::shared_ptr<Car>>& carObjects);
	//vector of shared_ptrs passed by reference to modify it in function
private:
	//SDL_Rect frog;
	//SDL_Rect car;
	//The sides of the rectangles
	int leftfrog, leftcar, rightfrog, rightcar;
	int topfrog, topcar, bottfrog, bottcar;
	int leftbullet, topbullet, bottbullet, rightbullet;
};

#endif /* COLLISIONHANDLER_H_ */
