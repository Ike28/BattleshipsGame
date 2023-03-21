#pragma once
#include <string>

class Ship {
	protected:
		short int size;
		short int healthPoints;

	public:
		Ship();
		Ship(short int size);
		Ship(const Ship& other);
		~Ship();

		bool isAlive();
		void hit();
		int getSize();
};
