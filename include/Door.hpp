#ifndef DOOR__HPP
#define DOOR__HPP

#include "Entity.hpp"
#include "Player.hpp"
#include "RequirementEngine.hpp"

class Room;

class Door : public Entity {
    // Attributes
    private :
        /// The name of the room it links to
        std::string m_linkTo;
        bool m_isUnlocked = true;
        RequirementEngine* m_reqs = nullptr;

        /// Parent
        Room* m_room;
    protected :
        virtual void loadJson (json js);
        void loadRequires(json js);
    public :
        Door(Room* r, json js);
        virtual ~Door();

        std::string getLinkTo () const;
        void printRequirements(std::ostream& out);
        /**
         * \brief attempts to unlock the door using passed players inventory aand stats.
         * \param p (in)
         * \return true if p can open
         */
        bool unlock (const Player& p);

        virtual void printLookText (std::ostream& out);
};

#include "Room.hpp"

#endif
