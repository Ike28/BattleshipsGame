#pragma once
#include "../entity/Ship.h"

class MapPoint {
	private:
		short int xCoord;
		short int yCoord;
		bool hitAlready;
		Ship * entity;

	public:
		MapPoint();
		MapPoint(short int xCoordinate, short int yCoordinate);
		MapPoint(const MapPoint& other);
		~MapPoint();

		void registerEntity(Ship * otherEntity);
		bool hit();
		bool isHitAlready();
		Ship* getEntity();
};