#include "../include/Player.hpp"

Player::Player(): Attackable(100) {}

Player::Player(json js): Inventory(js), Attackable(100) {}

Player::~Player() {}

void Player::dump(std::ostream& out) {
    for(auto kv : m_attributes) {
        out << kv.first << " = " << kv.second << std::endl;
    }
}