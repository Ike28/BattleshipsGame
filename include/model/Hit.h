#pragma once
#include "MapPoint.h"

class Hit {
	private:
		MapPoint * location;

	public:
		Hit();
		Hit(MapPoint * location);
		Hit(const Hit& other);
		~Hit();

		MapPoint * getLocation();
};
