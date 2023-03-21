#pragma once
#include "Ship.h"
#include "../model/Named.h"

class PatrolBoat : public Ship, protected Named {
	public:
		PatrolBoat();
		~PatrolBoat();

		std::string getName();
};
