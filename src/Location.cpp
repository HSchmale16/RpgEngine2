#include "../include/Location.hpp"
#include "../include/Misc.h"
#include <algorithm>

Location::Location(std::string file) {
    json j;
    JSON_FROM_FILE(j, file);
    loadJson(j);
}

Location::~Location() {
    for(auto room : m_rooms) 
        delete room;
}

void Location::loadJson(json js) {
    EntityBase::loadJson(js);
    JSON_ATTEMPT_READ_STR(m_startRoomString, js, "startRoom");
    assert(!m_startRoomString.empty());

    auto rooms = js.find("rooms");
    if(rooms == js.end())
        throw "Missing rooms from location file";
    loadRooms(*rooms);

    m_startRoom = getRoom(m_startRoomString);
}

void Location::loadRooms(json js) {
    if(!js.is_array())
        throw "Rooms must be loaded from an array";
    if(js.empty())
        throw "Rooms must not be an empty array";
    for(auto room : js) {
        // TODO: Finish Loading Rooms
        Room* r = new Room(this, room);
        m_rooms.push_back(r);
    }
}

Room* Location::getStartRoom() {
    assert(m_startRoom != nullptr);
    return m_startRoom;
}

Room* Location::getRoom(std::string name) {
    auto it = std::find_if(m_rooms.begin(), m_rooms.end(),
        [&name](Room* const& r) {
            return name == r->getName();
        });
    if(it == m_rooms.end())
        throw "Requested room not found";
    return *it;
}

void Location::dump(std::ostream& out) {
    for(auto room : m_rooms) {
        room->dump(out);
    }
}
