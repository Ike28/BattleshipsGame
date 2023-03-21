#include "../../include/model/Hit.h"

Hit::Hit() {
	location = nullptr;
}

Hit::Hit(MapPoint* location) {
	this->location = location;
}

Hit::Hit(const Hit& other) {
	location = other.location;
}

Hit::~Hit() {
	location = nullptr;
}

MapPoint* Hit::getLocation() {
	return location;
}
