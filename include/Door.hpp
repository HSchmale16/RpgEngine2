#ifndef DOOR__HPP
#define DOOR__HPP

#include "Entity.hpp"

class Room;

class Door : public Entity {
    // Attributes
    private :
        /// The name of the room it links to
        std::string m_linkTo;
        bool m_isLocked = false;

        /// Parent
        Room* m_room;
    protected :
        virtual void loadJson(json js);
    public :
        Door(Room* r, json js);

        /**
         * \brief attempts to unlock the door using passed players inventory aand stats.
         * \param p (in)
         * \return bool
         */
        //bool unlock (const Player& p);
};

#include "Room.hpp"

#endif
