#include "../../include/model/MapPoint.h"

MapPoint::MapPoint() {
	xCoord = 0;
	yCoord = 0;
	hitAlready = false;
	entity = nullptr;
}

MapPoint::MapPoint(short int xCoordinate, short int yCoordinate) {
	xCoord = xCoordinate;
	yCoord = yCoordinate;
	hitAlready = false;
	entity = nullptr;
}

MapPoint::MapPoint(const MapPoint& other) {
	xCoord = other.xCoord;
	yCoord = other.yCoord;
	hitAlready = other.hitAlready;
	entity = other.entity;
}

MapPoint::~MapPoint() {
	entity = nullptr;
}

void MapPoint::registerEntity(Ship * otherEntity) {
	if (otherEntity != nullptr && this->entity == nullptr) {
		entity = otherEntity;
	}
}

bool MapPoint::hit() {
	hitAlready = true;
	if (entity != nullptr) {
		entity->hit();
		return true;
	}
	return false;
}

Ship* MapPoint::getEntity() {
	return entity;
}

bool MapPoint::isHitAlready() {
	return hitAlready;
}
