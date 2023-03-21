#pragma once

class GameConfig {
	public:
		virtual bool gameActive() = 0;
		virtual void nextTurn() = 0;
};
