#include "../include/Session.hpp"

Session::Session(Location* loc) {
    assert(loc != nullptr);

    m_actions.insert(std::make_pair("look", &Session::handleLook));
    m_actions.insert(std::make_pair("take", &Session::handleTake));
    m_actions.insert(std::make_pair("quit", &Session::handleQuit));
}

Session::~Session() { }

bool Session::parseCommand(std::string line) {

}

bool Session::handleLook(std::string target) {

}

bool Session::handleTake(std::string rem) {

}

bool Session::handleHelp(std::string) {

}

bool Session::handleQuit(std::string) {

}

bool Session::handleSave(std::string) {
    
}