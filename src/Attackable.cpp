#include "../include/Attackable.hpp"

uint64_t Attackable::getCurrentHealth() {
    return m_currentHealth;
}

uint64_t Attackable::getMaxHealth() {
    return m_maxHealth;
}