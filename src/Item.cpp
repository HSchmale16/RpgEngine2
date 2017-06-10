#include "../include/Item.hpp"
#include "../include/Misc.h"
#include <cassert>

Item::Item(json j, ItemFactory* factory) : EntityBase(j) {
    assert(factory != nullptr);
    m_factory = factory;
    
    JSON_ATTEMPT_READ_STR(m_type, j, "type");
     if(!m_factory->validateType(m_type))
        throw "Item has invalid type";
    
    JSON_ATTEMPT_READ_NUM(m_sellPrice, j, "sellPrice");
    JSON_ATTEMPT_READ_NUM(m_buyPrice, j, "buyPrice");
}

std::string Item::getType() {
    return m_type;
}