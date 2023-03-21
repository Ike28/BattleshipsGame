#include "../../include/model/GameMap.h"

GameMap::GameMap() {
	map = new MapPointMatrix(10);
}

GameMap::GameMap(int size) {
	map = new MapPointMatrix(size);
}

GameMap::GameMap(const GameMap& other) {
	map = other.map;
}

GameMap::~GameMap() {
	delete map;
}

MapPoint * GameMap::getLocation(int row, int column) {
	return *(map->getElement(row, column));
}