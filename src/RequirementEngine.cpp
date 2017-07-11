#include "RequirementEngine.hpp"
#include "Misc.h"
#include <limits>

const AttributeInteger ATTRIB_INT_MIN = 
    std::numeric_limits<AttributeInteger>::min();

#define RI_TYPE_ATTRIB str2int("attribute")
#define RI_TYPE_ITEM str2int("item")

const std::map<string,uint32_t> RequirementItem::RI_TYPES = {
    { "attribute", RI_TYPE_ATTRIB },
    { "item", RI_TYPE_ITEM }
};

RequirementItem::RequirementItem(string type, string name)
    : RequirementItem(type, name, ATTRIB_INT_MIN, ATTRIB_INT_MIN) {}

RequirementItem::RequirementItem(string type, string name,
                AttributeInteger min, AttributeInteger max)
: m_name(name), m_min(min), m_max(max) {
    setType(type);
}

RequirementItem::~RequirementItem() {}

void RequirementItem::setType(string type) {
    auto it = RI_TYPES.find(type);
    if(it == RI_TYPES.end())
        throw "Invalid Requirement Type";
    m_type = it->second;
}

bool RequirementItem::testInventory(const Inventory& i) {
    return i.contains(m_name);
}

bool RequirementItem::testAttribute(const EntityBase& eb) {
    AttributeInteger i = eb.getAttribute(m_name, ATTRIB_INT_MIN);
    if(m_min == m_max)
        return i > ATTRIB_INT_MIN;
    if(m_max < m_min)
        return i > m_min;
    return between_inc(i, m_min, m_max);
}

bool RequirementItem::valid(const EntityBase& eb) {
    if(m_type == RI_TYPE_ITEM)
        return false;
    return testAttribute(eb);
}

bool RequirementItem::valid(const Inventory& i) {
    if(m_type == RI_TYPE_ATTRIB) {
        return testAttribute(i);
    } else {
        return testInventory(i);
    }
}

/////////////////////////////////////////////////////////////////
// Requirement Group

RequirementEngine::RequirementGroup::RequirementGroup(json js) {

}

RequirementEngine::RequirementGroup::~RequirementGroup() {

}


bool RequirementEngine::RequirementGroup::valid(const Inventory& i) {
    return false;
}

/////////////////////////////////////////////////////////////////
// Requirement Engine