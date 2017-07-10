#include "RequirementsEngine.hpp"
#include "Misc.h"

const std::map<string,int8_t> RequirementsItem::RI_TYPES = {
    {"attribute", 1},
    {"item", 2}
};


RequirementsItem::RequirementsItem(string type, string name, AttributeInteger min,
                 AttributeInteger max)
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