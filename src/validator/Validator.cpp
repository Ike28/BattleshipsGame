#include "../../include/validator/Validator.h"

bool Validator::validateCoords(std::pair<int, int> coords, int gameSize) {
	return !(coords.first < 0 || coords.first >= gameSize || coords.second < 0 || coords.second >= gameSize);
}

bool Validator::validateShipPlacement(std::pair<int, int> coords, ShipOrientation orientation, short int shipSize, int gameSize) {
	bool validCoords = validateCoords(coords, gameSize);

	if (!validCoords) {
		return false;
	}

	if (orientation == HORIZONTAL) {
		return coords.first + shipSize - 1 < gameSize;
	}
	else {
		return coords.second + shipSize - 1 < gameSize;
	}
}

bool Validator::validateMapSlot(std::pair<int, int> coords, ShipOrientation orientation, short int shipSize, int gameSize, GameMap * map) {
	bool validPlacement = validateShipPlacement(coords, orientation, shipSize, gameSize);

	if (!validPlacement) {
		return false;
	}

	if (orientation == HORIZONTAL) {
		for (int i = coords.first; i < coords.first + shipSize; ++i) {
			if (map->getLocation(i, coords.second)->getEntity() != nullptr) {
				return false;
			}
		}
	}
	else {
		for (int i = coords.second; i < coords.second + shipSize; ++i) {
			if (map->getLocation(coords.first, i)->getEntity() != nullptr) {
				return false;
			}
		}
	}

	return true;
}

bool Validator::validateHit(std::pair<int, int> coords, int gameSize, GameMap* map) {
	bool validCoords = validateCoords(coords, gameSize);
	if (!validCoords) {
		return false;
	}

	return !map->getLocation(coords.first, coords.second)->isHitAlready();
}
