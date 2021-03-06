#ifndef SESSION__HPP
#define SESSION__HPP

#include "Location.hpp"
#include "Player.hpp"
#include <map>

class Session {
    // Attributes
    private :
        typedef void (Session::*CommandFunc)(const StringVector&);

        bool m_quit = false;
        std::ostream& m_outStream;
        std::map<std::string,CommandFunc> m_actions;
        /// The current room of the given player
        Room * m_currentRoom = nullptr;
        /// The current location
        Location* m_location = nullptr;
        /// The player for this session.
        Player m_player;
        // TODO: Deal with player shit.
    // Operations
    public :
        Session (Location* loc, std::ostream& out);
        ~Session();
        bool parseCommand (std::string line);
        bool quit () const;
    private :
        // HANDLERS
        void handleTake (const StringVector&);
        void handleLook (const StringVector&);
        void handleHelp (const StringVector&);
        void handleSave (const StringVector&);
        void handleQuit (const StringVector&);
        void handleGo   (const StringVector&);
        void handleInventory (const StringVector&);

        // HELPERS
        void setConsolePrint();
        void resetConsoleDefaults();

        template<typename T>
        bool matchOrPrompt(const std::pair<uint64_t,T*>& x);
};

#endif
