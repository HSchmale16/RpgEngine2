#include "../include/Door.hpp"
#include "../include/Misc.h"
#include <cassert>


Door::Door(Room* r, json js) {
    assert(r != nullptr);
    m_room = r;
    loadJson(js);
}

void Door::loadJson(json js) {
    Entity::loadJson(js);
    JSON_ATTEMPT_READ_STR(m_linkTo, js, "linkTo");
    /// TODO: Add locking load
}

std::string Door::getLinkTo() {
    return m_linkTo;
}

bool Door::unlock(const Player& p) {
    if(m_isUnlocked)
        return true;
    // TODO: Add requirements checking
    return false;
}