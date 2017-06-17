#include "../include/Furniture.hpp"
#include <cassert>

Furniture::Furniture(Room* r, json js) : Inventory(js) {
    assert(r != nullptr);
    m_room = r;
}

Furniture::~Furniture() { }