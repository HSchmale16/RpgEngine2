#ifndef DOOR__HPP
#define DOOR__HPP

#include "Entity.hpp"
#include "Player.hpp"

class Door : public Entity {
    // Attributes
    private :
        /// The name of the room it links to
        std::string m_linkTo;
        bool m_isLocked = false;
    // Operations
    public :
        /**
         * \brief attempts to unlock the door using passed players inventory aand stats.
         * \param p (in)
         * \return bool
         */
        bool unlock (const Player& p);
};

#endif
