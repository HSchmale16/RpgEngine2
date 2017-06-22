#ifndef LOCATION__HPP
#define LOCATION__HPP

#include "Entity.hpp"
#include "Room.hpp"

/**
 * \brief Contains rooms in the location.
 * \author Henry J Schmale
 *
 * Will probably eventually belong to a world object in order to allow world fragements
 */
class Location : public Entity {
    // Attributes
    private :
        std::vector<Room*> m_rooms;
        /// Name of starting room Must not be empty
        std::string m_startRoomString;
        Room* m_startRoom;

        /**\brief loads the room json
         * expects the json to an array of objects
         */
        void loadRooms(json js);
    public :
    // Operations
        Location(std::string file);
        virtual ~Location();

        Room* getStartRoom();
        Room* getRoom (std::string name);
        virtual void loadJson(json js);
        virtual void dump(std::ostream& out);
};

#endif
