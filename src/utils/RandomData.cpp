#include "../../include/utils/RandomData.h"
#include "stdlib.h"
#include "time.h"

int RandomData::getRandomInteger() {
	srand(time(0));
    return rand();
}

std::pair<int, int> RandomData::getRandomCoords(int mapSize) {
	int row = getRandomInteger() % mapSize;
	int column = getRandomInteger() % mapSize;

	return std::pair<int, int>(row, column);
}

ShipOrientation RandomData::getRandomOrientation() {
	int randomInt = getRandomInteger();
	if (randomInt % 2) {
		return HORIZONTAL;
	}
	return VERTICAL;
}
