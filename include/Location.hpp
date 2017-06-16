#ifndef LOCATION__HPP
#define LOCATION__HPP

#include "Entity.hpp"
#include "Room.hpp"

/**
 * \brief Contains rooms in the location.
 */
class Location : public Entity {
    // Attributes
    private :
        std::vector<Room*> m_rooms;
        /// Name of starting room Must not be empty
        std::string m_startRoom;

        void loadRooms(json js);
    public :
    // Operations
        Location(std::string file);
        virtual ~Location();

        Room* getRoom (std::string name);
        virtual void loadJson(json js);
        virtual void dump(std::ostream& out);
};

#endif
