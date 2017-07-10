#include "RequirementsEngine.hpp"
#include "Misc.h"
#include <limits>

const AttributeInteger ATTRIB_INT_MIN = 
    std::numeric_limits<AttributeInteger>::min();

#define RI_TYPE_ATTRIB str2int("attribute")
#define RI_TYPE_ITEM str2int("item")

const std::map<string,int8_t> RequirementsItem::RI_TYPES = {
    { "attribute", RI_TYPE_ATTRIB },
    { "item", RI_TYPE_ITEM }
};

RequirementsItem::RequirementsItem(string type, string name,
                AttributeInteger min, AttributeInteger max)
: m_name(name), m_min(min), m_max(max) {
    setType(type);
}

RequirementsItem::~RequirementsItem() {}

void RequirementsItem::setType(string type) {
    auto it = RI_TYPES.find(type);
    if(it == RI_TYPES.end())
        throw "Invalid Requirements Type";
    m_type = it->second;
}

bool RequirementsItem::testInventory(const Inventory& i) {
    return i.contains(m_name);
}

bool RequirementsItem::testAttribute(const EntityBase& eb) {
    return false;
}

bool RequirementsItem::valid(const EntityBase& eb) {
    if(m_type == RI_TYPE_ITEM)
        return false;
    return testAttribute(eb);
}

bool RequirementsItem::valid(const Inventory& i) {
    if(m_type == RI_TYPE_ATTRIB) {
        return testAttribute(i);
    } else {
        return testInventory(i);
    }
}