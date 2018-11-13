/*
 * Entity.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: Kian
 */

#include "Entity.h"

namespace Au {

Entity::Entity() {
	// TODO Auto-generated constructor stub

}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

float Entity::getPosX(){
	return x;
}

float Entity::getPosY(){
	return y;
}

void Entity::setPosX(float posx){
	x = posx;
}

void Entity::setPosY(float posy){
	y = posy;
}

}
