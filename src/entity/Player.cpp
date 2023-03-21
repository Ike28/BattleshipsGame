#include "../../include/entity/Player.h"

Player::Player() {
	
}

Player::Player(std::string name, GameMap* map, bool computer) {
	this->name = name;
	playerMap = map;
	this->computer = computer;
}

Player::Player(const Player& other) {
	hitLog = other.hitLog;
	playerMap = other.playerMap;
	computer = other.computer;
}

Player::~Player() {

}

GameMap* Player::map() {
	return playerMap;
}

bool Player::isComputer() {
	return computer;
}

std::vector<Hit> Player::getHitLog() {
	return hitLog;
}

std::string Player::getName() {
	return name;
}

void Player::setName(std::string newName) {
	name = newName;
}
