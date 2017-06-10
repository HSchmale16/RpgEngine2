#include "../include/Door.hpp"
#include "../include/Misc.h"
#include <cassert>


Door::Door(Room* r, json js) {
    assert(r != nullptr);
    m_room = r;
    loadJson(js);
}

bool Door::loadJson(json js) {
    Entity::loadJson(js);
    JSON_ATTEMPT_READ_STR(m_linkTo, js, "linkTo");
    /// TODO: Add locking
}