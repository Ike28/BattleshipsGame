#pragma once
#include "MapPointMatrix.h"

class GameMap {
	private:
		MapPointMatrix * map;

	public:
		GameMap();
		GameMap(int size);
		GameMap(const GameMap& other);
		~GameMap();

		MapPoint * getLocation(int row, int column);
};
