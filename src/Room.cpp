#include "../include/Room.hpp"

Room::Room(const Location* loc, json def) {

}

Room::~Room() {
    for(auto ent : m_entities)
        delete ent;
}