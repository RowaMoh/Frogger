/*
 * main.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Kian
 */
#include "Game.h"
#include "FactorySDL.h"

int main(int argc, char* argv[]){
	//Maak factorysdl -> Factory *Fact = new FactorySDL(); geef fact door naar Game constructor en Start game, delete ook in main

	Au::Factory *Fact = new Au_sdl::FactorySDL(); //Fact points to an object of type FactorySDL(derived of Factory)
	Game gameObject(Fact);
	gameObject.start();
	Fact->close();
	delete Fact;

	return 0;
}
