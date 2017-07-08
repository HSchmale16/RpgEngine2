#ifndef ROOM__HPP
#define ROOM__HPP

#include "Entity.hpp"
#include "Door.hpp"
#include "Furniture.hpp"

class Location;
class Session;

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
        std::vector<Furniture*> m_furniture;
        /// The location with which this Room belongs to.
        const Location* m_location = nullptr;

        void loadDoors(json& js);
        void loadFurniture(json& js);
    public :
        Room (const Location* loc, json def);
        virtual ~Room ();

        virtual void loadJson(json js);
        virtual void dump(std::ostream& out);
        virtual void printLookText(std::ostream& out);

        void handleEnter(Session* s);

        typedef std::pair<uint64_t,Entity*> EntityScore;
        /** Searches the entities in the room for a keyword match
         */
        EntityScore searchRoomByKeywords(const StringVector& kws);

        typedef std::pair<uint64_t,Door*> DoorScore;
        /** Searches the doors in the room
         */
        DoorScore searchDoorByKeywords(const StringVector& kws);

        typedef std::pair<uint64_t,Furniture*> FurnitureScore;
        FurnitureScore searchFurnitureByKeywords(const StringVector& kws);
};

#include "Location.hpp"
#include "Session.hpp"

#endif
