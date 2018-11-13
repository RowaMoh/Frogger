/*
 * CollisionHandler.cpp
 *
 *  Created on: May 6, 2016
 *      Author: Kian
 */

#include "CollisionHandler.h"

CollisionHandler::CollisionHandler() {
	// TODO Auto-generated constructor stub

}

CollisionHandler::~CollisionHandler() {
	// TODO Auto-generated destructor stub
}

bool CollisionHandler::checkFrogCarCollision(Frog *Fr, std::shared_ptr<Car> Cr){
	//Sides of Frog rectangle
	leftfrog = Fr->getPosX();
	rightfrog = Fr->getPosX() + Fr->getWidth();
	topfrog = Fr->getPosY();
	bottfrog = Fr->getPosY() + Fr->getHeight();

		leftcar = Cr->getPosX();
		rightcar = Cr->getPosX() + Cr->getWidth();
		topcar = Cr->getPosY();
		bottcar = Cr->getPosY() + Cr->getHeight();

		//If any of the sides from Frog are outside of Car
	    if( bottfrog <= topcar )
	    {
	        return false;
	    }

	    if( topfrog >= bottcar )
	    {
	        return false;
	    }

	    if( rightfrog <= leftcar )
	    {
	        return false;
	    }

	    if( leftfrog >= rightcar )
	    {
	        return false;
	    }
	    //If none of the sides from Frog are outside Car => collision
	    return true;

}


bool CollisionHandler::checkBulletCarCollision(std::shared_ptr<Car> Car, std::shared_ptr<Bullet> bullets){
	//Sides of Frog rectangle
	leftbullet = bullets->getPosX();
	rightbullet = bullets->getPosX() + bullets->getWidth();
	topbullet = bullets->getPosY();
	bottbullet = bullets->getPosY() + bullets->getHeight();

	leftcar = Car->getPosX();
	rightcar = Car->getPosX() + Car->getWidth();
	topcar = Car->getPosY();
	bottcar = Car->getPosY() + Car->getHeight();
	        //If any of the sides from Bullet are outside of Car
		    if( bottbullet <= topcar )
		    {
		        return false;
		    }

		    if( topbullet >= bottcar )
		    {
		        return false;
		    }

		    if( rightbullet <= leftcar )
		    {
		        return false;
		    }

		    if( leftbullet >= rightcar )
		    {
		        return false;
		    }
		    //If none of the sides from Frog are outside Car => collision
		    return true;
}

void CollisionHandler::checkBorderCarCollision(Factory *Fact,std::vector<std::shared_ptr<Car>>& carObjects){
	if(carObjects[0]->getPosX() < -60 ){
		carObjects.push_back(std::shared_ptr<Car>(Fact->createCar()));
		carObjects[carObjects.size()-1]->setPosY(carObjects[0]->getPosY());
		carObjects[carObjects.size()-1]->setPosX(carObjects[carObjects.size()-2]->getPosX() + 180);
		carObjects.erase(carObjects.begin());
	}else if(carObjects[0]->getPosX() > 650){
		carObjects.push_back(std::shared_ptr<Car>(Fact->createCar()));
		carObjects[carObjects.size()-1]->setPosY(carObjects[0]->getPosY());
		carObjects[carObjects.size()-1]->setPosX(carObjects[carObjects.size()-2]->getPosX() - 180);
		carObjects.erase(carObjects.begin());
	}
}

