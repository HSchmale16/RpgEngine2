#ifndef ROOM__HPP
#define ROOM__HPP

#include "Entity.hpp"
#include "Door.hpp"
#include "Furniture.hpp"

class Location;

/**
 * \brief Defines a given spot a player can be in and operate on.
 */
class Room : public Entity {
    // Attributes
    private :
        /// contains all of the entities. 
        std::vector<EntityBase*> m_entities;
        /// contains pointers to the door entities
        std::vector<Door*> m_doors;
        /// pointers to Things in m_entities.
        std::vector<Furniture*> m_furniture;
        /// The location with which this Room belongs to.
        const Location* m_location = nullptr;

        void loadDoors(json& js);
        void loadFurniture(json& js);
    public :
        Room (const Location* loc, json def);
        virtual ~Room ();

        EntityBase* searchTarget(std::string target);
        virtual bool loadJson(json js);
        virtual void dump(std::ostream& out);
};

#include "Location.hpp"

#endif
