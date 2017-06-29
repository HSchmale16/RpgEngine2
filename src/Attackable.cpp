#include "../include/Attackable.hpp"

Attackable::Attackable() {

}

Attackable::~Attackable() { }

uint16_t Attackable::getCurrentHealth() {
    return m_currentHealth;
}

uint16_t Attackable::getMaxHealth() {
    return m_maxHealth;
}