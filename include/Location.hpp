#ifndef LOCATION__HPP
#define LOCATION__HPP

#include "Entity.hpp"

/**
 * \brief Contains rooms in the location.
 */
class Location : public Entity {
    // Attributes
    private :
        std::vector<Room> rooms;
    public :
        /// name of the starting room. May not be empty
        std::string m_startRoom;
    // Operations
        /**
         * \brief loads a location from an xml file.
         * \return bool
         */
        bool loadFromFile ();
        Room* getRoom (std::string name);
};

#endif
