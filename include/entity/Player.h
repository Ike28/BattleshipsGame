#pragma once
#include "../model/Hit.h"
#include "../model/GameMap.h"
#include "../model/Named.h"
#include <vector>

class Player : protected Named {
	private:
		std::vector<Hit> hitLog;
		GameMap * playerMap;
		bool computer;

	public:
		Player();
		Player(std::string name, GameMap * map, bool computer);
		Player(const Player& other);
		~Player();

		GameMap* map();
		bool isComputer();
		std::vector<Hit> getHitLog();
		std::string getName();
		void setName(std::string newName);
};