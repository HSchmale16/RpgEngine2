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

std::string Door::getLinkTo() {
    return m_linkTo;
}

void Door::loadRequires(json js) {
    if(m_reqs != nullptr)
        delete m_reqs;
    m_reqs = new RequirementEngine(js);
}

bool Door::unlock(const Player& p) {
    if(m_isUnlocked)
        return true;
    // TODO: Add requirements checking
    return false;
}