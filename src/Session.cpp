#include "../include/Session.hpp"
#include <sstream>

Session::Session(Location* loc, std::ostream& out) : m_outStream(out) {
    assert(loc != nullptr);
    m_location = loc;

    // set current room
    m_currentRoom = m_location->getStartRoom();

    // add valid actions
    m_actions.insert(std::make_pair("look", &Session::handleLook));
    m_actions.insert(std::make_pair("examine", &Session::handleLook));

    m_actions.insert(std::make_pair("take", &Session::handleTake));

    m_actions.insert(std::make_pair("quit", &Session::handleQuit));
    m_actions.insert(std::make_pair("exit", &Session::handleQuit));
    m_actions.insert(std::make_pair("help", &Session::handleHelp));

    m_actions.insert(std::make_pair("save", &Session::handleSave));

    m_currentRoom = m_location->getStartRoom();
}

Session::~Session() { }

bool Session::parseCommand(std::string line) {
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
    for(auto& s : pred)
        std::cerr << s << std::endl;
    Entity* target = nullptr;
    if(pred.empty())
        target = m_currentRoom;
    else if(pred[0] == "location")
        target = m_location;
    else if(pred[0] == "self") {
        // search player inventory
    } else {
        // search around the room
    }
    assert(target != nullptr);
    target->printLookText(m_outStream);
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
