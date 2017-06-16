#ifndef SESSION__HPP
#define SESSION__HPP

#include "Location.hpp"
#include <map>

class Session {
    // Attributes
    private :
        typedef void (Session::*CommandFunc)(std::string);

        bool m_quit = false;
        std::ostream& m_outStream;
        std::map<std::string,CommandFunc> m_actions;
        /// The current room of the given player
        Room * m_currentRoom = nullptr;
        /// The current location
        Location* m_location = nullptr;
        /// The player for this session.
        // TODO: Deal with player shit.
    // Operations
    public :
        Session (Location* loc, std::ostream& out);
        ~Session();
        bool parseCommand (std::string line);
        bool quit() const;
    private :
        void handleTake (std::string);
        void handleLook (std::string);
        void handleHelp (std::string);
        void handleSave (std::string);
        void handleQuit (std::string);
};

#endif
