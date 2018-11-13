/*
 * Entity.h
 *
 *  Created on: Jun 18, 2016
 *      Author: Kian
 */

#ifndef ENTITY_H_
#define ENTITY_H_
namespace Au {
class Entity {
public:
	Entity();
	virtual ~Entity();
	void setPosX(float);
	void setPosY(float);
	float getPosY();
	float getPosX();
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void update() = 0;

protected:
	float x,y;
	float lane1 = 75;
	float lane2 = 120;
	float lane3 = 210;
	float lane4 = 255;
	float lane5 = 345;
	float lane6 = 390;
};
}
#endif /* ENTITY_H_ */
