/*

 * Game.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Kian
 */

#include "Game.h"
#include "FrogSDL.h"
#include "FactorySDL.h"
#include "InputHandler.h"
#include "TimerSDL.h"
#include "CollisionHandler.h"
#include <vector>
//#include <iostream>
#include <queue>

using namespace Au; //OM TE VOORKOMEN DAT VOOR ALLE METHODS Au:: getyped moet worden

Game::Game(Au::Factory* pFact){
	gRunning = true;
	Fact = pFact;
}

Game::~Game(){
	//printf("Destroyed!");
}

void Game::start(){
	CollisionHandler Coll;
	Fact->init();
	Fact->loadBackground();
	Timer* stepTimer = Fact->createTimer();
	Timer* timer = Fact->createTimer();
	timer->start();
	InputHandler* In = Fact->createControl();
	Frog* Fr = Fact->createFrog();
	std::queue<std::shared_ptr<Au::Bullet>> bullets1;
	std::vector<std::shared_ptr<Au::Car>> carObjects1;
	std::vector<std::shared_ptr<Au::Car>> carObjects2;
	std::vector<std::shared_ptr<Au::Car>> carObjects3;
	std::vector<std::shared_ptr<Au::Car>> carObjects4;
	std::vector<std::shared_ptr<Au::Car>> carObjects5;
	std::vector<std::shared_ptr<Au::Car>> carObjects6;

	//std::vector<std::vector<std::shared_ptr<Au::Car>>> vectorcarObjects;

	for(unsigned int i=0;i<4;i++){
			bullets1.push(std::shared_ptr<Au::Bullet>(Fact->createBullet()));

			carObjects1.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
			carObjects2.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
			carObjects3.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
			carObjects4.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
			carObjects5.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
			carObjects6.push_back(std::shared_ptr<Au::Car>(Fact->createCar()));
			carObjects1[i]->setPosY(lane1);
			carObjects2[i]->setPosY(lane2);
			carObjects3[i]->setPosY(lane3);
			carObjects4[i]->setPosY(lane4);
			carObjects5[i]->setPosY(lane5);
			carObjects6[i]->setPosY(lane6);
		}

	carObjects1[0]->setPosX(0);
	carObjects2[0]->setPosX(600);
	carObjects3[0]->setPosX(0);
	carObjects4[0]->setPosX(600);
	carObjects5[0]->setPosX(0);
	carObjects6[0]->setPosX(600);

	for(unsigned int i=0;i<3;i++){
		carObjects1[i+1]->setPosX(carObjects1[i]->getPosX()+180);
		carObjects2[i+1]->setPosX(carObjects2[i]->getPosX()-180);
		carObjects3[i+1]->setPosX(carObjects3[i]->getPosX()+180);
		carObjects4[i+1]->setPosX(carObjects4[i]->getPosX()-180);
		carObjects5[i+1]->setPosX(carObjects5[i]->getPosX()+180);
		carObjects6[i+1]->setPosX(carObjects6[i]->getPosX()-180);
	}
//---------------------------------------------------------------------------------------------------------------
	while(gRunning == true){
		float timeStep = stepTimer->getTicks() / 1000.f;
		stepTimer->start();
		Fact->clear();
		Fact->loadBackground();
		Fact->showBullets(bullets1.size());
		Fact->showLives(Fr->getLives());
		//Fixed the crash(caused after removing the last bullet): after the bullet queue is empty, was still using/passing it through InputHandler => big nono
		//So was "using" objects while they were deleted => crash
		if(!bullets1.empty()){
			//Fact->showBullets(bullets1.size());
			In->update(Fr,bullets1.front(),gRunning);
			if(bullets1.front()->getPosY() <= Fr->getPosY()){
				bullets1.front()->shoot(timeStep);
				bullets1.front()->update();
				}
			if(bullets1.front()->getPosY() < 0){
					bullets1.pop();
				}
		} else {
			In->update1(Fr,gRunning);
		}

		Coll.checkFrogBulletCarCollision(Fr,carObjects1,Fact,bullets1,lane1,timeStep);
		Coll.checkFrogBulletCarCollision(Fr,carObjects2,Fact,bullets1,lane2,timeStep);
		Coll.checkFrogBulletCarCollision(Fr,carObjects3,Fact,bullets1,lane3,timeStep);
		Coll.checkFrogBulletCarCollision(Fr,carObjects4,Fact,bullets1,lane4,timeStep);
		Coll.checkFrogBulletCarCollision(Fr,carObjects5,Fact,bullets1,lane5,timeStep);
		Coll.checkFrogBulletCarCollision(Fr,carObjects6,Fact,bullets1,lane6,timeStep);

		Coll.checkBorderCarCollision(Fact,carObjects1);
		Coll.checkBorderCarCollision(Fact,carObjects2);
		Coll.checkBorderCarCollision(Fact,carObjects3);
		Coll.checkBorderCarCollision(Fact,carObjects4);
		Coll.checkBorderCarCollision(Fact,carObjects5);
		Coll.checkBorderCarCollision(Fact,carObjects6);
		timer->update();
		Fr->update();
		Fact->present();

		if(Fr->win() == true){
					for(unsigned int i = 0; i < 4; i++){
						carObjects1[i]->setVel(carObjects1[i]->getVel()+10);
						carObjects2[i]->setVel(carObjects2[i]->getVel()+10);
						carObjects3[i]->setVel(carObjects3[i]->getVel()+10);
						carObjects4[i]->setVel(carObjects4[i]->getVel()+10);
						carObjects5[i]->setVel(carObjects5[i]->getVel()+10);
						carObjects6[i]->setVel(carObjects6[i]->getVel()+10);
						}
					Fr->setPosX(300);
					Fr->setPosY(435);
					timer->start();
					}else if(Fr->getLives() == 0){
						Fact->showLives(Fr->getLives());
						delete Fr;
						Fact->createFrog();
						while(!bullets1.empty()){
							bullets1.pop();
						}
						for(unsigned int i = 0; i < 4; i++){
							carObjects1[i]->setVel(100);
							carObjects2[i]->setVel(100);
							carObjects3[i]->setVel(100);
							carObjects4[i]->setVel(100);
							carObjects5[i]->setVel(100);
							carObjects6[i]->setVel(100);
							bullets1.push(std::shared_ptr<Au::Bullet>(Fact->createBullet()));
						}
						timer->start();
					}
	}
	delete Fr; //needs to be explicitly deleted, cause its a raw pointer
		          //=> solution: use smart pointer(deletes here/outside scope) OR just delete after loop.
		         //used raw-(frog, etc.) and smart pointers(cars, etc.), just showing how to use both
	delete stepTimer;
	delete In;
}




