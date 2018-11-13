/*
 * InputHandler.h
 *
 *  Created on: Apr 11, 2016
 *      Author: Kian
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_
#include "Frog.h"
#include "Bullet.h"
#include <memory>
namespace Au{
class InputHandler {
public:
	InputHandler();
	virtual ~InputHandler();
	virtual void update(Au::Frog*,std::shared_ptr<Au::Bullet> ,bool&) = 0;
	virtual void update1(Au::Frog*,bool&) = 0;
};
}
#endif /* INPUTHANDLER_H_ */
