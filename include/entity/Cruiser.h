#pragma once
#include "Ship.h"
#include "../model/Named.h"

class Cruiser : public Ship, protected Named {
	public:
		Cruiser();
		~Cruiser();

		std::string getName();
};
