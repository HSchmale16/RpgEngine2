#include "../include/Attackable.hpp"

Attackable::Attackable(AttributeInteger defHealth)
    : Attackable(defHealth, 1)
    {}

Attackable::Attackable(AttributeInteger defHealth, AttributeInteger baseAttack)
        : DEFAULT_HEALTH(defHealth), DEFAULT_BASE_ATTACK(baseAttack) {
    m_attributes.insert(std::make_pair("health", DEFAULT_HEALTH));
    m_attributes.insert(std::make_pair("max health", DEFAULT_HEALTH));
    m_attributes.insert(std::make_pair("base attack", DEFAULT_BASE_ATTACK));
}

Attackable::~Attackable() { }

AttributeInteger Attackable::getCurrentHealth() {
    return 0;
}

AttributeInteger Attackable::getMaxHealth() {
    return 0;
}