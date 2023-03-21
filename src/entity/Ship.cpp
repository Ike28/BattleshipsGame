#include "../../include/entity/Ship.h"

Ship::Ship() {
	size = 0;
	healthPoints = 0;
}

Ship::Ship(short int size) {
	this->size = size;
	healthPoints = size;
}

Ship::Ship(const Ship& other) {
	this->size = other.size;
	this->healthPoints = other.healthPoints;
}

Ship::~Ship() {

}

void Ship::hit() {
	if (isAlive()) {
		--healthPoints;
	}
}

bool Ship::isAlive() {
	return healthPoints > 0;
}

int Ship::getSize() {
	return size;
}
