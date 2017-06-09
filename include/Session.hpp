#ifndef SESSION__HPP
#define SESSION__HPP

#include "Player.hpp"

class Session {
    // Attributes
    private :
        /// The current room of the given player
        Room * m_currentRoom = nullptr;
        /// The player for this session.
        Player m_player;
    // Operations
    public :
        Session ();
        ~Session ();
        void parseCommand (std::string line);
    private :
        static void handleTake ();
};

#endif
