#ifndef FURNITURE__HPP
#define FURNITURE__HPP

#include "Inventory.hpp"

class Room;

/**
 * \brief Some interactable item in a room.
 *        
 *        Defined in the furnitures tag of a room.
 */
class Furniture : public Inventory {
    private :
        // room that this belongs to.
        Room* m_room;
    public :
        Furniture (Room* r, json js);
};

#include "Room.hpp"

#endif
