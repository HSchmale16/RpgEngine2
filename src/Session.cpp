#include "../include/Session.hpp"
#include "../include/Misc.h"
#include "../lib/rang.hpp"
#include <exception>
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

template<typename T>
bool Session::matchOrPrompt(const std::pair<uint64_t,T*>& x) {
    static_assert(std::is_base_of<EntityBase, T>::value);
    assert(x.second != nullptr);
    return x.first == 0 ||
        promptYesNo(
            DO_YOU_MEAN(x.second->getName()),
            m_outStream, std::cin);
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
        if(matchOrPrompt(es)) {
            target = es.second;
        } else
            return;
    }
    assert(target != nullptr);
    target->printLookText(m_outStream);
}

void Session::handleGo(const StringVector& rem) {
    if(rem.empty()) {
        m_outStream << rang::fg::red << "Go Where?" << rang::fg::reset << std::endl;
        return;
    }
    Room::DoorScore ds = m_currentRoom->searchDoorByKeywords(rem);
    if(matchOrPrompt(ds)) {
        m_currentRoom = m_location->getRoom(ds.second->getLinkTo());
        assert(m_currentRoom != nullptr);

        m_currentRoom->handleEnter(this);
    }
}

StringVectorPair splitOnWord(const StringVector& v, std::string word) {
    auto it = std::find(v.begin(), v.end(), word);
    if(it == v.end())
        throw "missing clause";
    return std::make_pair(
        StringVector(v.begin(), it),
        StringVector(std::next(it), v.end())
    );
}

void Session::handleTake(const StringVector& rem) {
    StringVectorPair sp;
    try {
        sp = splitOnWord(rem, "from");
    } catch(const char* ex) {
        m_outStream << rang::fg::red << rang::style::bold
            << "missing from clause in take: take <item> from <furniture>"
            << std::endl;
        resetConsoleDefaults();
        return;
    }
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