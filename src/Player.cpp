#include "../include/Player.hpp"

Player::Player(): Attackable(100) {}

Player::Player(json js): Inventory(js), Attackable(100) {}

Player::~Player() {}