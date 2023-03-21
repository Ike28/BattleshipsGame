#pragma once
#include <string>
#include <utility>
#include "../model/GameMap.h"
#include "../entity/ShipOrientation.h"
#include "../entity/Player.h"

class UserInterface {
	private:
		bool tryParseInt(std::string& input, int& output);
		bool tryParseOrientation(std::string& input);
		int getInteger(std::string inputText);
		std::string mapToGameString(GameMap& map);
		std::string mapToDebugString(GameMap& map);

	public:
		void displayInGameMap(GameMap& map);
		void displayDebugMap(GameMap& map);
		std::pair<int, int> getInputCoords(std::string inputText);
		ShipOrientation getInputOrientation();
		std::string getInputName();
		void announceTurn(Player * player);
		void displayTurnStatus(std::pair<int, int> location, bool turnResult);
};
