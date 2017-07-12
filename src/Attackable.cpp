#include "../include/Attackable.hpp"

const AttributeInteger Attackable::DEFAULT_HEALTH = 100;
const AttributeInteger Attackable::DEFAULT_BASE_ATTACK = 1;
const AttributeInteger Attackable::DEFAULT_BASE_DEFENSE = 1;

Attackable::Attackable()
    : Attackable(DEFAULT_HEALTH) {}

Attackable::Attackable(AttributeInteger defHealth)
    : Attackable(defHealth, DEFAULT_BASE_ATTACK) {}

Attackable::Attackable(AttributeInteger defHealth,
                       AttributeInteger baseAttack) {
    m_attributes.insert(std::make_pair("health", DEFAULT_HEALTH));
    m_attributes.insert(std::make_pair("max_health", DEFAULT_HEALTH));
    m_attributes.insert(std::make_pair("base_attack", DEFAULT_BASE_ATTACK));
    m_attributes.insert(std::make_pair("base_defense", DEFAULT_BASE_DEFENSE));
}

Attackable::~Attackable() {}

AttributeInteger Attackable::getCurrentHealth() {
    return m_attributes["health"];
}

AttributeInteger Attackable::getMaxHealth() {
    return m_attributes["max health"];
}

void Attackable::restoreHealth() {
    m_attributes["health"] = m_attributes["max_health"];
}