#include "../../include/view/UserInterface.h"
#include <iostream>

std::string UserInterface::mapToGameString(GameMap& map) {
	std::string result = "\n\\\t";
	for (int i = 0; i < 10; i++) {
		result += std::to_string(i) + "\t";
	}

	for (int i = 0; i < 10; i++) {
		result += "\n" + std::to_string(i);
		result += "\t";

		for (int j = 0; j < 10; j++) {
			if (map.getLocation(i, j)->hit()) {
				if (map.getLocation(i, j)->getEntity() != nullptr) {
					result += "X\t";
				}
				else {
					result += "o\t";
				}
			}
			else {
				result += "_\t";
			}
		}
	}

	return result;
}

std::string UserInterface::mapToDebugString(GameMap& map) {
	std::string result = "\n \\|";
	for (int i = 0; i < 10; i++) {
		result += std::to_string(i) + " ";
	}

	for (int i = 0; i < 10; i++) {
		result += "\n " + std::to_string(i);
		result += "|";

		for (int j = 0; j < 10; j++) {
			if (map.getLocation(i, j)->getEntity() != nullptr) {
					result += "X ";
			}
			else {
				result += "_ ";
			}
		}
	}

	return result;
}

void UserInterface::displayInGameMap(GameMap& map) {
	std::string displayResult = mapToGameString(map);
	std::cout << displayResult;
}

void UserInterface::displayDebugMap(GameMap& map) {
	std::string displayResult = mapToDebugString(map);
	std::cout << displayResult;
}

bool UserInterface::tryParseInt(std::string& input, int& output) {
	try {
		output = std::stoi(input);
	}
	catch (std::invalid_argument) {
		return false;
	}
	return true;
}

bool UserInterface::tryParseOrientation(std::string& input) {
	if (input == "H" || input == "V") {
		return true;
	}
	return false;
}

int UserInterface::getInteger(std::string inputText) {
	std::string input;
	int res;

	std::cout << inputText;
	getline(std::cin, input);

	while (!tryParseInt(input, res)) {
		std::cout << "Bad entry. Enter a NUMBER: ";
		getline(std::cin, input);
	}
	return res;
}

std::pair<int, int> UserInterface::getInputCoords(std::string inputText) {
	std::cout << inputText << '\n';
	int row = getInteger(">row : ");
	int column = getInteger(">column : ");
	return std::pair<int, int>(row, column);
}

ShipOrientation UserInterface::getInputOrientation() {
	std::string input;
	std::cout << "\nInput ship orientation\n(H = horizontal, V = vertical): ";
	getline(std::cin, input);

	while (!tryParseOrientation(input)) {
		std::cout << "Bad entry. Enter H or V: ";
		getline(std::cin, input);
	}
	
	if (input == "H") {
		return HORIZONTAL;
	}
	return VERTICAL;
}

std::string UserInterface::getInputName() {
	std::cout << "\nChoose your name, captain!\n> ";
	std::string result;
	getline(std::cin, result);
	return result;
}

void UserInterface::announceTurn(Player * player) {
	std::cout << "> " << player->getName() + "'s turn:" << '\n';
}

void UserInterface::displayTurnStatus(std::pair<int, int> location, bool turnResult) {
	std::string message = ((turnResult) ? "Ship attacked!" : "Missed!");
	message += " (position " + std::to_string(location.first)
		+ ":" + std::to_string(location.second) + ")";
	std::cout << "> " << message << '\n';
}
