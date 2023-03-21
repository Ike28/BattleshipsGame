#include "../../include/entity/AircraftCarrier.h"

AircraftCarrier::AircraftCarrier() : Ship::Ship(5) {
	name = "Patrol Boat";
}

AircraftCarrier::~AircraftCarrier() {

}

std::string AircraftCarrier::getName() {
	return name;
}
