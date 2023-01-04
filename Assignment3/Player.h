#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"

class Player : public Object {

	public:

		Player(int, int);
		void move(int, int);

};

#endif
