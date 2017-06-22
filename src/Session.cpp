#include "../include/Session.hpp"
#include "../include/Misc.h"
#include <sstream>

Session::Session(Location* loc, std::ostream& out) : m_outStream(out) {
    assert(loc != nullptr);
    m_location = loc;

    // set current room
    m_currentRoom = m_location->getStartRoom();

    // add valid actions
    m_actions.insert(std::make_pair("look", &Session::handleLook));
    m_actions.insert(std::make_pair("examine", &Session::handleLook));

    m_actions.insert(std::make_pair("go", &Session::handleGo));

    m_actions.insert(std::make_pair("take", &Session::handleTake));

    m_actions.insert(std::make_pair("quit", &Session::handleQuit));
    m_actions.insert(std::make_pair("exit", &Session::handleQuit));
    
    m_actions.insert(std::make_pair("help", &Session::handleHelp));

    m_actions.insert(std::make_pair("save", &Session::handleSave));

    m_currentRoom = m_location->getStartRoom();
}

Session::~Session() { }

bool Session::parseCommand(std::string line) {
    lower_str(line);
    std::stringstream sstr(line);
    std::string word, tmp;
    StringVector sv;
    sv.reserve(10);
    sstr >> word;
    while(sstr >> tmp)
        sv.push_back(tmp);
    if(!m_actions.count(word)) {
        m_outStream << "I don't know how to " << word << std::endl;
        return false;
    }
    (this->*m_actions[word])(sv);
    return true;
}

bool Session::quit() const {
    return m_quit;
}

void Session::handleLook(StringVector pred) {
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
            std::cerr << es.first << std::endl;
            target = es.second;
        } else
            return;
    }
    assert(target != nullptr);
    target->printLookText(m_outStream);
}

void Session::handleGo(StringVector rem) {
    Room::DoorScore ds = m_currentRoom->searchDoorByKeywords(rem);
    if(ds.first == 0 || promptYesNo(
            DO_YOU_MEAN(ds.second->getName()), std::cout, std::cin)) {
        assert(ds.second != nullptr);
        m_currentRoom = m_location->getRoom(ds.second->getLinkTo());
        assert(m_currentRoom != nullptr);
    }
}

void Session::handleTake(StringVector rem) {
}

void Session::handleHelp(StringVector) {
}

void Session::handleQuit(StringVector) {
    m_quit = true;
}

void Session::handleSave(StringVector) {
}
