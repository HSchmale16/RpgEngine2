/** Implementation of a basic Requirements Engine
 *  @author Henry J Schmale
 */

#include "RequirementEngine.hpp"
#include "Misc.h"
#include <limits>
#include <sstream>

// the default value for type attributes
const AttributeInteger ATTRIB_INT_MIN = 
    std::numeric_limits<AttributeInteger>::min();

#define RI_TYPE_ATTRIB str2int("attribute")
#define RI_TYPE_ITEM str2int("item")

const std::map<string,uint32_t> RequirementItem::RI_TYPES = {
    { "attribute", RI_TYPE_ATTRIB },
    { "item", RI_TYPE_ITEM }
};

/////////////////////////////////////////////////////////////////
// Requirement Group

RequirementItem::RequirementItem(string type, string name)
    : RequirementItem(type, name, ATTRIB_INT_MIN, ATTRIB_INT_MIN) {}

RequirementItem::RequirementItem(string type, string name,
                AttributeInteger min, AttributeInteger max)
: m_name(name), m_min(min), m_max(max) {
    assert(!m_name.empty());
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
    // same test that attrib exists
    if(m_min == m_max)
        return i > ATTRIB_INT_MIN;
    // max < min then only min matters
    if(m_min > m_max)
        return i >= m_min;
    // otherwise test inclusive
    return between_inc(i, m_min, m_max);
}

bool RequirementItem::valid(const EntityBase& eb) {
    if(m_type == RI_TYPE_ITEM) {
        try {
            const Inventory& inv = dynamic_cast<const Inventory&>(eb);
            return testInventory(inv);
        } catch(const std::bad_cast& e) {
            return false;
        }
    }
    return testAttribute(eb);
}

string RequirementItem::toString() {
    std::stringstream sstr;
    sstr << "have (" <<
        ((m_type == RI_TYPE_ITEM) ? "item)" : "attrib)") <<
        m_name;
    if(m_type == RI_TYPE_ATTRIB) {
        if(m_min < m_max)
            sstr << " between " << m_min << " and " << m_max;
        else if(m_min > m_max)
            sstr << " of at least " << m_min;
    }
    return sstr.str();
}

/////////////////////////////////////////////////////////////////
// Requirement Group

RequirementEngine::RequirementGroup::RequirementGroup(json js) {
    if(js.is_object()) {
        addRequirementItem(js);
    } else if(js.is_array()) {
        for(auto rg : js)
            addRequirementItem(rg);
    } else {
        throw "RequirementGroups must be either an object or an array";
    }
}

RequirementEngine::RequirementGroup::~RequirementGroup() {}

void RequirementEngine::RequirementGroup::addRequirementItem(json js) {
    assert(js.is_object());

    string type, name;
    JSON_ATTEMPT_READ_STR(type, js, "requirementType");
    JSON_ATTEMPT_READ_STR(name, js, "name");

    AttributeInteger min, max;
    JSON_READ_NUM_DEF(min, js, "min", ATTRIB_INT_MIN);
    JSON_READ_NUM_DEF(max, js, "max", ATTRIB_INT_MIN);

    m_requirements.push_back(RequirementItem(type, name, min, max));
}

bool RequirementEngine::RequirementGroup::valid(const EntityBase& eb) {
    for(auto& req : m_requirements) {
        if(!req.valid(eb))
            return false;
    }
    return true;
}

void RequirementEngine::RequirementGroup::print(std::ostream& out) {
    auto finalIter = --m_requirements.end();
    for(auto it = m_requirements.begin(); it != m_requirements.end(); ++it) {
        string msg = it->toString();
        out << msg;
        if(it != finalIter) {
            out << " AND\n";
        }
    }
}

/////////////////////////////////////////////////////////////////
// Requirement Engine

RequirementEngine::RequirementEngine(json js) {
    if(js.is_object() || js.is_array())
        addGroup(js);
    else
        throw "RequirementEngine must be array or object";
}

RequirementEngine::~RequirementEngine() {}

void RequirementEngine::addGroup(json js) {
    if(js.is_object()) {
        m_groups.push_back(RequirementGroup(js));
    } else if(js.is_array()) {
        for(auto rg : js)
            m_groups.push_back(RequirementGroup(rg));
    }
}

bool RequirementEngine::valid(const EntityBase& eb) {
    for(auto& reqGroup : m_groups) {
        if(reqGroup.valid(eb)) {
            return true;
        }
    }
    return false;
}

void RequirementEngine::printRequirements(std::ostream& out) {
    auto finalIter = --m_groups.end();
    for(auto it = m_groups.begin(); it != m_groups.end(); ++it) {
        it->print(out);
        if(it != finalIter)
            out << "\nOR\n";
    }
    out << std::endl;
}