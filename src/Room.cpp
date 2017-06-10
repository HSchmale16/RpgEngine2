#include "../include/Room.hpp"

Room::Room(const Location* loc, json def) : m_location(loc) {
    assert(m_location != nullptr);
    if(!def.is_object())
        throw "Room definition must be an object";
    loadJson(def);
}

Room::~Room() {
    for(auto ent : m_entities)
        delete ent;
}

bool Room::loadJson(json js) {
    Entity::loadJson(js);
    /// TODO: implement loading of doors and stuff
}

void Room::loadDoors(json& js) {

}

void Room::loadFurniture(json& js) {
    
}