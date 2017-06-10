#include "../include/Room.hpp"
#include "../include/Misc.h"

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
    JSON_GET_ITER_EXCEPT(js, doors, "doors");
    loadDoors(*doors);
    JSON_ATTEMPT_FUNC_OPT(js, "furniture", loadFurniture);
}

void Room::loadDoors(json& doors) {
    if(!doors.is_array())
        throw "Doors must be in an array";
    if(doors.empty())
        throw "All rooms must have at least one door";
    for(auto& door : doors) {
        Door* d = new Door(this, door);
        m_doors.push_back(d);
        m_entities.push_back(d);
    }
}

void Room::loadFurniture(json& furniture) {
    // TODO: Implement me, requires implementing furniture and inventory
}

void Room::dump(std::ostream& out) {
    for(auto e : m_entities)
        e->dump(out);
}