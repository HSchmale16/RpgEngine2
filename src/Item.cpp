#include "../include/Item.hpp"
#include "../include/Misc.h"
#include <cassert>

Item::Item(json j, ItemFactory* factory) : EntityBase(j) {   
    JSON_ATTEMPT_READ_STR(m_type, j, "type");
     if(!factory->validateType(m_type))
        throw "Item has invalid type";
    
    JSON_ATTEMPT_READ_NUM(m_sellPrice, j, "sellPrice");
    JSON_ATTEMPT_READ_NUM(m_buyPrice, j, "buyPrice");
}

Item::Item(const Item& itm) : EntityBase(itm) {
    this->m_type = itm.m_type;
    this->m_attributes = itm.m_attributes;
    this->m_buyPrice = itm.m_buyPrice;
    this->m_sellPrice = itm.m_sellPrice;
}

std::string Item::getType() {
    return m_type;
}