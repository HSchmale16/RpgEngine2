#ifndef SESSION__HPP
#define SESSION__HPP

#include "Location.hpp"

class Session {
    // Attributes
    private :
        /// The current room of the given player
        Room * m_currentRoom = nullptr;
        /// The current location
        Location* m_location = nullptr;
        /// The player for this session.
        // TODO: Deal with player shit.
    // Operations
    public :
        Session (Location* loc);
        void parseCommand (std::string line);
    private :
        static void handleTake ();
};

#endif
