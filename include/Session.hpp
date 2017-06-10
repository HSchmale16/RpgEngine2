#ifndef SESSION__HPP
#define SESSION__HPP

#include "Player.hpp"
#include "Location.hpp"

class Session {
    // Attributes
    private :
        /// The current room of the given player
        Room * m_currentRoom = nullptr;
        /// The current location
        Location* m_location = nullptr;
        /// The player for this session.
        Player m_player;
    // Operations
    public :
        Session (Location* loc);
        void parseCommand (std::string line);
    private :
        static void handleTake ();
};

#endif
