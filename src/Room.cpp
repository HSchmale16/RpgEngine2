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

void Room::loadJson(json js) {
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
    if(!furniture.is_array())
        throw "Furniture must be loaded as an array";
    if(furniture.empty())
        return;
    for(auto& thing : furniture) {
        Furniture* f = new Furniture(this, thing);
        m_furniture.push_back(f);
        m_entities.push_back(f);
    }
}

void Room::dump(std::ostream& out) {
    Entity::dump(out);
    for(auto* ent : m_entities) {
        ent->dump(out);
    }
}

void Room::printLookText(std::ostream& out) {
    for(auto* ent : m_entities) {
        out << ent->getName() << " - ";
        ent->printLookText(out);
    }
}

Entity* Room::searchRoomByKeywords(StringVector& kws) {
    return searchEntitiesByKeywords(m_entities, kws);
}