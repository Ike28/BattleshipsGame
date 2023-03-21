#pragma once
#include <utility>
#include "../entity/ShipOrientation.h"

class RandomData {
	private:
		int getRandomInteger();

	public:
		std::pair<int, int> getRandomCoords(int mapSize);
		ShipOrientation getRandomOrientation();
};
