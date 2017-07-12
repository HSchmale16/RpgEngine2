#include "../include/Door.hpp"
#include "../include/Misc.h"
#include <cassert>


Door::Door(Room* r, json js) {
    assert(r != nullptr);
    m_room = r;
    loadJson(js);
}

Door::~Door() {
    if(m_reqs)
        delete m_reqs;
}

void Door::loadJson(json js) {
    Entity::loadJson(js);
    JSON_ATTEMPT_READ_STR(m_linkTo, js, "linkTo");
    assert(!m_linkTo.empty());

    JSON_ATTEMPT_FUNC_OPT(js, "requires", loadRequires);
}

std::string Door::getLinkTo() const {
    return m_linkTo;
}

void Door::loadRequires(json js) {
    m_isUnlocked = false;
    if(m_reqs != nullptr)
        delete m_reqs;
    m_reqs = new RequirementEngine(js);
}

void Door::printRequirements(std::ostream& out) {
    out << "You don't meet the requirements to open this door\n"; 
    m_reqs->printRequirements(out);
}

bool Door::unlock(const Player& p) {
    return (m_isUnlocked) ? true : m_reqs->valid(p);
}