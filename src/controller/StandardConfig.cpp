#include "../../include/controller/StandardConfig.h"
#include "../../include/view/UserInterface.h"
#include "../../include/entity/PatrolBoat.h"
#include "../../include/entity/Cruiser.h"
#include "../../include/entity/Battleship.h"
#include "../../include/entity/AircraftCarrier.h"
#include "../../include/utils/RandomData.h"
#include "../../include/validator/Validator.h"

GameMap * StandardConfig::generatePlayerMap() {
	GameMap * playerMap = new GameMap();
	std::vector<Ship * > ships;

	PatrolBoat * patrolBoat = new PatrolBoat();
	ships.push_back(patrolBoat);
	Cruiser * firstCruiser = new Cruiser();
	ships.push_back(firstCruiser);
	Cruiser * secondCruiser = new Cruiser();
	ships.push_back(secondCruiser);
	Battleship * battleShip = new Battleship();
	ships.push_back(battleShip);
	AircraftCarrier * aircraftCarrier = new AircraftCarrier();
	ships.push_back(aircraftCarrier);

	for (std::vector<Ship * >::iterator it = ships.begin(); it < ships.end(); ++it) {
		Validator validator = Validator();
		std::pair<int, int> coords = ui.getInputCoords("Choose your next ship location, size=" + (*it)->getSize());
		ShipOrientation orientation = ui.getInputOrientation();
		while (!validator.validateMapSlot(coords, orientation, (*it)->getSize(), 10, playerMap)) {
			coords = ui.getInputCoords("Invalid ship placement (make sure it fits)");
		}

		if (orientation == HORIZONTAL) {
			for (int i = 0; i < (*it)->getSize(); ++i) {
				playerMap->getLocation(coords.first, coords.second + i)->registerEntity((*it));
			}
		}
		else {
			for (int i = 0; i < (*it)->getSize(); ++i) {
				playerMap->getLocation(coords.first + i, coords.second)->registerEntity((*it));
			}
		}
	}

	return playerMap;
}

GameMap * StandardConfig::generateComputerMap() {
	GameMap * computerMap = new GameMap();
	std::vector<Ship*> ships;
	
	PatrolBoat * patrolBoat = new PatrolBoat();
	ships.push_back(patrolBoat);
	Cruiser * firstCruiser = new Cruiser();
	ships.push_back(firstCruiser);
	Cruiser * secondCruiser = new Cruiser();
	ships.push_back(secondCruiser);
	Battleship * battleShip = new Battleship();
	ships.push_back(battleShip);
	AircraftCarrier * aircraftCarrier = new AircraftCarrier();
	ships.push_back(aircraftCarrier);

	for (std::vector<Ship * >::iterator it = ships.begin(); it < ships.end(); ++it) {
		RandomData dataGen = RandomData();
		Validator validator = Validator();
		std::pair<int, int> coords = dataGen.getRandomCoords(10);
		ShipOrientation orientation = dataGen.getRandomOrientation();
		while (!validator.validateMapSlot(coords, orientation, (*it)->getSize(), 10, computerMap)) {
			coords = dataGen.getRandomCoords(10);
			ShipOrientation orientation = dataGen.getRandomOrientation();
		}

		if (orientation == HORIZONTAL) {
			for (int i = 0; i < (*it)->getSize(); ++i) {
				computerMap->getLocation(coords.first, coords.second + i)->registerEntity((*it));
			}
		}
		else {
			for (int i = 0; i < (*it)->getSize(); ++i) {
				computerMap->getLocation(coords.first + i, coords.second)->registerEntity((*it));
			}
		}
	}

	return computerMap;
}

StandardConfig::StandardConfig() {
	ui = UserInterface();
	std::string playerName = ui.getInputName();

	GameMap * playerMap = generatePlayerMap();
	Player * player = new Player(playerName, playerMap, false);
	players.push_back(player);

	GameMap * computerMap = generateComputerMap();
	Player * computer = new Player("Computer", computerMap, true);
	players.push_back(computer);

	playerQueue.push(player);
	playerQueue.push(computer);

	ui.displayDebugMap(*playerMap);
	ui.displayDebugMap(*computerMap);
}

bool StandardConfig::gameActive() {
	return false;
}

void StandardConfig::nextTurn() {
	Player* nextPlayer = playerQueue.front();
	playerQueue.pop();
	bool result; std::pair<int, int> hitCoords;

	ui.announceTurn(nextPlayer);
	RandomData dataGen = RandomData();
	Validator validator = Validator();
	if (nextPlayer->isComputer()) {
		hitCoords = dataGen.getRandomCoords(10);
		while (!validator.validateHit(hitCoords, 10, nextPlayer->map())) {
			hitCoords = dataGen.getRandomCoords(10);
		}

		result = nextPlayer->map()->getLocation(hitCoords.first, hitCoords.second)->hit();
	}
	else {
		ui.displayInGameMap(*playerQueue.front()->map());
		hitCoords = ui.getInputCoords("Next hit:");
		while (!validator.validateHit(hitCoords, 10, nextPlayer->map())) {
			hitCoords = ui.getInputCoords("We have already attacked this location, captain. Choose another:");
		}

		result = nextPlayer->map()->getLocation(hitCoords.first, hitCoords.second)->hit();
	}
	ui.displayTurnStatus(hitCoords, result);
	playerQueue.push(nextPlayer);
}

void StandardConfig::run() {
}
