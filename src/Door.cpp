#include "../include/Door.hpp"
#include <cassert>


Door::Door(Room* r, json js) {
    assert(r != nullptr);
    m_room = r;
    loadJson(js);
}

bool Door::loadJson(json js) {
    Entity::loadJson(js);
}