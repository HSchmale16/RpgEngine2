#include "../include/EntityBase.hpp"
#include "../include/Misc.h"
#include <cassert>
#include <typeinfo>

uint64_t EntityBase::m_nextSerial = 0;

EntityBase::EntityBase(json j) {
    setSerial();
    loadJson(j);
    // The name must never be empty
    assert(!m_name.empty());
    std::cerr << "EB BY JSON: " << getSerialNumber() << std::endl;
}

EntityBase::EntityBase(const EntityBase& eb) {
    this->m_lookTexts = eb.m_lookTexts;
    this->m_name = eb.m_name;
    this->m_keywords = eb.m_keywords;
    this->setSerial();
    std::cerr << "EB_BY_COPY: " << getSerialNumber() << std::endl;
}

EntityBase::EntityBase() {
    std::cerr << "EB_BY_DEF: " << getSerialNumber() << std::endl;
    setSerial();
}

// DTOR
EntityBase::~EntityBase() {}

void EntityBase::setSerial() {
    m_serialNumber = ++m_nextSerial;
}

void EntityBase::setName(std::string name) {
    splitOnWords(name, m_keywords);
    m_name = name;
}

void EntityBase::printLookText(std::ostream& out) {
    if(m_lookTexts.size() == 0)
        out << "Nothing distinct about this.";
    else if(m_lookTexts.size() == 1)
        out << m_lookTexts[0];
    else
        out << *random_element(m_lookTexts.begin(), m_lookTexts.end());
    out << std::endl;
}

std::string EntityBase::getName() const {
    return m_name;
}

void EntityBase::loadJson(json js) {
    if(!js.is_object())
        throw "All entities must be loaded a json object";
    // attempt to load the name
    JSON_ATTEMPT_FUNC_EX(js, "name", this->setName);
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

void EntityBase::dump(std::ostream& out) {
    out << typeid(*this).name() << " " << m_serialNumber << " \"" << this->getName() << '"' 
        << std::endl;
}

uint64_t EntityBase::getSerialNumber() {
    return m_serialNumber;
}