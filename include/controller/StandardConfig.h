#pragma once
#include "GameConfig.h"
#include "../entity/Player.h"
#include "../view/UserInterface.h"
#include <queue>
#include <vector>

class StandardConfig : protected GameConfig {
	private:
		std::vector<Player * > players;
		std::queue<Player * > playerQueue;
		GameMap * generatePlayerMap();
		GameMap * generateComputerMap();
		UserInterface ui;

	public:
		StandardConfig();

		bool gameActive();
		void nextTurn();
		void run();
};
