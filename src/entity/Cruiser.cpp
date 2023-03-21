#include "../../include/entity/Cruiser.h"

Cruiser::Cruiser() : Ship::Ship(3) {
	name = "Cruiser";
}

Cruiser::~Cruiser() {

}

std::string Cruiser::getName() {
	return name;
}
