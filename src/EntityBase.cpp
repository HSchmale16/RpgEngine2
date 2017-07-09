#include "EntityBase.hpp"
#include "Misc.h"
#include "levenshtein.h"
#include <cassert>
#include <typeinfo>

uint64_t EntityBase::m_nextSerial = 0;

EntityBase::EntityBase(json j) {
    loadJson(j);
    // The name must never be empty
    assert(!m_name.empty());
}

EntityBase::EntityBase(const EntityBase& eb) {
    this->m_lookTexts = eb.m_lookTexts;
    this->m_name = eb.m_name;
    this->m_keywords = eb.m_keywords;
    this->setSerial();
}

EntityBase::EntityBase() {}

// DTOR
EntityBase::~EntityBase() {}

void EntityBase::setSerial() {
    m_serialNumber = ++m_nextSerial;
}

void EntityBase::setName(std::string name) {
    m_keywords.clear();
    splitOnWords(name, m_keywords);
    // modify strings in vector in place by reference
    for(auto& k : m_keywords)
        lower_str(k);
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

void EntityBase::printBasicLookText(std::ostream& out) {
    EntityBase::printLookText(out);
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
    JSON_ATTEMPT_FUNC_OPT(js, "lookTexts", loadLookTexts);
    JSON_ATTEMPT_FUNC_OPT(js, "attributes", loadAttributes);

    this->setSerial();
}

void EntityBase::loadAttributes(json js) {
    if(!js.is_object())
        throw "Attributes are loaded from an object";
    
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
    out << typeid(*this).name() << " " << m_serialNumber << " \"" 
        << this->getName() << '"' << std::endl;
}

uint64_t EntityBase::getSerialNumber() {
    return m_serialNumber;
}

struct CompareBySize {
    bool operator()(const StringVector& a, const StringVector& b) {
        return a.size() < b.size();
    }
};

/** Performs a score calculation to determine how close this entity is to the
 *  target entity description. Just as in golf a lower score is better here.
 *  This is only good for small values of N, as it is O(n^4) with the levenshtein
 *  stuff.
 */
uint64_t EntityBase::getSearchScore(const StringVector& kws) {
    uint64_t sum = 0;
    auto kwSize = std::minmax(kws, m_keywords, CompareBySize());
    for (auto& kw1 : kwSize.second) {
        std::vector<uint64_t> scores;
        for (auto& kw2 : kwSize.first) {
            scores.push_back(levenshtein(kw1.c_str(), kw2.c_str()));
        }
        sum += *std::min_element(scores.begin(), scores.end());
    }
    return sum;
}