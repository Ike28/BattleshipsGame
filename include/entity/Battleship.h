#pragma once
#include "Ship.h"
#include "../model/Named.h"

class Battleship : public Ship, protected Named {
	public:
		Battleship();
		~Battleship();

		std::string getName();
};
