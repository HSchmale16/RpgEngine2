#include "../include/Item.hpp"
#include "../include/Misc.h"
#include "ItemFactory.hpp"

#include <cassert>

Item::Item(json j) : EntityBase(j) {   
    JSON_ATTEMPT_READ_STR(m_type, j, "type");
    if(!ItemFactory::validateType(m_type, m_attributes))
        throw "Item has invalid type";
    
    JSON_ATTEMPT_READ_NUM(m_sellPrice, j, "sellPrice");
    JSON_ATTEMPT_READ_NUM(m_buyPrice, j, "buyPrice");
}

Item::Item(const Item& itm) : EntityBase(itm) {
    this->m_type = itm.m_type;
    this->m_buyPrice = itm.m_buyPrice;
    this->m_sellPrice = itm.m_sellPrice;
}

std::string Item::getType() {
    return m_type;
}

void Item::printDetailed(std::ostream& out) {
    out << getName() << std::endl;
    printLookText(out);
}