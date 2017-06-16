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
}

Session::~Session() { }

bool Session::parseCommand(std::string line) {
    std::stringstream sstr(line);
    std::string word, rem;
    sstr >> word;
    getline(sstr, rem);
    if(!m_actions.count(word)) {
        m_outStream << "I don't know how to " << word << std::endl;
        return false;
    }
    (this->*m_actions[word])(rem);
    return true;
}

bool Session::quit() const {
    return m_quit;
}

void Session::handleLook(std::string target) {

}

void Session::handleTake(std::string rem) {

}

void Session::handleHelp(std::string) {

}

void Session::handleQuit(std::string) {
    m_quit = true;
}

void Session::handleSave(std::string) {

}