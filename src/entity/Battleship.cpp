#include "../../include/entity/Battleship.h"

Battleship::Battleship() : Ship::Ship(4) {
	name = "Battleship";
}

Battleship::~Battleship() {

}

std::string Battleship::getName() {
	return name;
}
