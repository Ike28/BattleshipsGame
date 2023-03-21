#include "../../include/entity/PatrolBoat.h"

PatrolBoat::PatrolBoat() : Ship::Ship(2) {
	name = "Patrol Boat";
}

PatrolBoat::~PatrolBoat() {

}

std::string PatrolBoat::getName() {
	return name;
}
