#pragma once
#include <utility>
#include "../entity/ShipOrientation.h"
#include "../model/GameMap.h"

class Validator {
	public:
		static bool validateCoords(std::pair<int, int> coords, int gameSize);
		static bool validateShipPlacement(std::pair<int, int> coords, ShipOrientation orientation, 
			short int shipSize, int gameSize);
		static bool validateMapSlot(std::pair<int, int> coords, ShipOrientation orientation, 
			short int shipSize, int gameSize, GameMap * map);
		static bool validateHit(std::pair<int, int> coords, int gameSize, GameMap* map);
};
