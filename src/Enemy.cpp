/*
 * Enemy.cpp
 *
 *  Created on: Jun 19, 2016
 *      Author: Kian
 */

#include "Enemy.h"
namespace Au{
Enemy::Enemy() {
	// TODO Auto-generated constructor stub

}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

float Enemy::getVel(){
	return VelX;
}

void Enemy::setVel(float pVel){
	VelX = pVel;
}

}
