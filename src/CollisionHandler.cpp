/*
 * CollisionHandler.cpp
 *
 *  Created on: May 6, 2016
 *      Author: Kian
 */

#include "CollisionHandler.h"
#include <iostream>

CollisionHandler::CollisionHandler() {
	// TODO Auto-generated constructor stub

}

CollisionHandler::~CollisionHandler() {
	// TODO Auto-generated destructor stub
}

void CollisionHandler::checkFrogBulletCarCollision(Au::Frog *Fr, std::vector<std::shared_ptr<Au::Car>>& carObjects,Au::Factory* Fact,std::queue<std::shared_ptr<Au::Bullet>>& bullets, float lane, float time){
	for(unsigned int i = 0; i < carObjects.size(); i++){
	//Sides of Frog rectangle
	leftfrog = Fr->getPosX();
	rightfrog = Fr->getPosX() + Fr->getWidth();
	topfrog = Fr->getPosY();
	bottfrog = Fr->getPosY() + Fr->getHeight();  //Remember: y-axis is upside down

	leftcar = carObjects[i]->getPosX();
	rightcar = carObjects[i]->getPosX() + carObjects[i]->getWidth();
	topcar = carObjects[i]->getPosY();
	bottcar = carObjects[i]->getPosY() + carObjects[i]->getHeight();

	//If any of the sides from Frog are outside of Car
	if(!(bottfrog <= topcar || topfrog >= bottcar || rightfrog <= leftcar || leftfrog >= rightcar)){
		if(Fr->getLives() != 0){
			Fr->setLives(Fr->getLives()-1);
			Fr->setPosX(300);
			Fr->setPosY(435);
		}
	}

	if(!bullets.empty()){
		//Sides of Bullet rectangle
		leftbullet = bullets.front()->getPosX();
		rightbullet = bullets.front()->getPosX() + bullets.front()->getWidth();
		topbullet = bullets.front()->getPosY();
		bottbullet = bullets.front()->getPosY() + bullets.front()->getHeight();

		//If any of the sides from Bullet are NOT outside of Car => collision
		if(!(bottbullet <= topcar || topbullet >= bottcar || rightbullet <= leftcar || leftbullet >= rightcar)){
			if(carObjects[i]->getType() == "normal"){
				bullets.pop();
			//	std::cout << "HIT1!" << std::endl;
				} else if(carObjects[i]->getType() == "bonus"){
					bullets.pop();
					bullets.push(std::shared_ptr<Au::Bullet>(Fact->createBullet()));
					bullets.push(std::shared_ptr<Au::Bullet>(Fact->createBullet()));
					//std::cout << "HIT2!" << std::endl;
							}
			carObjects.erase(carObjects.begin() + i);
			carObjects.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));  //Must add, because the size needs to stay the same for the other statements
			carObjects.back()->setVel(carObjects[carObjects.size()-2]->getVel());
			carObjects[carObjects.size()-1]->setPosY(lane);
			if(carObjects[carObjects.size()-2]->getDirection() == 0){
				carObjects[carObjects.size()-1]->setPosX(carObjects[carObjects.size()-2]->getPosX() + 180);
				}
			if(carObjects[carObjects.size()-2]->getDirection() == 1){
				carObjects[carObjects.size()-1]->setPosX(carObjects[carObjects.size()-2]->getPosX() - 180);
				}
		}
	}
	if(carObjects[carObjects.size()-2]->getDirection() == 0){
		carObjects[i]->update();
		carObjects[i]->moveLeft(time);
		}
	if(carObjects[carObjects.size()-2]->getDirection() == 1){
		carObjects[i]->update();
		carObjects[i]->moveRight(time);
			}
	}
}


void CollisionHandler::checkBorderCarCollision(Au::Factory *Fact,std::vector<std::shared_ptr<Au::Car>>& carObjects){

	int random_integer;
	random_integer = (rand()%2)+1; // rand()%n we generate a number from 0 to n-1, and +1 so its not zero based
	//check lanes as well, destroying multiple cars on the same lane with bullets caused errors
	if(carObjects[0]->getPosX() < -60 && ((carObjects[0]->getPosY() == lane1) || (carObjects[0]->getPosY() == lane3)
			|| (carObjects[0]->getPosY() == lane5))){
    switch(random_integer){
    	    case 1:
    	    	carObjects.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
    	    	break;
    	    case 2:
    	    	carObjects.push_back(std::shared_ptr<Au::Car>(Fact->createBonusCar()));
    	    	break;
    }
		//carObjects.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
		carObjects[carObjects.size()-1]->setPosY(carObjects[0]->getPosY());
		carObjects[carObjects.size()-1]->setPosX(carObjects[carObjects.size()-2]->getPosX() + 180);
		carObjects[carObjects.size()-1]->setVel(carObjects[carObjects.size()-2]->getVel());
		carObjects.erase(carObjects.begin());
	}else if(carObjects[0]->getPosX() > 650 && ((carObjects[0]->getPosY() == lane2) || (carObjects[0]->getPosY() == lane4)
			|| (carObjects[0]->getPosY() == lane6))){
		carObjects.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
		carObjects[carObjects.size()-1]->setPosY(carObjects[0]->getPosY());
		carObjects[carObjects.size()-1]->setPosX(carObjects[carObjects.size()-2]->getPosX() - 180);
		carObjects[carObjects.size()-1]->setVel(carObjects[carObjects.size()-2]->getVel());
		carObjects.erase(carObjects.begin());
	}
}

