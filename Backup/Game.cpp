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
#include <iostream>
#include <queue>

Game::Game(){
	gRunning = true;
}

Game::~Game(){
	//printf("Destroyed!");
}

void Game::start(){
}

bool Game::running(){
	return gRunning;
	}

void Game::quit(){
	gRunning = false;
	}



int main(int argc, char* argv[]){
	float lane1 = 74;
	float lane2 = 120;
	float lane3 = 212;
	float lane4 = 257;
	float lane5 = 344;
	float lane6 = 390;
	Game game;
	CollisionHandler Coll;
	Factory *Fact = new FactorySDL(); //Fact points to an object of type FactorySDL(derived of Factory)
	Fact->init();
	Fact->loadBackground();
	Timer* stepTimer = Fact->createTimer();
	InputHandler* In = Fact->createControl();
	Frog* Fr = Fact->createFrog();

	//std::vector<std::shared_ptr<Bullet>> bullets;
	std::queue<std::shared_ptr<Bullet>> bullets1;

	std::vector<std::shared_ptr<Car>> carObjects1;
	std::vector<std::shared_ptr<Car>> carObjects2;
	std::vector<std::shared_ptr<Car>> carObjects3;
	std::vector<std::shared_ptr<Car>> carObjects4;
	std::vector<std::shared_ptr<Car>> carObjects5;
	std::vector<std::shared_ptr<Car>> carObjects6;

	for(unsigned int i=0;i<4;i++){
		bullets1.push(std::shared_ptr<Bullet>(Fact->createBullet()));

		carObjects1.push_back(std::shared_ptr<Car>(Fact->createCar()));
		carObjects2.push_back(std::shared_ptr<Car>(Fact->createCar()));
		carObjects3.push_back(std::shared_ptr<Car>(Fact->createCar()));
		carObjects4.push_back(std::shared_ptr<Car>(Fact->createCar()));
		carObjects5.push_back(std::shared_ptr<Car>(Fact->createCar()));
		carObjects6.push_back(std::shared_ptr<Car>(Fact->createCar()));
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

//--------------------------Game loop-----------------------
	while(game.running() == true){
		float timeStep = stepTimer->getTicks() / 1000.f;
		stepTimer->start();
		Fact->clear();
		Fact->loadBackground();

		//Fixed the crash(caused after removing the last bullet): after the bullet queue is empty, was still using/passing it through InputHandler => big nono
		//So was "using" objects while they were deleted => crash
		if(!bullets1.empty()){
			In->update(Fr,&game,bullets1.front());
			if(bullets1.front()->getPosY() <= Fr->getPosY()){
				bullets1.front()->shoot(timeStep);
				bullets1.front()->update();
				}
			if(bullets1.front()->getPosY() < 0){
					bullets1.pop();
				}
		} else {
			In->update1(Fr,&game);
		}

		for(unsigned int i = 0; i < carObjects1.size(); i++){
			if(Coll.checkFrogCarCollision(Fr,carObjects1[i]) == true ||
					Coll.checkFrogCarCollision(Fr,carObjects2[i]) == true ||
					     Coll.checkFrogCarCollision(Fr,carObjects3[i]) == true ||
						     Coll.checkFrogCarCollision(Fr,carObjects4[i]) == true ||
							     Coll.checkFrogCarCollision(Fr,carObjects5[i]) == true ||
								     Coll.checkFrogCarCollision(Fr,carObjects6[i]) == true){
						Fr->setPosX(300);
						Fr->setPosY(440);
					}

			if(!bullets1.empty() && Coll.checkBulletCarCollision(carObjects1[i],bullets1.front()) == true){
							//if((Coll.checkBulletCarCollision(carObjects1[i],bullets1.front()) == true) && !bullets1.empty()){ WON'T WORK: because it checks collision before it knows if its empty
							carObjects1.erase(carObjects1.begin() + i);
							carObjects1.push_back(std::shared_ptr<Car>(Fact->createCar()));  //Must add, because the size needs to stay the same for the other statements
							carObjects1[carObjects1.size()-1]->setPosY(lane1);
							carObjects1[carObjects1.size()-1]->setPosX(carObjects1[carObjects1.size()-2]->getPosX() + 180);
							//std::cout << "HIT!" << endl;
							bullets1.pop();
										}
			if(!bullets1.empty() && Coll.checkBulletCarCollision(carObjects2[i],bullets1.front()) == true){
				carObjects2.erase(carObjects2.begin() + i);
											carObjects2.push_back(std::shared_ptr<Car>(Fact->createCar()));  //Must add, because the size needs to stay the same for the other statements
											carObjects2[carObjects2.size()-1]->setPosY(lane2);
											carObjects2[carObjects2.size()-1]->setPosX(carObjects2[carObjects2.size()-2]->getPosX() - 180);
											//std::cout << "HIT!" << endl;
											bullets1.pop();
			}

			if(!bullets1.empty() && Coll.checkBulletCarCollision(carObjects3[i],bullets1.front()) == true){
				carObjects3.erase(carObjects3.begin() + i);
											carObjects3.push_back(std::shared_ptr<Car>(Fact->createCar()));  //Must add, because the size needs to stay the same for the other statements
											carObjects3[carObjects3.size()-1]->setPosY(lane3);
											carObjects3[carObjects3.size()-1]->setPosX(carObjects3[carObjects3.size()-2]->getPosX() + 180);
											//std::cout << "HIT!" << endl;
											bullets1.pop();
						}

			if(!bullets1.empty() && Coll.checkBulletCarCollision(carObjects4[i],bullets1.front()) == true){
				carObjects4.erase(carObjects4.begin() + i);
											carObjects4.push_back(std::shared_ptr<Car>(Fact->createCar()));  //Must add, because the size needs to stay the same for the other statements
											carObjects4[carObjects4.size()-1]->setPosY(lane4);
											carObjects4[carObjects4.size()-1]->setPosX(carObjects4[carObjects4.size()-2]->getPosX() - 180);
											//std::cout << "HIT!" << endl;
											bullets1.pop();
						}

			if(!bullets1.empty() && Coll.checkBulletCarCollision(carObjects5[i],bullets1.front()) == true){
				carObjects5.erase(carObjects5.begin() + i);
											carObjects5.push_back(std::shared_ptr<Car>(Fact->createCar()));  //Must add, because the size needs to stay the same for the other statements
											carObjects5[carObjects5.size()-1]->setPosY(lane5);
											carObjects5[carObjects5.size()-1]->setPosX(carObjects5[carObjects5.size()-2]->getPosX() + 180);
											//std::cout << "HIT!" << endl;
											bullets1.pop();
						}
			if(!bullets1.empty() && Coll.checkBulletCarCollision(carObjects6[i],bullets1.front()) == true){
				carObjects6.erase(carObjects6.begin() + i);
				carObjects6.push_back(std::shared_ptr<Car>(Fact->createCar()));  //Must add, because the size needs to stay the same for the other statements
				carObjects6[carObjects6.size()-1]->setPosY(lane6);
				carObjects6[carObjects6.size()-1]->setPosX(carObjects6[carObjects6.size()-2]->getPosX() - 180);
				//std::cout << "HIT!" << endl;
				bullets1.pop();
						}

						carObjects1[i]->moveLeft(timeStep);
						carObjects2[i]->moveRight(timeStep);
						carObjects3[i]->moveLeft(timeStep);
						carObjects4[i]->moveRight(timeStep);
						carObjects5[i]->moveLeft(timeStep);
						carObjects6[i]->moveRight(timeStep);

					carObjects1[i]->update();
					carObjects2[i]->update();
					carObjects3[i]->update();
					carObjects4[i]->update();
					carObjects5[i]->update();
					carObjects6[i]->update();

				}

		Coll.checkBorderCarCollision(Fact,carObjects1);
		Coll.checkBorderCarCollision(Fact,carObjects2);
		Coll.checkBorderCarCollision(Fact,carObjects3);
		Coll.checkBorderCarCollision(Fact,carObjects4);
		Coll.checkBorderCarCollision(Fact,carObjects5);
		Coll.checkBorderCarCollision(Fact,carObjects6);


		Fr->update();
		Fact->present();
	}
	Fact->close();
	delete Fr; //needs to be explicitly deleted, cause its a raw pointer
	          //=> solution: use smart pointer(deletes here/outside scope) OR just delete after loop.
	         //used raw(frog, etc.) and smart pointers(cars, etc.), just showing how to use both
	delete Fact;
	delete stepTimer;
	delete In;

	return 0;
}
