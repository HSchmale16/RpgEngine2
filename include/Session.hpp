#ifndef SESSION__HPP
#define SESSION__HPP

#include "Location.hpp"
#include <map>

class Session {
    // Attributes
    private :
        typedef bool (Session::*CommandFunc)(std::string);

        std::map<std::string,CommandFunc> m_actions;
        /// The current room of the given player
        Room * m_currentRoom = nullptr;
        /// The current location
        Location* m_location = nullptr;
        /// The player for this session.
        // TODO: Deal with player shit.
    // Operations
    public :
        Session (Location* loc);
        ~Session();
        bool parseCommand (std::string line);
    private :
        bool handleTake (std::string);
        bool handleLook (std::string);
        bool handleHelp (std::string);
        bool handleSave (std::string);
        bool handleQuit (std::string);
};

#endif
