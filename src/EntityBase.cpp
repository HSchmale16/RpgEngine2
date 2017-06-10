#include "../include/EntityBase.hpp"
#include "../include/Misc.h"

EntityBase::EntityBase(json j) {
    loadJson(j);
}

EntityBase::EntityBase() { }

void EntityBase::printLookText(std::ostream& out) {
    if(m_lookTexts.size() == 0)
        out << "Nothing distinct about this.";
    else if(m_lookTexts.size() == 1)
        out << m_lookTexts[0];
    else
        out << *random_element(m_lookTexts.begin(), m_lookTexts.end());
    out << std::endl;
}

std::string EntityBase::getName() {
    return m_name;
}

bool EntityBase::loadJson(json js) {
    if(!js.is_object())
        throw "All entities must be loaded a json object";
    // attempt to load the name
    JSON_ATTEMPT_READ_STR(m_name, js, "name");
    // load the look texts
    if(js.find("lookTexts") != js.end())
        loadLookTexts(js["lookTexts"]);
}

void EntityBase::loadLookTexts(json ltexts) {
    for(const auto& e : ltexts) {
        if(e.is_string())
            m_lookTexts.push_back(e);
        else
            throw "All look texts must be a string";
    }        
}