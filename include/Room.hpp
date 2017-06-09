#ifndef ROOM__HPP
#define ROOM__HPP

#include "Entity.hpp"

/**
 * \brief Defines a given spot a player can be in and operate on.
 */
class Room : public Entity {
    // Attributes
    private :
        /// contains all of the entities. 
        std::vector<Entity*> m_entities;
        /// contains pointers to the door entities
        std::vector<Door*> m_doors;
        /// pointers to Things in m_entities.
        std::vector<Furniture*> m_things;
    public :
        /// The location with which this Room belongs to.
        Location* m_location = nullptr;
    // Operations
        Room (const Location* loc, json def);
        virtual ~Room ();
};

#endif
