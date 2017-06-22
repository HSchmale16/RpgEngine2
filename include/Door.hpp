#ifndef DOOR__HPP
#define DOOR__HPP

#include "Entity.hpp"
#include "Player.hpp"

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

        std::string getLinkTo();

        /**
         * \brief attempts to unlock the door using passed players inventory aand stats.
         * \param p (in)
         * \return true if p can open
         */
        bool unlock (const Player& p);
};

#include "Room.hpp"

#endif
