#include "../include/Session.hpp"
#include "../include/Misc.h"
#include "../lib/rang.hpp"
#include <sstream>

/* Builds a do you mean string. As macro because it should be lined
 */
#define DO_YOU_MEAN(x) "Do you mean \"" + x + "\"? (y/n) "


Session::Session(Location* loc, std::ostream& out) : m_outStream(out) {
    assert(loc != nullptr);
    m_location = loc;

    // set current room
    m_currentRoom = m_location->getStartRoom();

    // add valid actions
    m_actions.insert(std::make_pair("look",     &Session::handleLook));
    m_actions.insert(std::make_pair("examine",  &Session::handleLook));
    m_actions.insert(std::make_pair("go",       &Session::handleGo));
    m_actions.insert(std::make_pair("take",     &Session::handleTake));
    m_actions.insert(std::make_pair("quit",     &Session::handleQuit));
    m_actions.insert(std::make_pair("exit",     &Session::handleQuit));
    m_actions.insert(std::make_pair("help",     &Session::handleHelp));
    m_actions.insert(std::make_pair("save",     &Session::handleSave));

    // reset the client console
    resetConsoleDefaults();
}

Session::~Session() { }

bool Session::parseCommand(std::string line) {
    lower_str(line);
    std::stringstream sstr(line);
    std::string command, tmp;
    StringVector sv;
    sv.reserve(10);
    sstr >> command;
    while(sstr >> tmp)
        sv.push_back(tmp);

    if(!m_actions.count(command)) {
        m_outStream << "I don't know how to " << command << std::endl;
        return false;
    }

    setConsolePrint();
    (this->*m_actions[command])(sv);
    resetConsoleDefaults();
    return true;
}

bool Session::quit() const {
    return m_quit;
}

void Session::handleLook(const StringVector& pred) {
    Entity* target = nullptr;
    if(pred.empty())
        target = m_currentRoom;
    else if(pred[0] == "location")
        target = m_location;
    else if(pred[0] == "self") {
        // search player inventory
    } else {
        // search around the room
        Room::EntityScore es = m_currentRoom->searchRoomByKeywords(pred);
        if(es.first == 0 ||
                promptYesNo(DO_YOU_MEAN(es.second->getName()), std::cout,
                std::cin)) {
            target = es.second;
        } else
            return;
    }
    assert(target != nullptr);
    target->printLookText(m_outStream);
}

void Session::handleGo(const StringVector& rem) {
    Room::DoorScore ds = m_currentRoom->searchDoorByKeywords(rem);
    if(ds.first == 0 || promptYesNo(
            DO_YOU_MEAN(ds.second->getName()), std::cout, std::cin)) {
        assert(ds.second != nullptr);

        m_currentRoom = m_location->getRoom(ds.second->getLinkTo());
        m_currentRoom->handleEnter(this);

        assert(m_currentRoom != nullptr);
    }
}

void Session::handleTake(const StringVector& rem) {
}

void Session::handleHelp(const StringVector&) {
}

void Session::handleQuit(const StringVector&) {
    m_quit = true;
}

void Session::handleSave(const StringVector&) {
}

// HELPERS
void Session::setConsolePrint() {
    using namespace rang;
    m_outStream << style::reset << fg::reset << bg::reset;
}

void Session::resetConsoleDefaults() {
    using namespace rang;
    m_outStream << style::reset << fg::reset << bg::reset;
}