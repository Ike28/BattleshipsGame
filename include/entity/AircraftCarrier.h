#pragma once
#include "Ship.h"
#include "../model/Named.h"

class AircraftCarrier : public Ship, protected Named {
public:
	AircraftCarrier();
	~AircraftCarrier();

	std::string getName();
};
